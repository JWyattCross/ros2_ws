import sys
import os
from launch import LaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from ament_index_python.packages import get_package_share_directory

'''AP robot names:
    /j100_0572
    /a200_0706 
    /a200_0708
    /go1_0153  #small dog with blue parts
    /go1_0154
    /go1_0155
    /go1_0165/cmd_vel
    '''

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='matplotlib_sim',
            executable='matplotlib_sim_node',
            name='matplotlib_sim',
        ),
        # # Target 1 and Herding Control
        # Node(
        #     package='single_integrator_agent',
        #     namespace='go1_0154',
        #     executable='single_int_node',
        #     name='single_integrator_agent_1',
        #     parameters=[
        #         {'x_init': -5.0},
        #         {'y_init': 0.0},
        #         {'name': 'go1_0154'},
        #     ],
        # ),
        # Node(
        #     package='herding_control',
        #     namespace='go1_0154',
        #     executable='herding_target_node',
        #     name='herding_target_node_1',
        #     output='screen',
        #     parameters=[
        #         {'dt': 0.1},
        #         {'MAX_SPEED_MS': 1.0},
        #         {'LEVY_WALK_PARAM': 20.0},
        #         {'BIG_BAD_WOLF': 'go1_0165'},   #remmeber to change me!!!!!!!!!!!!
        #     ],
        # ),
        # Agent and Herding Control
        # Node(
        #     package='single_integrator_agent',
        #     namespace='go1_0165',
        #     executable='single_int_node',
        #     name='single_integrator_agent_2',
        #     parameters=[
        #         {'x_init': 0.0},
        #         {'y_init': -2.0},
        #         {'name': 'go1_0153'},
        #     ],
        # ),
        Node(
            package='herding_control',
            namespace='go1_0165',
            executable='herding_agent_node',
            name='herding_agent_node_1',
            output='screen',
            parameters=[
                {'dt': 0.1},
                {'MAX_SPEED_MS': 3.0},
            ],
        ),


    ])

#need to run 
#ros2 run joy joy_node
#in a terminal window with contorller connnected