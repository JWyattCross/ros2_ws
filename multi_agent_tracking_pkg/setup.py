from setuptools import find_packages, setup

package_name = 'multi_agent_tracking_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='wyatt',
    maintainer_email='jameswyattcross@hotmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'multi_agent_tracking_node = multi_agent_tracking_pkg.multi_agent_tracking_node:main'
        ],
    },
)
