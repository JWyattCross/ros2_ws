import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

'''
Python implementation of:
    Indirect Regulation/Control/Herding by Jhyv Nicolas Philor
'''

class HerdingSimulation:
    def __init__(self, g, k1, k2, target_initial, agent_initial, target_goal, dt, total_time):
        '''Gain Conditions [(10) & (11)]'''
        self.g = g
        self.k1 = k1
        self.k2 = k2

        #Simulation parameters
        self.dt = dt
        self.total_time = total_time
        self.steps = int(self.total_time / self.dt)

        #Set intitial states as float numpy arrays
        self.target = np.asarray(target_initial, dtype=float)   #target position (expressed as "x" in paper)
        self.agent = np.asarray(agent_initial, dtype=float)     #tracking agent position (expressed as "y" in paper)
        self.target_goal = np.asarray(target_goal, dtype=float) #goal location position (expressed as "x_g" in paper)
        
        #Init arrays to save position history for plotting
        self.target_history = [self.target.copy()]
        self.agent_history = [self.agent.copy()]


    def step(self):
        #Perform one simulation step
        #Note, numbers in () correspond to equations in paper
        
        '''Error Systems [(3),(4),(7) & (8)]'''
        #(3) target regulation error
        ex = self.target - self.target_goal
        
        '''Virtual Controller/Backstepping Controller, yd [(6)]'''
        #(6) desired target trajectory
        yd = self.target + (1/self.g)*(self.k1*ex)
        
        #(4) backstepping error
        ey = yd - self.agent
            
        '''Controller, u [(9)]'''
        #(9) control input
        u = self.k2*ey - ( (self.k1**2 / self.g) + self.g )*ex
        
        '''Update Dynamics [(1) & (2)]'''
        #(2) target update plant
        dx = self.g*(self.target - self.agent)
        #add displacement to currnet position
        self.target += dx * self.dt
        
        #(1) agent update plant
        #add displacement to currnet position
        self.agent += u * self.dt
        
        #save history for plotting
        self.target_history.append(self.target.copy())
        self.agent_history.append(self.agent.copy())
    
    def animate(self):
        # Prepare the figure and axis
        fig, ax = plt.subplots(figsize=(8, 6))
        
        # Initialize plot elements
        target_line, = ax.plot([], [], 'r-', label='Target Trajectory')
        agent_line, = ax.plot([], [], 'b-', label='Tracking Agent Trajectory')
        
        # Target and agent points
        target_point, = ax.plot([], [], 'ro', label='Target')
        agent_point, = ax.plot([], [], 'bo', label='Tracking Agent')
        
        # Goal point
        ax.plot(self.target_goal[0], self.target_goal[1], 'g*', markersize=10, label='Goal')
        
        # Set up the axes
        ax.set_xlim(-10, 10)
        ax.set_ylim(-10, 10)

        ax.set_title(' Indirect Regulation/Control/Herding Simulation')
        ax.set_xlabel('x Position')
        ax.set_ylabel('y Position')
        ax.legend()
        ax.grid(True)
        
        # Animation update function
        def update(frame):
            # Run a simulation step
            if frame < self.steps:
                self.step()
            
            # Update trajectories
            target_hist = np.array(self.target_history)
            agent_hist = np.array(self.agent_history)
            
            target_line.set_data(target_hist[:, 0], target_hist[:, 1])
            agent_line.set_data(agent_hist[:, 0], agent_hist[:, 1])
            
            # Update current positions
            target_point.set_data([target_hist[-1, 0]], [target_hist[-1, 1]])
            agent_point.set_data([agent_hist[-1, 0]], [agent_hist[-1, 1]])
            
            return target_line, agent_line, target_point, agent_point
        
        # Create animation
        anim = animation.FuncAnimation(
            fig, 
            update, 
            frames=self.steps + 50,  # Extra frames to show final position
            interval=50,  # 50 ms between frames
            blit=True
        )
        
        plt.show()

# Example usage
def main():
    #Create and run sim
    sim = HerdingSimulation(
        target_initial=[5, 5],
        agent_initial=[0.0, 3],     #These are x,y initial position vectors
        target_goal=[-3, -5],
        g=1.0,                       #Known constant that will eventually be a function
        k1=2.0,                         #Control gain  k1 > 1
        k2=3.0,                         #Control gain  k2 > g+k1
        dt=0.005,                      #Timestep (seconds)
        total_time=10,               #End the simulation after n seconds. Note, arrays are not preinitalized to final size, so you can more easily rip out the for loop and replace with while loop and exit conditons
    )

    #Animate sim
    sim.animate()

if __name__ == "__main__":
    main()