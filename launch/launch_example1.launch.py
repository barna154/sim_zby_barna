from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sim_zby_barna',
            executable='jelgen',
        ),

        Node(
            package='sim_zby_barna',
            executable='osszeg',
        ),
    ])
