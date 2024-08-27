import numpy as np

class Entity:
    def __init__(self, initial_pos, config):
        self.positions = np.zeros((3, config.time_steps))
        self.velocities = np.zeros((3, config.time_steps))
        self.positions[:, 0] = initial_pos
        self.time_step_delta = config.time_step_delta

    def integrate(self, step):
        self.positions[:, step] = self.positions[:, step-1] + self.time_step_delta * self.velocities[:, step]
        
class Agent(Entity):
    def __init__(self, initial_pos, config, target):
        super().__init__(initial_pos, config)
        self.target = target
        self.tracking_error = np.zeros((3, config.time_steps))
        self.neighbors = []
        self.linked_to_target = False
        self.k1 = config.k

    def controller(self, step):
        self.tracking_error[:, step-1] = self.target.positions[:, step-1] - self.positions[:, step-1]
        return self.k1*(np.sum([(neighbor.positions[:, step-1] - self.positions[:, step-1]) for neighbor in self.neighbors], axis=0) + self.linked_to_target*self.tracking_error[:, step-1])

    def dynamics(self, step):
        self.velocities[:, step] = self.controller(step)

class Target(Entity):
    def dynamics(self, step):
        x, y, z = self.positions[:, step - 1]
        self.velocities[:, step] = np.array([-5 * y, x, -0.1 * z])