import sys
import os
from launch import LaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import TimerAction

from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='matplotlib_sim',
            executable='matplotlib_sim_node',
            name='matplotlib_sim',
        ),
        # Target 1 and Herding Control
        Node(
            package='single_integrator_agent',
            namespace='sheep1',
            executable='single_int_node',
            name='single_integrator_agent_1',
            parameters=[
                {'x_init': -3.0},
                {'y_init': 1.0},
                {'name': 'sheep1'},
            ],
        ),
        Node(
            package='herding_control',
            namespace='sheep1',
            executable='herding_target_node',
            name='herding_target_node_1',
            parameters=[
                {'dt': 0.1},
                {'MAX_SPEED_MS': 1.0},
                {'LEVY_WALK_PARAM': 20.0},
                {'BIG_BAD_WOLF': 'sheepdog'},
                {'SIGHT_RANGE_METERS': 20.0},
            ],
        ),
        # Agent and Herding Control
        Node(
            package='single_integrator_agent',
            namespace='sheepdog',
            executable='single_int_node',
            name='single_integrator_agent_2',
            parameters=[
                {'x_init': 8.0},
                {'y_init': 7.0},
                {'name': 'sheepdog'},
            ],
        ),
        # Delay of 1 seconds. This helps prevent errors when topics are starting up.
        TimerAction(
            period=1.0,
            actions=[

                Node(
                    package='herding_control',
                    namespace='sheepdog',
                    executable='herding_agent_node',
                    name='herding_agent_node_1',
                    output='screen',
                    parameters=[
                        {'dt': 0.1},
                        {'MAX_SPEED_MS': 2.0},
                        {'TARGET_NAME': 'sheep1'},
                        {'GOAL_LOCATION_x': -5.0},
                        {'GOAL_LOCATION_y': -5.0},
                        {'GOAL_RADIUS': 2.0},
                    ],
                ),
            ]
        ),

        #rviz visualization packages
        Node(
            package='frame_pose_test_package',
            executable='spoof_static_transform_node',
            name='convert_world_frame_to_apark',
        ),

        Node(
            package='autonomy_park_viz',
            executable='autonomy_park_viz_node',
            name='autonomy_park_viz_node',
            namespace='autonomy_park_viz',
            parameters=[os.path.join(get_package_share_directory('autonomy_park_viz'), 'param', 'park_geometry.yaml')],
            output='screen'
        ),
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', os.path.join(get_package_share_directory('autonomy_park_viz'), 'rviz', 'apark_herding.rviz')]
        )
    ])