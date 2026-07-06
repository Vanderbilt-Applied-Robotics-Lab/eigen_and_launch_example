#include <eigen_and_launch_example/simple_robot.h>

SimpleRobot::SimpleRobot(float link_length, float theta) : Node("simple_robot"), link_length_(link_length)
{
    // initialize ee location to theta = 0
    setJointAngle(theta);

    // create subscriber object
    subscriber_ = this->create_subscription<eigen_and_launch_example::msg::JointAngleStamped>("/joint_angle", 10, 
        std::bind(&SimpleRobot::jointAngleCallback, this, std::placeholders::_1));

    start_time_ = this->get_clock()->now();
}

void SimpleRobot::setJointAngle(float theta)
{
    joint_angle_ = theta;

    // update the rotation matrix
    rotation_matrix_ << std::cos(joint_angle_), -std::sin(joint_angle_), std::sin(joint_angle_), std::cos(joint_angle_);
    
    // ee location when theta = 0
    Eigen::Vector2d unrotated_ee_location_;
    unrotated_ee_location_ << link_length_, 0;
    
    // ee location at theta using matrix multiplication
    ee_location_ =  rotation_matrix_*unrotated_ee_location_;
}

void SimpleRobot::printEELocation()
{
    RCLCPP_INFO(this->get_logger(),"EE location. x: %0.2f [m], y: %0.2f [m]", ee_location_[0], ee_location_[1]); 
}

void SimpleRobot::jointAngleCallback(const eigen_and_launch_example::msg::JointAngleStamped & msg)
{
    // get send time (measured since start of program)
    rclcpp::Time message_send_time = msg.header.stamp;
    double send_time = ( message_send_time- start_time_).seconds();
    RCLCPP_INFO(this->get_logger(),"Received joint angle %0.2f [rad] sent at time %0.2f [sec]", msg.theta, send_time); 
    setJointAngle(msg.theta);
    printEELocation();
}

int main(int argc, char * argv[])
{
    // initialize the node
    rclcpp::init(argc, argv);

    // parse launch arguments
    float link_length = std::stof(argv[1]);
    float theta = std::stof(argv[2]);

    // create instance of class
    auto node = std::make_shared<SimpleRobot>(link_length, theta);

    // loop and update publishers and subscribers
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}
