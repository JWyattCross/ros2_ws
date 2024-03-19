import numpy as np

class Config:
    def __init__(self, dt, k):
        self.dt = dt
        self.k = k

class Simulation:
    def __init__(self, config):
        self.config = config
        self.agent, self.target = self.initialize()

    def initialize(self):
        target = Target(self.config)
        agent = Agent(self.config, target)
        return agent, target

class Entity:
    def __init__(self, config):
        self.dt = config.dt
        self.k = config.k

    def pass_initial_pos(self, initial_pos): #initial_pos needs to be a numpy array shaped like [x,y]
        self.position = initial_pos

    def pull(self, ros_pos_node): #ros_pos_node needs to be a numpy array shaped like [x,y]
        self.position_previous = self.position
        self.position = ros_pos_node
    
class Agent(Entity):
    def __init__(self, config, target):
        super().__init__(config)
        self.target = target
        self.tracking_error = np.array([])#np.array([,])

    def push(self, i):
        k1 = self.k
        #phi = DNN("stuff")     #new dnn script not done yet
        self.tracking_error = self.target.position - self.target.position_previous
        controller = k1*self.tracking_error #+ phi      #Proportional control
        
        #crank k1 up to get proportional control working for demo
        return controller, self.tracking_error  #these are both [,] filled with floats

class Target(Entity):
    def push(self, i):
        angular_velocity = 1 #tune this value as needed, controls the speed that the target travles around the circle. intuitively, this feels high
        radius = self.position[0] #target will move in circle around origin. This means don't set the robot near the drone landing pads
        omega_t = angular_velocity * self.dt * (i - 1)
        dx = -radius * angular_velocity * np.sin(omega_t)
        dy = radius * angular_velocity * np.cos(omega_t)
        return np.array([dx, dy]) #this value is hollonomic. is converted to lin/ang components in ros node
        #these values are meaningless and need to be scaled/capped to work on real robots
    
    #target goes in circle of radius equal to initial position? on line 44
    #agent starts in center and follows it