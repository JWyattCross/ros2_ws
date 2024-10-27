#!/usr/bin/env python3

#ROS2 library imports
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data

#System imports - not always used but necessary sometimes
import sys
import os
import math
import numpy as np

#Import the interfaces here
#for example, using the Header msg from the std_msgs package
from uf_interfaces.msg import Position
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Imu, NavSatFix


#Define your class - use package name with camel case capitalization
class PositionBroadcaster(Node):
    #Initialize the class
    def __init__(self):
        #Create the node with whatever name (package name + node)
        super().__init__('position_broadcaster_node')

        #Define the publishers here
        #self.'publisher_var_name' = self.create_publisher('MessageType', '/topic_name', 'queue length')
        self.declare_parameter('vehicle_domain', '')
        self.declare_parameter('vehicle_type', '')
        self.declare_parameter('vehicle_name', '')

        self.declare_parameter('origin_easting', 368304.87143102096)
        self.declare_parameter('origin_northing', 3278357.789323321)
        self.declare_parameter('origin_rotation', -0.6021965548550632)

        self.origin_easting = self.get_parameter('origin_easting').value
        self.origin_northing = self.get_parameter('origin_northing').value
        self.origin_rotation = self.get_parameter('origin_rotation').value

        self.veh_domain = self.get_parameter('vehicle_domain').value
        self.veh_type = self.get_parameter('vehicle_type').value
        self.veh_name = self.get_parameter('vehicle_name').value

        topic_name_ = ''

        if self.veh_domain != '':
            topic_name_ += '/'+self.veh_domain
        if self.veh_type != '':
            topic_name_ += '/'+self.veh_type

        if topic_name_ == '':
            self.pos_pub_ = self.create_publisher(Position, '/pose', 10)
            self.pose_pub_ = self.create_publisher(PoseStamped, 'pose', 10)
        else:
            self.pos_pub_ = self.create_publisher(Position, topic_name_+'/pos', 10)
            self.pose_pub_ = self.create_publisher(PoseStamped, topic_name_+'/pose', 10)

        #Define the subscribers here
        #self.'subscriber_var_name' = self.create_subscription('MessageType', '/topic_name', self.'callback_function', 'queue length')
        self.imu_sub = self.create_subscription(Imu, "imu/data", self.imu_callback, qos_profile=qos_profile_sensor_data)
        self.utm_sub_ = self.create_subscription(NavSatFix, 'rtk/utm', self.gps_callback, qos_profile=qos_profile_sensor_data)

        self.gps_init = False
        self.gps_data = Imu()
        self.gps_epoch = self.get_clock().now()

        self.imu_init = False
        self.imu_data = Imu()
        self.imu_epoch = self.get_clock().now()

        #Set the timer period and define the timer function that loops at the desired rate
        time_period = 1/10
        self.timer = self.create_timer(time_period, self.timer_callback)

    def timer_callback(self):

        #publish pose
        if self.gps_init:
            if self.safety_check(self.gps_epoch, 'gps'):
                if self.imu_init:
                    if self.safety_check(self.imu_epoch, 'imu'):
                        self.local_transform()

    def local_transform(self):

        x = self.current_pos[0] - self.origin_easting
        y = self.current_pos[1] - self.origin_northing
        alt = self.current_pos[2]
        w = self.origin_rotation
        rot = [math.cos(w)*x+math.sin(w)*y, -math.sin(w)*x+math.cos(w)*y]
        x = rot[0]
        y = rot[1]

        pos_msg = PoseStamped()
        pos_msg.header.stamp = self.get_clock().now().to_msg()
        pos_msg.header.frame_id = self.veh_name
        pos_msg.pose.position.x = x
        pos_msg.pose.position.y = y
        pos_msg.pose.position.z = alt

        xi = self.imu_data.orientation.x
        yi = self.imu_data.orientation.y
        zi = self.imu_data.orientation.z
        wi = self.imu_data.orientation.w

        euler = self.euler_from_quaternion([wi,xi,yi,zi])
        #euler = tf_transformations.euler_from_quaternion([wi,xi,yi,zi], axes='sxyz')
        euler = list(euler)
        euler[2] = self.wrap_angle(euler[2] - self.origin_rotation)

        quat = self.quaternion_from_euler(euler[0], euler[1], euler[2])

        pos_msg.pose.orientation.x = quat[1]
        pos_msg.pose.orientation.y = quat[2]
        pos_msg.pose.orientation.z = quat[3]
        pos_msg.pose.orientation.w = quat[0]

        # pos_msg.pose.orientation.x = self.imu_data.orientation.x
        # pos_msg.pose.orientation.y = self.imu_data.orientation.y
        # pos_msg.pose.orientation.z = self.imu_data.orientation.z
        # pos_msg.pose.orientation.w = self.imu_data.orientation.w

        # self.get_logger().warn("Publishing pose...")
        self.pose_pub_.publish(pos_msg)
        #self.get_logger().warn("Pose published.")

        pos_msg = Position()
        pos_msg.name = self.veh_name
        pos_msg.x = x
        pos_msg.y = y
        pos_msg.z = alt
        pos_msg.yaw = euler[2]

        # self.get_logger().warn("Publishing position...")
        self.pos_pub_.publish(pos_msg)
        # self.get_logger().warn("Position published.")

    def imu_callback(self, msg):
        self.imu_epoch = self.get_clock().now()
        self.imu_data = msg
        self.imu_init = True

    def gps_callback(self, msg):
        self.gps_init = True
        self.gps_epoch = self.get_clock().now()
        x = msg.latitude
        y = msg.longitude
        z = msg.altitude
        self.current_pos = [x, y, z]

    def wrap_angle(self, angle):
        if angle > 0:
            if angle > math.pi:
                return angle - 2*math.pi
        else:
            if angle < -math.pi:
                return angle + 2*math.pi
        return angle

    def safety_check(self, epoch, sensor):

        if (self.get_clock().now()-epoch).nanoseconds*(10**-9) < 2.0: #1 second since last update
            return True
        else:
            self.get_logger().warn('Missing sensor data or sensor data missing update rate: {0}'.format(sensor))
            return False

    def quaternion_from_euler(self, roll, pitch, yaw): #roll (x), pitch (Y), yaw (z)

        #Abbreviations for the various angular functions

        cr = math.cos(roll * 0.5);
        sr = math.sin(roll * 0.5);
        cp = math.cos(pitch * 0.5);
        sp = math.sin(pitch * 0.5);
        cy = math.cos(yaw * 0.5);
        sy = math.sin(yaw * 0.5);

        qw = cr * cp * cy + sr * sp * sy;
        qx = sr * cp * cy - cr * sp * sy;
        qy = cr * sp * cy + sr * cp * sy;
        qz = cr * cp * sy - sr * sp * cy;

        q = [qw, qx, qy, qz]

        return q;

    def euler_from_quaternion(self, q):

        #roll (x-axis rotation)
        sinr_cosp = 2 * (q[0] * q[1] + q[2] * q[3]);
        cosr_cosp = 1 - 2 * (q[1] * q[1] + q[2] * q[1]);
        roll = math.atan2(sinr_cosp, cosr_cosp);

        #pitch (y-axis rotation)
        sinp = np.sqrt(1 + 2 * (q[0] * q[2] - q[1] * q[3]));
        cosp = np.sqrt(1 - 2 * (q[0] * q[2] - q[1] * q[3]));
        pitch = 2 * math.atan2(sinp, cosp) - math.pi / 2;

        #yaw (z-axis rotation)
        siny_cosp = 2 * (q[0] * q[3] + q[1] * q[2]);
        cosy_cosp = 1 - 2 * (q[2] * q[2] + q[3] * q[3]);
        yaw = math.atan2(siny_cosp, cosy_cosp);

        angles = [roll, pitch, yaw]

        return angles;


#This is some boiler plate code that you slap at the bottom
#to make the node work.
#Make sure to update the name of the function and package, etc
#to match your node
def main(args=None):
    rclpy.init(args=args)

    position_broadcaster = PositionBroadcaster()
    rclpy.spin(position_broadcaster)
    position_broadcaster.destroy_node()
    rclpy.shutdown()

if __name__ == 'main':
    main()
