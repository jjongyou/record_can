#include <functional>

#include "record_can/can_record.hpp"

namespace ichthus
{

CANRecorder::CANRecorder(const rclcpp::NodeOptions & options)
: rclcpp::Node("CAN_Recorder", options)
{
  RCLCPP_INFO(this->get_logger(), "===Start CAN Recorder===");
  RCLCPP_INFO(this->get_logger(), "Create Pub & Sub");

  vel_pub = this->create_publisher<std_msgs::msg::Float64>("ref_vel", 1);
  ang_pub = this->create_publisher<std_msgs::msg::Float64>("ref_ang", 1);

  ang_sub = this->create_subscription<ichthus_msgs::msg::Common>(
    "cur_ang", 10, std::bind(&CANRecorder::ang_CB, this, std::placeholders::_1));
  vel_sub = this->create_subscription<ichthus_msgs::msg::Common>(
    "cur_vel", 10, std::bind(&CANRecorder::spd_CB, this, std::placeholders::_1));
}

CANRecorder::~CANRecorder()
{
}

void CANRecorder::spd_CB(ichthus_msgs::msg::Common::SharedPtr msg)
{
  std_msgs::msg::Float64 ref_vel;
  ref_vel.data = msg->data;
  vel_pub->publish(ref_vel);
}

void CANRecorder::ang_CB(ichthus_msgs::msg::Common::SharedPtr msg)
{
  std_msgs::msg::Float64 ref_ang;
  ref_ang.data = msg->data;
  ang_pub->publish(ref_ang);
}
} //namespace end
