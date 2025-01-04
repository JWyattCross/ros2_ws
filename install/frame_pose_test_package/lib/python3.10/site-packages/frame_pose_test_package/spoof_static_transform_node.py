import rclpy
from geometry_msgs.msg import TransformStamped
from tf2_ros import StaticTransformBroadcaster
from rclpy.node import Node

class StaticTransformPublisher(Node):
    def __init__(self):
        super().__init__('spoof_static_transform_node')

        # Create a static transform broadcaster
        self.br = StaticTransformBroadcaster(self)

        # Set the static transform
        self.publish_transform()

    def publish_transform(self):
        # Create the TransformStamped message
        transform = TransformStamped()

        # Set the header
        transform.header.stamp = self.get_clock().now().to_msg()
        transform.header.frame_id = 'world'  # Parent frame
        transform.child_frame_id = 'autonomy_park'  # Child frame

        # Set the transform (translation and rotation)
        transform.transform.translation.x = 0.0
        transform.transform.translation.y = 0.0
        transform.transform.translation.z = 0.0

        transform.transform.rotation.x = 0.0
        transform.transform.rotation.y = 0.0
        transform.transform.rotation.z = 0.0
        transform.transform.rotation.w = 1.0  # Identity quaternion (no rotation)

        # Publish the transform
        self.br.sendTransform(transform)

        self.get_logger().info('Publishing static transform from world to autonomy_park')

def main(args=None):
    rclpy.init(args=args)
    node = StaticTransformPublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
