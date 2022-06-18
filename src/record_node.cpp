#include <rclcpp/rclcpp.hpp>
#include <memory>

#include "record_can/can_record.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<ichthus::CANRecorder>(
    rclcpp::NodeOptions()));

  rclcpp::shutdown();
  return 0;
}
