import math
import numpy as np
import rclpy # type: ignore
from geometry_msgs.msg import PoseStamped, Twist # type: ignore
from rclpy.node import Node # type: ignore
from tf_transformations import euler_from_quaternion # type: ignore


class PubNode(Node): #this is the main method of the function where all the ros publishers/subscribers are created
    def __init__(self):
        super().__init__('herding_control_node') #node name, must match filename

        #Robot namespaces
        '''AP robot names:
            /j100_0572
            /a200_0706 
            /a200_0708
            /go1_0153  #small dog with blue parts
            /go1_0154
            /go1_0155
        no trailing '/' as it is concatenated in each pub/sub creation line below already'''

        #create parameters for variables
        self.declare_parameter('name', "dummy")
        self.declare_parameter('IS_AGENT', False) #defaults to target
        self.declare_parameter('dt', 0.01)
        self.declare_parameter('GAIN', 10)
        self.declare_parameter('MAX_SPEED_MS', 0.2)
        self.declare_parameter('SIGHT_RANGE_METERS', 5.0)
        self.declare_parameter('LEVY_WALK_PARAM', 6.9)
        
        #get parameters
        #self.namespace = self.get_parameter('name').value
        self.is_agent = self.get_parameter('IS_AGENT').value
        self.dt = self.get_parameter('dt').value
        self.GAIN = self.get_parameter('GAIN').value
        self.MAX_VEL = self.get_parameter('MAX_SPEED_MS').value
        self.SIGHT_RANGE = self.get_parameter('SIGHT_RANGE_METERS').value
        self.LEVY_WALK_PARAM = float(self.get_parameter('LEVY_WALK_PARAM').value)

        #publish velocity (linear x and anglular z)
        self.vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)

        #subscribe to real-world robot position
        self.pos_sub = self.create_subscription(PoseStamped, 'pose', self.pos_callback, 10)

        #create timer using dt from parameters
        self.timer = self.create_timer(self.dt, self.update_motion)

        #variables for checks to make sure values are valid
        self.real_pos = None
        #self.real_pos_target = None

        #set initial velocity to zero
        self.my_vel = 0.0


    def pos_callback(self, msg): #get real positions and update sim. This runs whenever a postion is revieved to update our position array
        self.real_pos = np.array([msg.pose.position.x, msg.pose.position.y])
        self.heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        self.get_logger().info(f'Position:  [{msg.pose.position.x}, {msg.pose.position.y}]')

    #def target_pos_callback(self, msg):
    #    self.real_pos_target = np.array([msg.pose.position.x, msg.pose.position.y])
    #    self.target_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
    #    self.get_logger().info(f'Target position: [{msg.pose.position.x}, {msg.pose.position.y}]')

    def update_motion(self):
        if self.real_pos is None:
            self.get_logger().info("Position is missing. Skipping update.")
            return

        if self.is_agent:
            pass
            #do agent stuff here
        else:
            self.target_vel_hol = self.levy_walk(self.LEVY_WALK_PARAM)
            self.get_logger().info(f'vel_hol: {self.target_vel_hol}')

            self.pub_delta_vel(self.vel_pub, self.target_vel_hol, self.MAX_VEL)

            self.get_logger().info(f'\n') #empty comment to seperate steps in console window
            self.real_pos = None #zero out variables to check for when the robots are off

    def levy_walk(self, alpha):
        step_length = np.random.pareto(alpha) #generate a step
        angle = np.random.uniform(0, 2 * np.pi)
        dx = step_length * np.cos(angle) #calculate hollonomic values
        dy = step_length * np.sin(angle)
        return np.array([dx, dy])
    
    def fearFunction(self, target, agent, distance):
        opposite_vec = target - agent
        fear_factor = 1.0 #np.exp(distance)
        t_dot = fear_factor * opposite_vec
        return t_dot

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

    def pub_delta_vel(self, publisher, velocity, max): #this is supposed to publish a linear velocity only as a twist message. it will be used to make the robots keep moving when the gps does not send the position and the simulation cannot be run since it depends on n current gps values. not implemnted yet.
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




'''#!/usr/bin/env python3

# ROS2 library imports
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist

class HerdingControl(Node):
    def __init__(self):
        super().__init__('herding_control_node')

        # Define parameters
        self.declare_parameter('name', 'r1')

        # Get the parameters
        self.name = self.get_parameter('name').value

        # Define publishers and subscribers
        self.cmd_vel_pub = self.create_publisher(Twist, f'{self.name}/cmd_vel', 10)

        # Placeholder to receive external commands (replace this as needed)
        self.create_timer(1.0, self.control_loop)

    def control_loop(self):
        # Generate a sample command for moving the agent
        twist_msg = Twist()
        twist_msg.linear.x = 0.1  # example linear velocity
        twist_msg.linear.y = 0.0
        twist_msg.angular.z = 0.0
        self.cmd_vel_pub.publish(twist_msg)


# Define the HerdingControl class
class HerdingControl(Node):
    def __init__(self):
        super().__init__('herding_control')

        # Define parameters
        self.declare_parameter('x_target', 0.0)
        self.declare_parameter('y_target', 0.0)
        self.declare_parameter('name', 'r1')

        # Get parameters
        self.x_target = self.get_parameter('x_target').value
        self.y_target = self.get_parameter('y_target').value
        self.name = self.get_parameter('name').value

        # Define publishers
        self.pose_pub_ = self.create_publisher(PoseStamped, 'pose', 10)

        # Set the timer period and define the timer function that loops at the desired rate
        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        # Create and publish PoseStamped message
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self.name  # This should match the agent's name
        msg.pose.position.x = self.x_target
        msg.pose.position.y = self.y_target
        msg.pose.position.z = 0.0
        msg.pose.orientation.w = 1.0

        # Publish the pose message
        self.pose_pub_.publish(msg)

# Boilerplate to make the node work
def main(args=None):
    rclpy.init(args=args)
    herding_control = HerdingControl()
    rclpy.spin(herding_control)
    herding_control.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
'''