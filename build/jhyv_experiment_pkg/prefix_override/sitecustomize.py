import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/wyatt/ros2_ws/install/jhyv_experiment_pkg'
