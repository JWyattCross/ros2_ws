import os

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    file_path = os.path.expanduser("~/../home/robot_param.yaml")
    with open(file_path, "r") as stream:
        try:
            data_loaded = yaml.safe_load(stream)
            robot_namespace = '/'+ data_loaded['robot_namespace']

        except yaml.YAMLError as exc:
            print(exc)

    return LaunchDescription([
        position_broadcaster,
        sensors_launch,
        Node(
            package='b1_udp_velocity_interface',
            namespace=robot_namespace,
            executable='udp_velocity_interface_node',
            name='udp_velocity_interface_node',
            parameters=[
            ]
        ),
        Node(
            package='b1_legged_real',
            namespace=robot_namespace,
            executable='ros2_udp',
            name='ros2_udp',
            parameters=[
            ]
        ),
    ])
