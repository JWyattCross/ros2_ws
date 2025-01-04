import rclpy
from geometry_msgs.msg import PoseStamped
from rclpy.node import Node

class PosePublisher(Node):
    def __init__(self):
        super().__init__('test_pub_pose_node')

        # Publisher to publish PoseStamped message
        self.pose_publisher = self.create_publisher(PoseStamped, 'pose', 10)

        # Timer to periodically publish pose
        self.timer = self.create_timer(1.0, self.publish_pose)

    def publish_pose(self):
        # Create a PoseStamped message (Pose with timestamp and frame_id)
        pose_stamped = PoseStamped()

        # Set the header with the current time and frame_id
        pose_stamped.header.stamp = self.get_clock().now().to_msg()  # Get the current time
        pose_stamped.header.frame_id = 'autonomy_park'  # Set the frame ID (could be 'world', 'map', etc.)

        # Set position
        pose_stamped.pose.position.x = 1.0
        pose_stamped.pose.position.y = 2.0
        pose_stamped.pose.position.z = 0.0

        # Set orientation (no rotation in this case, i.e., identity quaternion)
        pose_stamped.pose.orientation.x = 0.0
        pose_stamped.pose.orientation.y = 0.0
        pose_stamped.pose.orientation.z = 0.0
        pose_stamped.pose.orientation.w = 1.0

        # Publish the PoseStamped message
        self.pose_publisher.publish(pose_stamped)

        self.get_logger().info('Publishing Pose: {}'.format(pose_stamped))

def main(args=None):
    rclpy.init(args=args)
    node = PosePublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
