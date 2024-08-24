import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/wyatt/Documents/GitHub/ros2_ws/install/vehicle_position_checker'
