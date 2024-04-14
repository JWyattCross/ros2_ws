import sys
import os
from launch import LaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    return LaunchDescription([
        Node(
            package='matplotlib_sim',
            executable='matplotlib_sim_node',
            name='matplotlib_sim',
        ),
        Node(
            package='single_integrator_agent',
            namespace='a200_0708',
            executable='single_int_node',
            name='single_integrator_agent_1',
            parameters=[
                {'x_init': 5.0},
                {'y_init': 5.0},
                {'name': 'a200_0708'},
            ],
        ),
        # Node(
        #     package='consensus_control',
        #     namespace='r1',
        #     executable='consensus_control_node',
        #     name='consensus_control_node_1',
        #     parameters=[
        #         {'max_vel': 0.25},
        #         {'K': 1.0},
        #         {'name': 'r1'},
        #     ],
        # ),
        Node(
            package='single_integrator_agent',
            namespace='a200_0706',
            executable='single_int_node',
            name='single_integrator_agent_target_2',
            parameters=[
                {'x_init': -5.0},
                {'y_init': -5.0},
                {'name': 'a200_0706'},
            ],
        ),
        # Node(
        #     package='consensus_control',
        #     namespace='r2',
        #     executable='consensus_control_node',
        #     name='consensus_control_node_2',
        #     parameters=[
        #         {'max_vel': 0.25},
        #         {'K': 1.0},
        #         {'name': 'r2'},
        #     ],
        # ),
    ])
