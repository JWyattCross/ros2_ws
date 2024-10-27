import os
import yaml

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    file_path = os.path.expanduser("/home/robot_param.yaml")
    with open(file_path, "r") as stream:
        try:
            data_loaded = yaml.safe_load(stream)
            robot_namespace = '/'+ data_loaded['robot_namespace']

        except yaml.YAMLError as exc:
            print(exc)

    sensors_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
        get_package_share_directory('minimal_startup')),
        '/sensors_service.launch.py'])
    )
    position_broadcaster = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
        get_package_share_directory('position_broadcaster'), 'launch'),
        '/position_broadcaster_launch.py'])
    )

    return LaunchDescription([
        position_broadcaster,
        sensors_launch,
        Node(
            package='udp_velocity_interface',
            namespace=robot_namespace,
            executable='udp_velocity_interface_node',
            name='udp_velocity_interface_node',
            parameters=[
            ]
        ),
        Node(
            package='unitree_legged_real',
            namespace=robot_namespace,
            executable='ros2_udp',
            name='ros2_udp',
            parameters=[
            ]
        ),
    ])
