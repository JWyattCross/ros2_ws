from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, TimerAction

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
        # # Target 2 and Herding Control
        # Node(
        #     package='single_integrator_agent',
        #     namespace='sheep2',
        #     executable='single_int_node',
        #     name='single_integrator_agent_2',
        #     parameters=[
        #         {'x_init': 5.0},
        #         {'y_init': 0.0},
        #         {'name': 'sheep2'},
        #     ],
        # ),
        # Node(
        #     package='herding_control',
        #     namespace='sheep2',
        #     executable='herding_target_node',
        #     name='herding_target_node_2',
        #     output='screen',
        #     parameters=[
        #         {'dt': 0.1},
        #         {'MAX_SPEED_MS': 2.0},
        #         {'LEVY_WALK_PARAM': 3.0},
        #         {'BIG_BAD_WOLF': 'sheepdog'},
        #     ],
        # ),

        # # Target 3 and Herding Control
        # Node(
        #     package='single_integrator_agent',
        #     namespace='sheep3',
        #     executable='single_int_node',
        #     name='single_integrator_agent_3',
        #     parameters=[
        #         {'x_init': 4.0},
        #         {'y_init': 0.0},
        #         {'name': 'sheep3'},
        #     ],
        # ),
        # Node(
        #     package='herding_control',
        #     namespace='sheep3',
        #     executable='herding_target_node',
        #     name='herding_target_node_3',
        #     output='screen',
        #     parameters=[
        #         {'dt': 0.1},
        #         {'MAX_SPEED_MS': 2.0},
        #         {'LEVY_WALK_PARAM': 7.0},
        #         {'BIG_BAD_WOLF': 'sheepdog'},
        #     ],
        # ),
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

        TimerAction(
            period=1.0,  # Delay of 1 seconds. This helps prevent errors when topics are starting up.
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
        )


    ])

#need to run 
#ros2 run joy joy_node
#in a terminal window with contorller connnected