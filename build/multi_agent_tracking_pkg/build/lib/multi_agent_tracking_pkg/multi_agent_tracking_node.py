#imports. Note, other files in folder must be refrenced with pkg_name.file_name
import math
import numpy as np
import rclpy
from geometry_msgs.msg import PoseStamped, Twist
from multi_agent_tracking_pkg.simulation import Config, Simulation
from rclpy.node import Node
from tf_transformations import euler_from_quaternion


class PubNode(Node): #this is the main method of the function where all the ros publishers/subscribers are created
    def __init__(self):
        super().__init__('multi_agent_tracking_node') #node name, must match filename

        #create parameters for variables
        self.declare_parameter('num_agents', 2)
        #self.declare_parameter('target_initial_pos', [15, 15, 15])     #pass this on first iteration of function
        #final_time = 60        #remove so the simulation can be started and let run
        self.declare_parameter('dt', 0.01)
        self.declare_parameter('k1', 10)
        self.declare_parameter('pinning_vector', [1, 1, 1])
        self.declare_parameter('edge_set', [(1,2), (2,1), (1,3), (3,1), (2,3), (3,2)])

        #get parameters
        self.dt = self.get_parameter('dt').value
        #self.final_time = self.get_parameter('final_time').value
        self.k1 = self.get_parameter('k1').value
        self.num_agents = self.get_parameter('num_agents').value
        #self.target_initial_pos = self.get_parameter('target_initial_pos').value
        self.pinning_vector = self.get_parameter('pinning_vector').value
        self.edge_set = self.get_parameter('edge_set').value
        
        #create config and simulation using provided values
        self.config = Config(self.dt, self.final_time, (self.k1), self.num_agents, self.target_initial_pos, self.pinning_vector, self.edge_set)
        self.simulation = Simulation(self.config) #create sim with config

        #Robot namespaces
        '''AP robot names:
            /j100_0572
            /a200_0706 
            /a200_0708
            /go1_0153  #small dog with blue parts
            /go1_0154
            /go1_0155
        no trailing '/' as it is concatenated in each pub/sub creation line below already'''
        self.agent_name = 'go1_0153'
        self.target_name = 'go1_0154'

        #publish velocity (linear x and anglular z)
        self.agent1_vel_pub = self.create_publisher(Twist, self.agent_name + '/cmd_vel', 10)
        self.target1_vel_pub = self.create_publisher(Twist, self.target_name + '/cmd_vel', 10)

        #subscribe to real-world robot position
        self.agent1_pos_sub = self.create_subscription(PoseStamped, self.agent_name + '/pose', self.agent1_pos_callback, 10)
        self.target1_pos_sub = self.create_subscription(PoseStamped, self.target_name + '/pose', self.target1_pos_callback, 10)


        #create timer using dt from parameters
        self.timer = self.create_timer(self.dt, self.update_motion)
        self.i = 0 #this is a counter used to track the number of times the simulation has been run. it can be used if you need to track elapsed time


        #flags to make sure the program does not start with invalid values
        self.real_pos_agent1 = None
        self.real_pos_target1 = None
        self.First = True
        self.no_repeat = False

        self.agent1_vel = 0.0 #set initial velocity to zero
        self.target1_vel = 0.0


    def agent1_pos_callback(self, msg): #get real positions and update sim. This runs whenever a postion is revieved to update our position array
        self.real_pos_agent1 = np.array([msg.pose.position.x, msg.pose.position.y])
        self.agent1_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        _, _, self.agent1_yaw = euler_from_quaternion(self.agent1_heading_list)
        self.get_logger().info(f'Agent1 position:  [{msg.pose.position.x}, {msg.pose.position.y}]')

    def target1_pos_callback(self, msg):
        self.real_pos_target1 = np.array([msg.pose.position.x, msg.pose.position.y])
        self.target1_heading_list = [msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w]
        _, _, self.target1_yaw = euler_from_quaternion(self.target1_heading_list)
        self.get_logger().info(f'Target1 position: [{msg.pose.position.x}, {msg.pose.position.y}]')

    def update_motion(self):
        self.no_repeat = False
        if self.real_pos_agent1 is None:
            self.get_logger().info("Agent position is missing. Skipping update.")
            self.no_repeat = True
        
        if self.real_pos_target1 is None:
            self.get_logger().info("Target position is missing. Skipping update.")
            self.no_repeat = True

        if self.no_repeat: #lets me see what is missing using log messages, and publishes last velocity, default is 0
            #self.pub_lin_vel(self.agent1_vel_pub, self.agent1_vel)
            #self.pub_lin_vel(self.target1_vel_pub, self.target1_vel)
            return
        
        if self.First: #give initial positions to simulation
            self.config.target_initial_pos = self.real_pos_target1 #i think something along these lines could work, but i am not sure.
            #it would probably be safer to create another function in simulation.py and call that to give the initial positions
            #the following commented lines are how i did it
            
            #self.simulation.target.pass_initial_pos(self.real_pos_target1)
            #self.simulation.agent.pass_initial_pos(self.real_pos_agent1)
            self.First = False
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
        self.agent1_vel = self.convert_and_publish_velocity(self.agent1_vel_pub, self.agent1_vel_hol, 0.5, self.agent1_yaw)
        self.target1_vel = self.convert_and_publish_velocity(self.target1_vel_pub, self.target1_vel_hol, 0.2, self.target1_yaw)


        self.get_logger().info(f'\n') #empty comment to seperate steps in console window
        self.i += 1 #next time step
        self.real_pos_agent1 = None   #zero out variables to check for when the robots are off
        self.real_pos_target1 = None

    def convert_and_publish_velocity(self, publisher, velocity_hol, v_max, yaw): #publish the vel commands as a twist message
        #this converts the [dx,dy] vel vector to a linear component and angular component
        v_lin = np.linalg.norm(velocity_hol) #take the norm for the linear component
        atan2_angle = np.arctan2((velocity_hol[1]/v_lin), (velocity_hol[0]/v_lin)) #atan2 for the amount to turn from x axis. this is not the correct heading, do not directly publish this value or things will not work.
        
        if math.isnan(v_lin) or math.isnan(atan2_angle): #check if our values are divide by 0 errors and skip update
            return

        v_ang = atan2_angle - yaw #subtract current heading

        if v_ang > 0: #wrap angle so it stays between -pi to pi
            while v_ang > np.pi:
                v_ang -= 2*np.pi
        else:
            while v_ang < -np.pi:
                v_ang += 2*np.pi

        v_ang = -0.8*v_ang #coefficient is a gain so we dont do 360deg rotations instantly. negative worked best but i need to investigate further.

        if v_lin > v_max: #cap linear speed so we don't tell the dogs to run too fast
            v_lin = v_max
        
        self.get_logger().info(f'Publishing Vel Hol: {velocity_hol}')
        self.get_logger().info(f'Publishing lin,ang: {v_lin}, {v_ang}')

        twist_msg = Twist() #create twist message to pack data into to publish
        twist_msg.linear.x = v_lin
        twist_msg.angular.z = v_ang

        publisher.publish(twist_msg) #publish twist message
        return v_lin #return velocity so it can be used to keep the robot moving when position has not been updated. not implemented yet.
    
    def pub_lin_vel(self, publisher, velocity): #this is supposed to publish a linear velocity only as a twist message. it will be used to make the robots keep moving when the gps does not send the position and the simulation cannot be run since it depends on n current gps values. not implemnted yet.
        self.get_logger().info(f'Publishing Last linear vel: {velocity}')
        twist_msg = Twist()
        twist_msg.linear.x = velocity
        publisher.publish(twist_msg)


#ros2 boilerplate, make sure pub_node matches the main function above
def main(args=None):
    rclpy.init(args=args)
    pub_node = PubNode()
    rclpy.spin(pub_node)
    pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


#---------------------------------------------------------------------

'''
from simulation import Simulation
from results import show_results
from simulation import Config
import numpy as np

if __name__ == '__main__':
    num_agents = 3
    target_initial_pos = np.array([15, 15, 15])
    final_time = 60
    time_step_delta = 0.01
    k1 = 10
    pinning_vector = [1, 1, 1]
    edge_set = [(1,2), (2,1), (1,3), (3,1), (2,3), (3,2)]

    config = Config(time_step_delta, final_time, (k1), num_agents, target_initial_pos, pinning_vector, edge_set)
    simulation = Simulation(config)
    show_results(simulation)
'''