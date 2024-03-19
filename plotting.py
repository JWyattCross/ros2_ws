import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Read data from CSV file
df = pd.read_csv("Simulation_2024-03-19_14-37-25" + "/target1_vel_hol.csv") #folder name then it picks the file

# Extract time and velocity data
time = df['Timestep']
dx = df['dx'].values
dy = df['dy'].values

# Calculate magnitude of velocity vector
velocity_magnitude = np.linalg.norm([dx, dy], axis=0)
# Plot velocity magnitude against time
plt.plot(velocity_magnitude, marker='o', linestyle='-')
plt.title('Velocity Magnitude vs Time')
plt.xlabel('Time')
plt.ylabel('Velocity Magnitude')
plt.grid(True)
plt.show()
