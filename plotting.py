import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Read data from CSV file
df = pd.read_csv("a_NO-DELETE-Simulation_2024-02-25_13-50-01/target1_vel_hol.csv")

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
