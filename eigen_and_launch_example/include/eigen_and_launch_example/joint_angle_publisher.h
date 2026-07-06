#ifndef JOINT_ANGLE_PUBLISHER
#define JOINT_ANGLE_PUBLISHER

#include <array>
#include <cmath>
#include <rclcpp/rclcpp.hpp>
#include <eigen_and_launch_example/msg/joint_angle_stamped.hpp> // note the snake case

/**
 * publishes to the /joint_angle topic
 * Applied Robotics
 */
class JointAnglePublisher : public rclcpp::Node
{
public:
    /**
     * Constructor
     */
    JointAnglePublisher();

    /**
     * Default destructor
     */
    ~JointAnglePublisher() = default;

    /**
     * Publishes a specified joint angle
     * @param theta joint angle in radians
     */
    void publishJointAngle(float angle);

private:

    // publisher object
    rclcpp::Publisher<eigen_and_launch_example::msg::JointAngleStamped>::SharedPtr publisher_;

    // output message
    eigen_and_launch_example::msg::JointAngleStamped msg_;

};
#endif // JOINT_ANGLE_PUBLISHER