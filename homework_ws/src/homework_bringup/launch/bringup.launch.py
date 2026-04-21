from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    detector_node = Node(
        package = 'robot_detector',
        executable = 'detector_node',
        name = 'detector_node',
    )

    decision_node = Node(
        package = 'robot_decision_n_vision',
        executable = 'decision_node',
        name = 'decision_node',
        parameters = [
            os.path.join(
                get_package_share_directory('homework_bringup'),
                'config',
                'decision_params.yaml'
            ),
            {'serial_port': LaunchConfiguration('serial')}
        ],
    )

    vision_node = Node(
        package = 'robot_decision_n_vision',
        executable = 'vision_node',
        name = 'vision_node',
        parameters = [
            os.path.join(
                get_package_share_directory('homework_bringup'),
                'config',
                'vision_params.yaml'
            ),
        ],
    )

    return LaunchDescription([
        detector_node,
        decision_node,
        vision_node
    ])