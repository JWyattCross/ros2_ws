#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist
import matplotlib.pyplot as plt
from dataclasses import dataclass
import math

@dataclass
class Agent:
    name: str
    x: float
    y: float
    x_hist: list
    y_hist: list
    yaw: float
    velocity: float
    angular_velocity: float

class Conductor(Node):
    def __init__(self, agent_configs):
        super().__init__('conductor_node')

        # Define the agents and their positions (None means radial distribution)
        self.agent_configs = agent_configs

        self.num_agents = len(self.agent_configs)
        self.agents = []
        self.pose_pubs = []
        self.vel_subs = []

        # Setup agents with starting positions or radial defaults
        for i, (robot_ns, start_position) in enumerate(self.agent_configs):
            if start_position:  # Use provided start position
                start_x, start_y = start_position
            else:
                # Default to radially around origin
                angle = 2 * math.pi * i / self.num_agents
                start_x = 5 * math.cos(angle)
                start_y = 5 * math.sin(angle)

            # Create agent object with the specified or default start positions
            agent = Agent(robot_ns, start_x, start_y, [start_x], [start_y], 0.0, 0.0, 0.0)
            self.agents.append(agent)
            
            # Publisher for /pose topic under the specific namespace
            pose_pub = self.create_publisher(PoseStamped, f'{robot_ns}/pose', 10)
            self.pose_pubs.append(pose_pub)

            # Subscriber for /cmd_vel topic under the specific namespace
            vel_sub = self.create_subscription(Twist, f'{robot_ns}/cmd_vel', lambda msg, ns=robot_ns: self.cmd_vel_callback(msg, ns), 10)
            self.vel_subs.append(vel_sub)

        # Plotting setup
        self.BBox = [-10, 10, -10, 10]
        self.fig, self.ax = plt.subplots(figsize=(10, 10))
        self.agent_plots = []
        self.agent_hist_plots = []

        for _ in range(self.num_agents):
            agent_plot, = self.ax.plot([], [], 'ro', label="agent")
            agent_hist_plot, = self.ax.plot([], [], 'k,', label="agent path")
            self.agent_plots.append(agent_plot)
            self.agent_hist_plots.append(agent_hist_plot)

        self.ax.set_xlabel('Easting')
        self.ax.set_ylabel('Northing')
        self.ax.legend()
        self.ax.grid()
        self.ax.set_xlim(self.BBox[0], self.BBox[1])
        self.ax.set_ylim(self.BBox[2], self.BBox[3])
        self.ax.set_aspect('equal')

        # Timer to update positions and plot them
        time_period = 1/10
        self.timer = self.create_timer(time_period, self.update_plot)

    # Callback function for cmd_vel
    def cmd_vel_callback(self, msg, robot_ns):
        for agent in self.agents:
            if agent.name == robot_ns:
                agent.velocity = msg.linear.x
                agent.angular_velocity = msg.angular.z

    # Timer callback to update positions and plot
    def update_plot(self):
        for i, agent in enumerate(self.agents):
            # Update agent's position based on velocity and angular velocity
            delta_x = agent.velocity * math.cos(agent.yaw)
            delta_y = agent.velocity * math.sin(agent.yaw)
            agent.x += delta_x
            agent.y += delta_y
            agent.yaw += agent.angular_velocity

            # Update agent's history
            agent.x_hist.append(agent.x)
            agent.y_hist.append(agent.y)

            # Publish the updated pose
            self.publish_pose(agent, self.pose_pubs[i])

            # Collect data for plotting
            self.agent_plots[i].set_xdata(agent.x)
            self.agent_plots[i].set_ydata(agent.y)

            self.agent_hist_plots[i].set_xdata(agent.x_hist)
            self.agent_hist_plots[i].set_ydata(agent.y_hist)

        # Redraw plot
        self.fig.canvas.draw()
        self.fig.canvas.flush_events()

    # Function to publish pose
    def publish_pose(self, agent, publisher):
        pose_msg = PoseStamped()
        pose_msg.header.frame_id = agent.name
        pose_msg.pose.position.x = agent.x
        pose_msg.pose.position.y = agent.y
        pose_msg.pose.position.z = 0.0  # Assuming 2D movement for simplicity
        publisher.publish(pose_msg)

# Main entry point for the node
def main(args=None):
    rclpy.init(args=args)

    # Specify robot namespaces and their starting positions or None for radial distribution
    agent_configs = [
        ('go1_0153', (5, 7)),   # Blue robot at (5, 7)
        ('go1_0154', (2, 6)),   # Red robot at (2, 6)
        ('/j100_0572', None),   # Another robot radially distributed
        ('/a200_0706', None)    # Another robot radially distributed
    ]

    conductor = Conductor(agent_configs=agent_configs)

    try:
        rclpy.spin(conductor)
    except KeyboardInterrupt:
        pass

    conductor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
