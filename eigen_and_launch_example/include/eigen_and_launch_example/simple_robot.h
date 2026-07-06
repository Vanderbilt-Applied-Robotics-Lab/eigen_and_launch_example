#ifndef SIMPLE_ROBOT
#define SIMPLE_ROBOT

#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <Eigen/Dense>
#include <eigen_and_launch_example/msg/joint_angle_stamped.hpp> // note the snake case

/**
 * Subscribes to the /joint_angle topic and updates the kinematics of a 1 DOF robot
 * Applied Robotics
 */
class SimpleRobot : public rclcpp::Node
{
public:
    /**
     * Constructor
     * @param link_length The length of a the link [m]
     * @param theta initial joint angle
     */
    SimpleRobot(float link_length, float theta);

    /**
     * Default destructor
     */
    ~SimpleRobot() = default;

    /**
     * Set the joint angle of the robot
     * @param theta joint angle in radians
     */
    void setJointAngle(float theta);

    /**
     * prints the x and y location of the robot's end-effector (EE)
     */
    void printEELocation();

private:
    /**
     * Callback for the /joint_angle topic
     * @param msg Reference to the incoming message object
     */
    void jointAngleCallback(const eigen_and_launch_example::msg::JointAngleStamped & msg);

    /**
     * Subscriber object for the /joint_angle topic 
     */
    rclcpp::Subscription<eigen_and_launch_example::msg::JointAngleStamped>::SharedPtr subscriber_;

    float link_length_;
    float joint_angle_;

    Eigen::Vector2d ee_location_;
    Eigen::Matrix2d rotation_matrix_; 

    rclcpp::Time start_time_;
};
#endif // SIMPLE_ROBOT