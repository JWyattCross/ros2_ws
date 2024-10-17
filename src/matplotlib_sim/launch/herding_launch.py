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
        # Herder and Herding Control
        Node(
            package='single_integrator_agent',
            namespace='sheepdog',
            executable='single_int_node',
            name='single_integrator_agent_1',
            parameters=[
                {'x_init': 0.0},
                {'y_init': 8.0},
                {'name': 'sheepdog'},
            ],
        ),
        Node(
            package='herding_control',
            namespace='sheepdog',
            executable='herding_control_node',
            name='herding_control_node_1',
            output='screen',
            parameters=[
                {'name': 'sheepdog'},
                {'IS_AGENT': True},
                {'TARGET_LIST': ['1sheep', '2sheep']},
                {'dt': 0.1},
                {'MAX_SPEED_MS': 5.0},
                {'LEVY_WALK_PARAM': 7.0},
            ],
        ),
        # Agent 1 and Herding Control
        Node(
            package='single_integrator_agent',
            namespace='1sheep',
            executable='single_int_node',
            name='single_integrator_agent_2',
            parameters=[
                {'x_init': -5.0},
                {'y_init': 0.0},
                {'name': '1sheep'},
            ],
        ),
        Node(
            package='herding_control',
            namespace='1sheep',
            executable='herding_control_node',
            name='herding_control_node_2',
            output='screen',
            parameters=[
                {'name': '1sheep'},
                {'IS_AGENT': False},
                {'BIG_BAD_WOLF': 'sheepdog'},
                {'dt': 0.1},
                {'MAX_SPEED_MS': 2.0},
                {'LEVY_WALK_PARAM': 7.0},
            ],
        ),
        # Agent 2 and Herding Control
        Node(
            package='single_integrator_agent',
            namespace='2sheep',
            executable='single_int_node',
            name='single_integrator_agent_3',
            parameters=[
                {'x_init': 5.0},
                {'y_init': 0.0},
                {'name': '2sheep'},
            ],
        ),
        Node(
            package='herding_control',
            namespace='2sheep',
            executable='herding_control_node',
            name='herding_control_node_3',
            output='screen',
            parameters=[
                {'name': '2sheep'},
                {'IS_AGENT': False},
                {'BIG_BAD_WOLF': 'sheepdog'},
                {'dt': 0.1},
                {'MAX_SPEED_MS': 2.0},
                {'LEVY_WALK_PARAM': 7.0},
            ],
        ),
    ])
