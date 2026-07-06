#include <eigen_and_launch_example/joint_angle_publisher.h>

JointAnglePublisher::JointAnglePublisher() : Node("joint_angle_publisher")
{
    // create publisher object
    publisher_ = this->create_publisher<eigen_and_launch_example::msg::JointAngleStamped>("/joint_angle", 10);
}

void JointAnglePublisher::publishJointAngle(float angle)
{
    // assign angle to message object
    msg_.theta = angle;

    // the header file
    msg_.header.stamp = this->get_clock()->now();

    // publish message
    publisher_->publish(msg_);
}

int main(int argc, char * argv[])
{
    // initialize the node
    rclcpp::init(argc, argv);

    // create instance of the class
    auto node = std::make_shared<JointAnglePublisher>();

    // Set loop rate
    rclcpp::Rate rate = rclcpp::Rate(1); // 1 Hz

    // MAIN LOOP
    while (rclcpp::ok())
    {
        // loop from 0 to 360 degrees
        for (int i = 0; i < 360; i++)
        {
            node->publishJointAngle(i*M_PI/180.0);
            rclcpp::spin_some(node); // updates publishers and subscribers
            rate.sleep();
        }
    }
    rclcpp::shutdown();
    return 0;

}
