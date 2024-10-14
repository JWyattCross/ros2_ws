from launch import LaunchDescription
from launch_ros.actions import Node

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
                {'x_init': 0.0},
                {'y_init': 0.0},
                {'name': 'r1'},
            ],
        ),
        Node(
            package='herding_control',
            namespace='r1',
            executable='herding_control_node',
            name='herding_control_node_1',
            parameters=[
                {'name': 'r1'},
            ],
        ),
        # Repeat for additional agents as needed...
    ])
