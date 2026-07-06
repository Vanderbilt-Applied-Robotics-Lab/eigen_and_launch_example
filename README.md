# eigen_and_launch_example
Example of using Eigen (C++ linear algebra library), launch files, and custom message types. Builds on [publisher_subscriber_example](https://github.com/Vanderbilt-Applied-Robotics-Lab/publisher_subscriber_example) in the following ways:
* All `std::array`'s are now `Eigen::Vector2d`'s when applicable
* Uses `Eigen::Matrix2d` to rotate the link length 
* Added a custom message type for the angle
* Added launch arguments for the link length and initial joint angle
* Changes printing to ROS 2 logging

## Downloading Code
1. Navigate to examples workspace source folder: `cd ~/workspaces/examples_ws/src`
2. Download code: `git clone https://github.com/Vanderbilt-Applied-Robotics-Lab/eigen_and_launch_example.git`

## Compiling Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Compile the code: `colcon build`

## Running Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Source the code: `source install/setup.bash`
3. Run simple robot: `ros2 launch lecture3_example rotate_vector.launch.yaml <arg name>:=<value>`

The launch arguments are:

| arg name | default | description |
|----------|---------|-------------|
| `link_length` | `1.0` | The length of the robot's link [m] |
| `theta` | `0.0` | Initial angle of the robot's joint [rad] | 
