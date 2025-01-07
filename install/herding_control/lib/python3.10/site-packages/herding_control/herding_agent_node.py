import math
import numpy as np
import rclpy # type: ignore
from sensor_msgs.msg import Joy  # type: ignore
from geometry_msgs.msg import PoseStamped, Twist # type: ignore
from rclpy.node import Node # type: ignore
from tf_transformations import euler_from_quaternion # type: ignore


class PubNode(Node):
    def __init__(self):
        super().__init__('herding_target_node') #node name, must match filename

        self.declare_parameter('dt', 0.01)
        self.declare_parameter('MAX_SPEED_MS', 0.2)
        self.declare_parameter('TARGET_NAME', "dummy")
        self.declare_parameter('GOAL_LOCATION_x', 0.0)
        self.declare_parameter('GOAL_LOCATION_y', 0.0)
        self.declare_parameter('GAIN_LIST', [1.0, 2.0, 3.0]) #g, k1, k2
        self.declare_parameter('GOAL_RADIUS', 1.0)


        self.dt = self.get_parameter('dt').value
        self.MAX_VEL = self.get_parameter('MAX_SPEED_MS').value
        self.TARGET_NAME = self.get_parameter('TARGET_NAME').value
        self.GOAL_LOCATION_x = self.get_parameter('GOAL_LOCATION_x').value
        self.GOAL_LOCATION_y = self.get_parameter('GOAL_LOCATION_y').value
        self.GAIN_LIST = self.get_parameter('GAIN_LIST').value
        self.GOAL_RADIUS = self.get_parameter('GOAL_RADIUS').value
        
        #publish velocity (linear x and anglular z)
        self.agent_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.agent_holonomic_vel_pub = self.create_publisher(Twist, 'holonomic_cmd_vel', 10)

        self.agent_pos_sub = self.create_subscription(PoseStamped, 'pose', self.agent_pos_callback, 10)
        self.target_pos_sub = self.create_subscription(PoseStamped, '/' + self.TARGET_NAME + '/pose', self.target_pos_callback, 10)
        
        # subscribe to joystick input
        self.joy_sub = self.create_subscription(Joy, '/joy', self.joy_callback, 10)

        #create timer using dt from parameters
        self.timer = self.create_timer(self.dt, self.update_motion)

        #variables for checks to make sure values are valid. bad when gps drops out otherwise
        self.real_pos_agent = None

        #set intitial vel to 0
        self.agent_vel_hol = np.array([0.0, 0.0])

        self.joy_pressed = False  # Track if the joystick is pressed


    def agent_pos_callback(self, msg):
        self.real_pos_agent = np.array([msg.pose.position.x, msg.pose.position.y])
        self.agent_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        #self.get_logger().info(f'Agent position: [{msg.pose.position.x}, {msg.pose.position.y}]')


    def target_pos_callback(self, msg): #get real positions and update sim. This runs whenever a postion is revieved to update our position array
        self.real_pos_target = np.array([msg.pose.position.x, msg.pose.position.y])
        self.target_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        #self.get_logger().info(f'Position:  [{msg.pose.position.x}, {msg.pose.position.y}]')


    def joy_callback(self, msg):
        # Check joystick axes to determine if it is pressed
        if abs(msg.axes[0]) > 0.1 or abs(msg.axes[1]) > 0.1:
            self.joy_pressed = True
            self.agent_vel_hol[0] = -msg.axes[0] * self.MAX_VEL #horzontal left stick, inverted correctly, controls x_pos
            self.agent_vel_hol[1] = msg.axes[1] * self.MAX_VEL #vertical left stick, controls y_pos
        else:
            self.agent_vel_hol = np.array([0.0, 0.0])


    def update_motion(self):
        if self.real_pos_agent is None:
            self.get_logger().info("Position is missing. Skipping update.")
            return
        
        if self.real_pos_target is None:
            self.get_logger().info("Position is missing. Skipping update.")
            return

        #copy variables so i can reuse code
        self.agent = self.real_pos_agent
        self.target = self.real_pos_target
        self.target_goal = np.asarray([self.GOAL_LOCATION_x, self.GOAL_LOCATION_y], dtype=float)
        self.g = float(self.GAIN_LIST[0])
        self.k1 = float(self.GAIN_LIST[1])
        self.k2 = float(self.GAIN_LIST[2])

        #(3) target regulation error
        ex = self.target - self.target_goal
        self.get_logger().info(f'target error: {ex}')

        #(6) desired target trajectory
        yd = self.target + (1/self.g)*(self.k1*ex)
        
        #(4) backstepping error
        ey = yd - self.agent
            
        #(9) control input
        u = self.k2*ey - ( (self.k1**2 / self.g) + self.g )*ex
        self.get_logger().info(f'control output: {u}')

        self.agent_vel_hol = u * self.dt


        #check if target is within goal location radius
        self.target_distance_from_goal = np.linalg.norm(self.real_pos_target - self.target_goal)
        self.get_logger().info(f'target goal dist: {self.target_distance_from_goal}')
        if self.target_distance_from_goal < self.GOAL_RADIUS:
            self.agent_vel_hol = np.array([0.0, 0.0])        

        #grab current heading
        _, _, self.agent_yaw = euler_from_quaternion(tuple(self.agent_heading_list))
        #self.get_logger().info(f'current heading: {self.agent_yaw}')

        #publish for robots
        #self.convert_and_publish_velocity(self.agent_vel_pub, self.agent_vel_hol, self.MAX_VEL, self.agent_yaw)
        #publish for matplotlib sim
        self.pub_delta_vel(self.agent_holonomic_vel_pub, self.agent_vel_hol, self.MAX_VEL)
        
        #reset empty message check. we only want to run the controller with new data.=
        self.real_pos_agent = None






        # if self.real_pos_agent is None:
        #     self.get_logger().info("Position is missing. Skipping update.")
        #     return

        # #self.get_logger().info(f'vel_hol: {self.agent_vel_hol}')

        # #publish velocities
        # _, _, self.agent_yaw = euler_from_quaternion(tuple(self.agent_heading_list))
        # self.get_logger().info(f'current heading: {self.agent_yaw}')

        # #self.convert_and_publish_velocity(self.agent_vel_pub, self.agent_vel_hol, self.MAX_VEL, self.agent_yaw)
        # self.convert_and_publish_velocity(self.agent_vel_pub, self.agent_vel_hol, self.MAX_VEL, self.agent_yaw)

        # self.pub_delta_vel(self.agent_holonomic_vel_pub, self.agent_vel_hol, self.MAX_VEL)
        # #swap the commented sections to make it wokr with ground robots
        
        # #self.get_logger().info(f'\n') #empty comment to seperate steps in console window
        # self.real_pos_agent = None

    #--------------------------------


    def cnvt_and_pub(self, publisher, velocity_hol, v_max, yaw):
        theta = yaw # Extract yaw from pose
        linear_x = np.linalg.norm(velocity_hol)
        angular_z = math.atan2(self.velocity_hol[1], self.velocity_hol[0]) - theta
        angular_z = self.normalize_angle(angular_z)

        if linear_x > v_max: #cap linear speed so we don't tell the dogs to run too fast
            linear_x = v_max
        
        #self.get_logger().info(f'Publishing Vel Hol: {velocity_hol}')
        #self.get_logger().info(f'Publishing lin,ang: {v_lin}, {v_ang}')

        twist_msg = Twist() #create twist message to pack data into to publish
        twist_msg.linear.x = linear_x
        twist_msg.angular.z = angular_z

        publisher.publish(twist_msg) #publish twist message   


    def normalize_angle(self, angle):
        """Normalize an angle to the range [-pi, pi]."""
        return (angle + math.pi) % (2 * math.pi) - math.pi


    def convert_and_publish_velocity(self, publisher, velocity_hol, v_max, yaw): #publish the vel commands as a twist message
        #this converts the [dx,dy] vel vector to a linear component and angular component
        v_lin = np.linalg.norm(velocity_hol) #take the norm for the linear component

        if v_lin == 0:
            atan2_angle = 0
        else:
            atan2_angle = np.arctan2(velocity_hol[1], velocity_hol[0])  # Correctly use the y and x

        if math.isnan(v_lin) or math.isnan(atan2_angle):
            return

        v_ang = atan2_angle - yaw #subtract current heading

        #if v_ang > 0: #wrap angle so it stays between -pi to pi
        #    while v_ang > np.pi:
        #        v_ang -= 2*np.pi
        #else:
        #    while v_ang < -np.pi:
        #        v_ang += 2*np.pi
        # Normalize the angle to be within -pi to pi
        v_ang = (v_ang + np.pi) % (2 * np.pi) - np.pi
        
        #v_ang *= -0.8 #coefficient is a gain so we dont do 360deg rotations instantly. negative worked best but i need to investigate further.

        if v_lin > v_max: #cap linear speed so we don't tell the dogs to run too fast
            v_lin = v_max
        
        #self.get_logger().info(f'Publishing Vel Hol: {velocity_hol}')
        #self.get_logger().info(f'Publishing lin,ang: {v_lin}, {v_ang}')

        twist_msg = Twist() #create twist message to pack data into to publish
        twist_msg.linear.x = v_lin
        twist_msg.angular.z = v_ang

        publisher.publish(twist_msg) #publish twist message
        return v_lin #return velocity so it can be used to keep the robot moving when position has not been updated. not implemented yet.
    

    def pub_lin_vel(self, publisher, velocity): #this is supposed to publish a linear velocity only as a twist message. it will be used to make the robots keep moving when the gps does not send the position and the simulation cannot be run since it depends on n current gps values. not implemnted yet.
        #self.get_logger().info(f'Publishing Last linear vel: {velocity}')
        twist_msg = Twist()
        twist_msg.linear.x = velocity
        publisher.publish(twist_msg)


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
