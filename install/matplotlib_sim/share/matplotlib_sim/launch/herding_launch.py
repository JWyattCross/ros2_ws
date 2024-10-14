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
        # Agent 1 and Herding Control
        Node(
            package='single_integrator_agent',
            namespace='r1',
            executable='single_int_node',
            name='single_integrator_agent_1',
            parameters=[
                {'x_init': -5.0},
                {'y_init': 0.0},
                {'name': 'r1'},
            ],
        ),
        Node(
            package='herding_control',
            namespace='r1',
            executable='herding_control_node',
            name='herding_control_node_1',
            output='screen',
            parameters=[
                {'name': 'r1'},
                {'IS_AGENT': False},
                {'dt': 0.1},
                {'MAX_SPEED_MS': 2.0},
                {'LEVY_WALK_PARAM': 7.0},
            ],
        ),
        # Repeat for additional agents as needed...
        # Agent 1 and Herding Control
        Node(
            package='single_integrator_agent',
            namespace='r2',
            executable='single_int_node',
            name='single_integrator_agent_2',
            parameters=[
                {'x_init': 5.0},
                {'y_init': 0.0},
                {'name': 'r2'},
            ],
        ),
        Node(
            package='herding_control',
            namespace='r2',
            executable='herding_control_node',
            name='herding_control_node_2',
            output='screen',
            parameters=[
                {'name': 'r2'},
                {'IS_AGENT': False},
                {'dt': 0.1},
                {'MAX_SPEED_MS': 2.0},
                {'LEVY_WALK_PARAM': 7.0},
            ],
        ),
    ])
