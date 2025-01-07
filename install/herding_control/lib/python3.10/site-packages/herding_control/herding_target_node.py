import math
import numpy as np
import rclpy # type: ignore
from geometry_msgs.msg import PoseStamped, Twist # type: ignore
from rclpy.node import Node # type: ignore
from tf_transformations import euler_from_quaternion # type: ignore


class PubNode(Node):
    def __init__(self):
        super().__init__('herding_target_node') #node name, must match filename

        self.declare_parameter('dt', 0.01)
        self.declare_parameter('GAIN', 10)
        self.declare_parameter('MAX_SPEED_MS', 0.2)
        self.declare_parameter('SIGHT_RANGE_METERS', 3.0)
        self.declare_parameter('LEVY_WALK_PARAM', 12.0)
        self.declare_parameter('BIG_BAD_WOLF', "dummy")
        
        self.dt = self.get_parameter('dt').value
        self.GAIN = self.get_parameter('GAIN').value
        self.MAX_VEL = self.get_parameter('MAX_SPEED_MS').value
        self.SIGHT_RANGE = self.get_parameter('SIGHT_RANGE_METERS').value
        self.LEVY_WALK_PARAM = float(self.get_parameter('LEVY_WALK_PARAM').value)
        self.BIG_BAD_WOLF = self.get_parameter('BIG_BAD_WOLF').value

        #publish velocity (linear x and anglular z)
        self.target_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.target_holonomic_vel_pub = self.create_publisher(Twist, 'holonomic_cmd_vel', 10)

        #subscribe to  my real-world robot position
        self.target_pos_sub = self.create_subscription(PoseStamped, 'pose', self.pos_callback, 10)
        #subscribe to agent real-world robot position
        self.agent_pos_sub = self.create_subscription(PoseStamped, '/' + self.BIG_BAD_WOLF + '/pose', self.agent_pos_callback, 10)

        #create timer using dt from parameters
        self.timer = self.create_timer(self.dt, self.update_motion)

        #variables for checks to make sure values are valid. bad when gps drops out otherwise
        self.real_pos_target = None
        self.real_pos_agent = None

        #set intitial vel to 0
        self.target_vel_hol = np.array([0.0, 0.0])


    def pos_callback(self, msg): #get real positions and update sim. This runs whenever a postion is revieved to update our position array
        self.real_pos_target = np.array([msg.pose.position.x, msg.pose.position.y])
        self.target_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        #self.get_logger().info(f'Position:  [{msg.pose.position.x}, {msg.pose.position.y}]')


    def agent_pos_callback(self, msg):
        self.real_pos_agent = np.array([msg.pose.position.x, msg.pose.position.y])
        self.agent_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        #self.get_logger().info(f'Agent position: [{msg.pose.position.x}, {msg.pose.position.y}]')


    def update_motion(self):
        if self.real_pos_target is None:
            #self.get_logger().info("My (Target) Position is missing. Skipping update.")
            return
        if self.real_pos_agent is None:
            #self.get_logger().info("Agent position is missing.")
            self.target_vel_hol = self.levy_walk(self.LEVY_WALK_PARAM)

        else:
            #find displacement between them
            self.dist_from_target = np.linalg.norm(self.real_pos_target - self.real_pos_agent)

            #random walk check
            if self.dist_from_target < self.SIGHT_RANGE:
                self.target_vel_hol = self.fearFunction(self.real_pos_target, self.real_pos_agent, self.dist_from_target)
            else:
                self.target_vel_hol = self.levy_walk(self.LEVY_WALK_PARAM)
        
        #publish velocities
        _, _, self.target_yaw = euler_from_quaternion(self.target_heading_list)
        
        self.convert_and_publish_velocity(self.target_vel_pub, self.target_vel_hol, self.MAX_VEL, self.target_yaw)
        self.pub_delta_vel(self.target_holonomic_vel_pub, self.target_vel_hol, self.MAX_VEL)
        
        self.real_pos_target = None #zero out variables to check for when the robots are off
        self.real_pos_agent = None


    def levy_walk(self, alpha):
        step_length = np.random.pareto(alpha) #generate a step
        angle = np.random.uniform(0, 2 * np.pi)
        dx = step_length * np.cos(angle) #calculate hollonomic values
        dy = step_length * np.sin(angle)
        return np.array([dx, dy])


    def fearFunction(self, target, agent, distance):
        opposite_vec = target - agent
        fear_factor = 1.0
        t_dot = fear_factor * opposite_vec * self.dt
        return t_dot


    def convert_and_publish_velocity(self, publisher, velocity_hol, v_max, yaw): #publish the vel commands as a twist message
        #this converts the [dx,dy] vel vector to a linear component and angular component
        v_lin = np.linalg.norm(velocity_hol) #take the norm for the linear component
        atan2_angle = np.arctan2(velocity_hol[1], velocity_hol[0]) #fix angle calculation
        
        if math.isnan(v_lin) or math.isnan(atan2_angle): #check if our values are divide by 0 errors and skip update
            return

        v_ang = atan2_angle - yaw #subtract current heading

        if v_ang > 0: #wrap angle so it stays between -pi to pi
            while v_ang > np.pi:
                v_ang -= 2*np.pi
        else:
            while v_ang < -np.pi:
                v_ang += 2*np.pi

        #v_ang = 0.8*v_ang  # Remove negative sign, test to see if it moves in the correct direction

        if v_lin > v_max: #cap linear speed so we don't tell the dogs to run too fast
            v_lin = v_max
        
        twist_msg = Twist() #create twist message to pack data into to publish
        twist_msg.linear.x = v_lin
        twist_msg.angular.z = v_ang

        publisher.publish(twist_msg) #publish twist message
        return


    def pub_delta_vel(self, publisher, velocity, max): #this publishes velocity in a format that the matplotlib sim likes
        twist_msg = Twist()
        dx = velocity[0]
        dy = velocity[1]
        if dx > max: #cap linear speed so we don't tell the dogs to run too fast
            dx = max
        if dy > max:
            dy = max
        twist_msg.linear.x = dx
        twist_msg.linear.y = dy
        twist_msg.angular.z = 0.0
        publisher.publish(twist_msg)
        #self.get_logger().info(f'Publishing Twist: linear x: {twist_msg.linear.x}, y: {twist_msg.linear.y}')


#ros2 boilerplate, make sure pub_node matches the main function above
def main(args=None):
    rclpy.init(args=args)
    pub_node = PubNode()
    rclpy.spin(pub_node)
    pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
