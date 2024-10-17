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
        self.declare_parameter('TARGET_LIST', [])

        self.dt = self.get_parameter('dt').value
        self.MAX_VEL = self.get_parameter('MAX_SPEED_MS').value
        self.TARGET_LIST = self.get_parameter('TARGET_LIST').value
        
        #publish velocity (linear x and anglular z)
        self.agent_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)

        #subscribe to  my real-world robot position
        self.agent_pos_sub = self.create_subscription(PoseStamped, 'pose', self.pos_callback, 10)
        #subscribe to agent real-world robot position
        #todo later
        #self.target_pos_sub = self.create_subscription(PoseStamped, self.TARGET_LIST + '/pose', self.agent_pos_callback, 10)
        
        # subscribe to joystick input
        self.joy_sub = self.create_subscription(Joy, 'joy', self.joy_callback, 10)

        #create timer using dt from parameters
        self.timer = self.create_timer(self.dt, self.update_motion)

        #variables for checks to make sure values are valid. bad when gps drops out otherwise
        self.real_pos_agent = None

        #set intitial vel to 0
        self.agent_vel_hol = np.array([0.0, 0.0])


    def agent_pos_callback(self, msg):
        self.real_pos_agent = np.array([msg.pose.position.x, msg.pose.position.y])
        self.agent_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        #self.get_logger().info(f'Agent position: [{msg.pose.position.x}, {msg.pose.position.y}]')

    def joy_callback(self, msg):
        # Assuming left stick is at index 1 and 0 (Y and X axis)
        self.agent_vel_hol[0] = msg.axes[1]  # Vertical axis (Y)
        self.agent_vel_hol[1] = msg.axes[0]  # Horizontal axis (X)

    def update_motion(self):
        if self.real_pos_agent is None:
            self.get_logger().info("Position is missing. Skipping update.")
            return

        self.get_logger().info(f'vel_hol: {self.agent_vel_hol}')

        #publish velocities
        #_, _, self.target_yaw = euler_from_quaternion(self.target_heading_list)
        #self.target_vel = self.convert_and_publish_velocity(self.target_vel_pub, self.target_vel_hol, self.MAX_VEL, self.target_yaw)
        self.pub_delta_vel(self.agent_vel_pub, self.agent_vel_hol, self.MAX_VEL)
        #swap the commented sections to make it wokr with ground robots
        
        self.get_logger().info(f'\n') #empty comment to seperate steps in console window
        self.real_pos_agent = None


    def convert_and_publish_hollonomic_velocity(self, publisher, velocity_hol, v_max, yaw): #publish the vel commands as a twist message
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
        self.get_logger().info(f'Publishing Twist: linear x: {twist_msg.linear.x}, y: {twist_msg.linear.y}')


#ros2 boilerplate, make sure pub_node matches the main function above
def main(args=None):
    rclpy.init(args=args)
    pub_node = PubNode()
    rclpy.spin(pub_node)
    pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
