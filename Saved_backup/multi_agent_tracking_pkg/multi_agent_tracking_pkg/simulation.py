from multi_agent_tracking_pkg.entity import Target, Agent
import numpy as np

class Config:
    def __init__(self, time_step_delta, final_time, k, num_agents, target_initial_pos, pinning_vector, edge_set):
        self.time_step_delta = time_step_delta
        self.final_time = final_time
        self.time_steps = int(final_time / time_step_delta)
        self.k = k
        self.target_initial_pos = target_initial_pos
        self.num_agents = num_agents
        self.pinning_vector = pinning_vector
        self.edge_set = edge_set

class Simulation:
    def __init__(self, config):
        self.config = config
        self.target = None
        self.agents = []
        self.initialize()
        self.run()

    def initialize(self):
        theta = np.linspace(0, 2 * np.pi, self.config.num_agents, endpoint=False)
        positions = np.column_stack([2.5 * np.cos(theta), 2.5 * np.sin(theta), np.zeros(self.config.num_agents)])
        self.target = Target(self.config.target_initial_pos, self.config)
        self.agents = [Agent(positions[i], self.config, self.target) for i in range(self.config.num_agents)]

        for i, j in self.config.edge_set:
            self.agents[j-1].neighbors.append(self.agents[i-1])

        for i, agent in enumerate(self.agents):
            agent.linked_to_target = bool(self.config.pinning_vector[i])

    def update(self, step):
        self.target.dynamics(step)
        for agent in self.agents:
            agent.dynamics(step)

    def integrate(self, step):
        self.target.integrate(step)
        for agent in self.agents:
            agent.integrate(step)

    def run(self):
        for step in range(1, self.config.time_steps):
            self.update(step)
            self.integrate(step)