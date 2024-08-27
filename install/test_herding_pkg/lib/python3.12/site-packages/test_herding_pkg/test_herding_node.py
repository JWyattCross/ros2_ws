import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import math

class PositionSimulator(Node):
    def __init__(self):
        super().__init__('test_herding_node')
        self.agent1_pos_pub = self.create_publisher(PoseStamped, '/a200_0706/pose', 10)
        self.target1_pos_pub = self.create_publisher(PoseStamped, '/a200_0708/pose', 10)#/j100_0572/pose
        dt = 0.1 #timestep
        self.timer = self.create_timer(dt, self.publish_positions)

    def publish_positions(self):
        # Simulate sinusoidal oscillations
        time = self.get_clock().now().nanoseconds / 1e9  # Current time in seconds
        amplitude = 0.5  # Adjust this value as needed
        frequency = 0.5  # Adjust this value as needed
        oscillation = amplitude * math.sin(2 * math.pi * frequency * time)

        # Create PoseStamped messages
        agent1_pose = PoseStamped()
        agent1_pose.pose.position.x = 1.0 + oscillation
        agent1_pose.pose.position.y = 2.0 + oscillation
        #agent1_pose.pose.position.z = 0.5 + oscillation
        self.agent1_pos_pub.publish(agent1_pose)

        target1_pose = PoseStamped()
        target1_pose.pose.position.x = 3.0 + oscillation
        target1_pose.pose.position.y = 4.0 + oscillation
        #target1_pose.pose.position.z = 1.0 + oscillation
        self.target1_pos_pub.publish(target1_pose)

def main(args=None):
    rclpy.init(args=args)
    herding_pub_node = PositionSimulator()
    rclpy.spin(herding_pub_node)
    herding_pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
