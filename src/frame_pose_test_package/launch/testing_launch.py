import os
import sys
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, ExecuteProcess
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='false', description='Use simulation time if true'),

        # Start the spoof_static_transform_node
        ExecuteProcess(
            cmd=['ros2', 'run', 'frame_pose_test_package', 'spoof_static_transform_node'],
            output='screen',
            name='spoof_static_transform_node'
        ),
        
        # Start the test_pub_pose_node
        ExecuteProcess(
            cmd=['ros2', 'run', 'frame_pose_test_package', 'test_pub_pose_node'],
            output='screen',
            name='test_pub_pose_node'
        ),
    ])
