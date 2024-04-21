import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist
from std_msgs.msg import Float64MultiArray
import numpy as np
from herding_v1_package.simulation import Simulation, Agent, Target, Config
import os
import csv
from datetime import datetime
import math

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

        #goal position in autonomy park frame
        self.goal_pos = np.array([0.0, 0.0])
        
        # Define parameters
        self.declare_parameter('dt', 0.1)
        self.declare_parameter('k', [300.0, 2.0])   #crank k up for the demo. for proportional control
        #k is saved as a python list. that way i can add k1, k2 ... without ading varaibles
        self.declare_parameter('ang', 3.0) #tune this value as needed, controls the speed that the target travles around the circle

        # Get parameters
        self.dt = self.get_parameter('dt').value
        self.k = self.get_parameter('k').value
        self.ang = self.get_parameter('ang').value
        
        self.config = Config(self.dt, self.k, self.ang) #set time step and proportional gain for sim
        self.simulation = Simulation(self.config) #create sim with config

        #Robot namespaces
        #/j100_0572/
        self.agent_name = '/a200_0706' #no trailing /
        self.target_name = '/a200_0708'

        #publish velocity (anglular and linear)
        #COMMENT FOR TESTING
        self.agent1_vel_pub = self.create_publisher(Twist, self.agent_name + '/cmd_vel', 10)
        self.target1_vel_pub = self.create_publisher(Twist, self.target_name + '/cmd_vel', 10)

        #subscribe to robot position
        self.agent1_pos_sub = self.create_subscription(PoseStamped, self.agent_name + '/pose', self.agent1_pos_callback, 10)
        self.target1_pos_sub = self.create_subscription(PoseStamped, self.target_name + '/pose', self.target1_pos_callback, 10)

        #timer
        self.timer = self.create_timer(self.dt, self.update_motion)
        self.i = 0

        #flags to make sure the program does not start with invalid values
        self.real_pos_agent1 = None
        self.real_pos_target1 = None
        self.First = True

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

        self.last_target = None
        self.last_agent = None

    def agent1_pos_callback(self, msg): #get real positions and update sim. This runs whenever a postion is revieved to update our position array
        self.real_pos_agent1 = np.array([msg.pose.position.x, msg.pose.position.y])

        if self.real_pos_agent1 is None:
            if self.last_agent is None:
                return
            else:
                self.real_pos_agent1 = self.last_agent
                self.get_logger().info("Using last agent position")
                return
        self.get_logger().info(f'Agent1 position:  [{msg.pose.position.x}, {msg.pose.position.y}]')

    def target1_pos_callback(self, msg):
        self.real_pos_target1 = np.array([msg.pose.position.x, msg.pose.position.y])

        if self.real_pos_target1 is None:
            if self.last_target is None:
                return
            else:
                self.real_pos_target1 = self.last_target
                self.get_logger().info("Using last target position")
                return
            
        self.get_logger().info(f'Target1 position: [{msg.pose.position.x}, {msg.pose.position.y}]')

    def update_motion(self):
        if self.real_pos_agent1 is None:
            self.get_logger().info("Agent position is missing. Skipping update.")
            return
        
        if self.real_pos_target1 is None:
            self.get_logger().info("Target position is missing. Skipping update.")
            return
        
        #give initial positions to simulation
        if self.First:
            self.simulation.target.pass_initial_pos(self.real_pos_target1)
            self.simulation.agent.pass_initial_pos(self.real_pos_agent1)
            self.First = False

            self.simulation.target.give_goal_pos(self.goal_pos)
            self.simulation.agent.give_goal_pos(self.goal_pos)
            return

        #give real positions to simulation
        self.simulation.target.pull(self.real_pos_target1)
        self.simulation.agent.pull(self.real_pos_agent1)

        #get velicities from simulation
        #_hol refers to holonomic, dx and dy components provided. need to convert to linear and angular
        self.target1_vel_hol = self.simulation.target.push(self.i)
        self.agent1_vel_hol, self.tracking_error = self.simulation.agent.push(self.i)

        self.get_logger().info(f'Target vel_hol:       {self.target1_vel_hol}')
        self.get_logger().info(f'Agent vel_hol:        {self.agent1_vel_hol}')
        self.get_logger().info(f'Agent tracking error: {self.tracking_error}')


        #publish velocities
        self.convert_and_publish_velocity(self.agent1_vel_pub, self.agent1_vel_hol, 0.5)
        self.convert_and_publish_velocity(self.target1_vel_pub, self.target1_vel_hol, 0.1)
        
        #save holonomic velocity commands to csv
        self.agent1_vel_hol_csv.writerow([self.i, self.agent1_vel_hol[0], self.agent1_vel_hol[1]])
        self.target1_vel_hol_csv.writerow([self.i, self.target1_vel_hol[0], self.target1_vel_hol[1]])
        #save tracking error to csv
        self.track_error_csv.writerow([self.i, self.tracking_error[0], self.tracking_error[1]])

        self.get_logger().info(f'\n') #empty comment to seperate steps
        self.i += 1 #next time step
        self.real_pos_agent1 = None   #zero out variables to check for when the robots are off
        self.real_pos_target1 = None

    def convert_and_publish_velocity(self, publisher, velocity_hol, v_max): #publish the vel commands as a twist message
        #this converts the [dx,dy] vel vector to a linear component and angular component
        v_lin = np.linalg.norm(velocity_hol)
        v_ang = np.arctan2((velocity_hol[1]/v_lin), (velocity_hol[0]/v_lin))
        
        if math.isnan(v_lin) or math.isnan(v_ang):
            return
        
        if v_lin > v_max:
            v_lin = v_max
        
        self.get_logger().info(f'Publishing Vel Hol: {velocity_hol}')
        self.get_logger().info(f'Publishing lin,ang: {v_lin}, {v_ang}')

        twist_msg = Twist()
        twist_msg.linear.x = v_lin
        twist_msg.angular.z = v_ang
        #TESTING, using sim that takes in deltx and delty, not ang/lin
        #twist_msg.linear.x = v_max*velocity_hol[0]/v_lin
        #twist_msg.linear.y = velocity_hol[1]
        publisher.publish(twist_msg)


def main(args=None):
    rclpy.init(args=args)
    herding_pub_node = HerdingNode()
    rclpy.spin(herding_pub_node)
    herding_pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
