import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import socket

class WindSensorNode(Node):
    def __init__(self):
        super().__init__('wind_sensor_node')
        self.publisher_speed = self.create_publisher(Float32, 'wind_speed', 10)
        self.publisher_direction = self.create_publisher(Float32, 'wind_direction', 10)

        self.TCP_IP = "192.168.1.31" #static ip
        self.TCP_PORT = 4001

        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((self.TCP_IP, self.TCP_PORT))
        self.get_logger().info(f'TCP client connected. Press Ctrl+C to stop.')

        self.timer = self.create_timer(1, self.get_wind_data)


    def get_wind_data(self):
        data = self.sock.recv(1024)
        if not data:
            return

        decoded_data = data.decode()
        parts = decoded_data.split()

        header = parts[0]
        speed = float(parts[1])
        heading = float(parts[2])
        checksum = parts[3]

        self.get_logger().info(f'Wind Speed: {speed}')
        self.get_logger().info(f'Heading:    {heading}')

        self.publish_wind_speed(speed)
        self.publish_wind_direction(heading)


    def publish_wind_speed(self, speed):
        msg = Float32()
        msg.data = speed #should be a positive float
        self.publisher_speed.publish(msg)

    def publish_wind_direction(self, direction):
        msg = Float32()
        msg.data = direction #should be a float from 0 to 360 degrees
        self.publisher_direction.publish(msg)

    def on_shutdown(self):
        self.get_logger().info("Closing socket...")
        self.sock.close()


def main(args=None):
    rclpy.init(args=args)
    wind_sensor_node = WindSensorNode()
    try:
        rclpy.spin(wind_sensor_node)
    except KeyboardInterrupt:
        pass
    finally:
        wind_sensor_node.on_shutdown()
        wind_sensor_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
