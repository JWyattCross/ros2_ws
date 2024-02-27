import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist
from std_msgs.msg import Float64MultiArray
import numpy as np
from herding_v1_package.simulation import Simulation, Agent, Target, Config
import os
import csv
from datetime import datetime

def create_directory_with_timestamp():
    # Get current date and time
    now = datetime.now()
    timestamp = now.strftime("%Y-%m-%d_%H-%M-%S")

    # Create directory with timestamp
    directory_name = f"Simulation_{timestamp}"
    os.makedirs(directory_name)

    return directory_name

class HerdingNode(Node): #create package
    def __init__(self):
        super().__init__('herding_pub_node') #specify node name
        self.dt = 0.1 #0.001
        self.k = 1

        self.config = Config(self.dt, self.k) #set time step and proportional gain for sim
        self.simulation = Simulation(self.config) #create sim with config

        #publish velocity (anglular and linear)
        #COMMENTED FOR TESTING
        #self.agent1_vel_pub = self.create_publisher(Twist, '/a200_0708/cmd_vel', 10)
        #self.target1_vel_pub = self.create_publisher(Twist, '/a200_0706/cmd_vel', 10)

        #publish simulation values
        self.tracking_pub = self.create_publisher(Float64MultiArray, '/tracking_error', 10)
        #self.dnn_weight_pub = self.create_publisher(Float64MultiArray, '/dnn_weights', 10) #unused in current form

        #subscribe to robot position
        self.agent1_pos_sub = self.create_subscription(PoseStamped, '/a200_0708/pose', self.agent1_pos_callback, 10)
        self.target1_pos_sub = self.create_subscription(PoseStamped, '/a200_0708/pose', self.target1_pos_callback, 10)

        #timer
        self.timer = self.create_timer(self.dt, self.update_motion)
        self.i = 0

        self.real_pos_agent1 = None
        self.real_pos_target1 = None

        #csv saving code ---
        self.directory = create_directory_with_timestamp() #create a directory in /ros2_ws folder to hold saved values
        #create csv files and add headers:
        self.agent1_vel_hol_csv = csv.writer(open(os.path.join(self.directory, "agent1_vel_hol.csv"), mode='w', newline='')) #create and open file
        self.agent1_vel_hol_csv.writerow(['Timestep', 'dx', 'dy']) #header
        self.target1_vel_hol_csv = csv.writer(open(os.path.join(self.directory, "target1_vel_hol.csv"), mode='w', newline=''))
        self.target1_vel_hol_csv.writerow(['Timestep', 'dx', 'dy'])
        self.track_error_csv = csv.writer(open(os.path.join(self.directory, "tracking_error.csv"), mode='w', newline=''))
        self.track_error_csv.writerow(['Timestep', 'x error', 'y error'])
        #self.dnn_weights_csv = csv.writer(open(os.path.join(self.directory, "dnn_weights.csv"), mode='w', newline=''))
        #self.dnn_weights_csv.writerow(['Timestep', 'x error', 'y error'])

    def agent1_pos_callback(self, msg): #get real positions and update sim. This runs whenever a postion is revieved to update our position array
        self.real_pos_agent1 = np.array([[msg.pose.position.x],[msg.pose.position.y]])
        #self.get_logger().info(f'Agent1 position: [{msg.pose.position.x}, {msg.pose.position.y}]')
        #self.get_logger().info(f'Agent1 numpy position: [{self.real_pos_agent1[0][0]}, {self.real_pos_agent1[1][0]}]')

    def target1_pos_callback(self, msg):
        self.real_pos_target1 = np.array([[msg.pose.position.x],[msg.pose.position.y]])
        #self.get_logger().info(f'Target1 position: [{msg.pose.position.x}, {msg.pose.position.y}]')

    def update_motion(self):
        if self.real_pos_agent1 is None or self.real_pos_target1 is None:
            self.get_logger().info("Agent or target position is missing. Skipping update.")
            return
        
        #give real positions to simulation
        self.simulation.target.pull(self.real_pos_target1, self.i)
        self.simulation.agent.pull(self.real_pos_agent1, self.i)

        #get velicities from simulation
        #_hol refers to holonomic, dx and dy components provided. need to convert to linear and angular
        self.target1_vel_hol = self.simulation.target.push(self.i)
        self.agent1_vel_hol, self.tracking_error = self.simulation.agent.push(self.i)

        #publish velocities
        #self.convert_and_publish_velocity(self.agent1_vel_pub, self.agent1_vel_hol)
        #self.convert_and_publish_velocity(self.target1_vel_pub, self.target1_vel_hol)
        
        #save holonomic velocity commands to csv
        self.agent1_vel_hol_csv.writerow([self.i, self.agent1_vel_hol[0], self.agent1_vel_hol[1]])
        self.target1_vel_hol_csv.writerow([self.i, self.target1_vel_hol[0], self.target1_vel_hol[1]])
        #save tracking error to csv
        self.track_error_csv.writerow([self.i, self.tracking_error[0], self.tracking_error[1]])

        self.i += 1 #next time step

    def convert_and_publish_velocity(self, publisher, velocity_hol): #publish the vel commands as a twist message
        #this converts the [dx,dy] vel vector to a linear component and angular component
        v_lin = np.linalg.norm(velocity_hol)
        v_ang = np.arctan2(velocity_hol[1]/v_lin, velocity_hol[0]/v_lin)

        twist_msg = Twist()
        twist_msg.linear.x = v_lin
        twist_msg.angular.x = v_ang
        publisher.publish(twist_msg)

def main(args=None):
    rclpy.init(args=args)
    herding_pub_node = HerdingNode()
    rclpy.spin(herding_pub_node)
    herding_pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
