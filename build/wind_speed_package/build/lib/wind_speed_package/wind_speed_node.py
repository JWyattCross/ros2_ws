import rclpy
from rclpy.node import Node

from std_msgs.msg import Float32

import socket
import struct

class WindSensorNode(Node):
    def __init__(self):
        super().__init__('wind_sensor_node')
        self.publisher_speed = self.create_publisher(Float32, 'wind_speed', 10)
        self.publisher_direction = self.create_publisher(Float32, 'wind_direction', 10)

        self.udp_socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
        self.udp_socket.bind(('127.0.0.1', 0000)) #ip and port

        self.timer = self.create_timer(1, self.publish_wind_data)

    def publish_wind_data(self):
        message, address = self.udp_socket.recvfrom(1024) #1024 is buffer size
        wind_speed, wind_direction = struct.unpack('ff', message)
        self.publish_wind_speed(wind_speed)
        self.publish_wind_direction(wind_direction)


    def publish_wind_speed(self, speed):
        msg = Float32()
        msg.data = speed #should
        self.publisher_speed.publish(msg)

    def publish_wind_direction(self, direction):
        msg = Float32()
        msg.data = direction #should be a float from 0 to 360 degrees
        self.publisher_direction.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    wind_sensor_node = WindSensorNode()
    rclpy.spin(wind_sensor_node)
    wind_sensor_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
