import math
import numpy as np
import rclpy # type: ignore
from geometry_msgs.msg import PoseStamped, Twist # type: ignore
from rclpy.node import Node # type: ignore
from tf_transformations import euler_from_quaternion # type: ignore


class PubNode(Node): #this is the main method of the function where all the ros publishers/subscribers are created
    def __init__(self):
        super().__init__('fear_and_random_walk_node') #node name, must match filename

        #create parameters for variables
        self.declare_parameter('dt', 0.01)
        self.declare_parameter('GAIN', 10)
        #self.declare_parameter('goal_pos', [1, 1, 1])
        #self.declare_parameter('edge_set', [(1,2), (2,1), (1,3), (3,1), (2,3), (3,2)])

        #get parameters
        self.dt = self.get_parameter('dt').value
        self.GAIN = self.get_parameter('GAIN').value

        #Robot namespaces
        '''AP robot names:
            /j100_0572
            /a200_0706 
            /a200_0708
            /go1_0153  #small dog with blue parts
            /go1_0154
            /go1_0155
        no trailing '/' as it is concatenated in each pub/sub creation line below already'''
        self.agent_name  = MAKE_SURE_THIS_IS_CORRECT; 'go1_0153'
        self.target_name = GET_CURRENT_VEHICLE; 'go1_0154'

        #publish velocity (linear x and anglular z)
        self.target_vel_pub = self.create_publisher(Twist, self.target_name + '/cmd_vel', 10)

        #subscribe to real-world robot position
        self.agent_pos_sub = self.create_subscription(PoseStamped, self.agent_name + '/pose', self.agent_pos_callback, 10)
        self.target_pos_sub = self.create_subscription(PoseStamped, self.target_name + '/pose', self.target_pos_callback, 10)

        #create timer using dt from parameters
        self.timer = self.create_timer(self.dt, self.update_motion)

        #checks to make sure values are valid
        self.real_pos_agent = None
        self.real_pos_target = None

        #set initial velocity to zero
        self.agent_vel = 0.0
        self.target_vel = 0.0

        #control max linear velocity, keeps things under control
        self.MAX_VEL = 0.2 #m/s 
        #control how far away random walk is disabled for the fear behaviour
        self.SIGHT_RANGE = 5.0 #m


    def agent_pos_callback(self, msg): #get real positions and update sim. This runs whenever a postion is revieved to update our position array
        self.real_pos_agent = np.array([msg.pose.position.x, msg.pose.position.y])
        self.agent_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        self.get_logger().info(f'agent position:  [{msg.pose.position.x}, {msg.pose.position.y}]')

    def target_pos_callback(self, msg):
        self.real_pos_target = np.array([msg.pose.position.x, msg.pose.position.y])
        self.target_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        self.get_logger().info(f'Target position: [{msg.pose.position.x}, {msg.pose.position.y}]')

    def update_motion(self):
        if self.real_pos_agent is None:
            self.get_logger().info("Agent position is missing. Skipping update.")
            self.no_repeat = True
        
        if self.real_pos_target is None:
            self.get_logger().info("Target position is missing. Skipping update.")
            self.no_repeat = True

        if self.no_repeat: return

        #find displacement between them
        self.dist_from_target = np.linalg.norm(self.real_pos_target - self.real_pos_target)

        #random walk check
        if self.dist_from_target < self.SIGHT_RANGE:
            #call random walk funciton
            self.target_vel_hol = self.levy_walk()
        else:
            #pass positions to gain function
            self.target_vel_hol = self.fearFunction(self.real_pos_target, self.real_pos_agent, self.dist_from_target)

        #BOTH should output a self.target_vel_hol
        self.get_logger().info(f'Target vel_hol: {self.target_vel_hol}')

        #publish velocities
        _, _, self.target_yaw = euler_from_quaternion(self.target_heading_list)
        self.target_vel = self.convert_and_publish_velocity(self.target_vel_pub, self.target_vel_hol, self.MAX_VEL, self.target_yaw)

        self.get_logger().info(f'\n') #empty comment to seperate steps in console window
        self.real_pos_agent = None #zero out variables to check for when the robots are off
        self.real_pos_target = None

    def levy_walk(alpha=6.9):
        step_length = np.random.pareto(alpha) #generate a step
        angle = np.random.uniform(0, 2 * np.pi)
        dx = step_length * np.cos(angle) #calculate hollonomic values
        dy = step_length * np.sin(angle)
        return np.array([dx, dy])
    
    def fearFunction(target, agent, distance):
        opposite_vec = target - agent
        fear_factor = np.exp(distance)
        t_dot = fear_factor * opposite_vec
        return t_dot

    def convert_and_publish_velocity(self, publisher, velocity_hol, v_max, yaw): #publish the vel commands as a twist message
        #this converts the [dx,dy] vel vector to a linear component and angular component
        v_lin = np.linalg.norm(velocity_hol) #take the norm for the linear component
        atan2_angle = np.arctan2((velocity_hol[1]/v_lin), (velocity_hol[0]/v_lin)) #atan2 for the amount to turn from x axis. this is not the correct heading, do not directly publish this value or things will not work.
        
        if math.isnan(v_lin) or math.isnan(atan2_angle): #check if our values are divide by 0 errors and skip update
            return

        v_ang = atan2_angle - yaw #subtract current heading

        if v_ang > 0: #wrap angle so it stays between -pi to pi
            while v_ang > np.pi:
                v_ang -= 2*np.pi
        else:
            while v_ang < -np.pi:
                v_ang += 2*np.pi

        v_ang = -0.8*v_ang #coefficient is a gain so we dont do 360deg rotations instantly. negative worked best but i need to investigate further.

        if v_lin > v_max: #cap linear speed so we don't tell the dogs to run too fast
            v_lin = v_max
        
        self.get_logger().info(f'Publishing Vel Hol: {velocity_hol}')
        self.get_logger().info(f'Publishing lin,ang: {v_lin}, {v_ang}')

        twist_msg = Twist() #create twist message to pack data into to publish
        twist_msg.linear.x = v_lin
        twist_msg.angular.z = v_ang

        publisher.publish(twist_msg) #publish twist message
        return v_lin #return velocity so it can be used to keep the robot moving when position has not been updated. not implemented yet.
    
    def pub_lin_vel(self, publisher, velocity): #this is supposed to publish a linear velocity only as a twist message. it will be used to make the robots keep moving when the gps does not send the position and the simulation cannot be run since it depends on n current gps values. not implemnted yet.
        self.get_logger().info(f'Publishing Last linear vel: {velocity}')
        twist_msg = Twist()
        twist_msg.linear.x = velocity
        publisher.publish(twist_msg)


#ros2 boilerplate, make sure pub_node matches the main function above
def main(args=None):
    rclpy.init(args=args)
    pub_node = PubNode()
    rclpy.spin(pub_node)
    pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
