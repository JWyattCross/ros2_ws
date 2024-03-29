from setuptools import setup

package_name = 'vehicle_position_checker'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='wyatt',
    maintainer_email='wyatt@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'vehicle_positon_checker_node=vehicle_position_checker.vehicle_position_checker:main'
        ],
    },
)
