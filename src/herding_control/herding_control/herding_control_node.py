#!/usr/bin/env python3

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

'''
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
'''
# Boilerplate to make the node work
def main(args=None):
    rclpy.init(args=args)
    herding_control = HerdingControl()
    rclpy.spin(herding_control)
    herding_control.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
