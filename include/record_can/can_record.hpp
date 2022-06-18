#include <rclcpp/rclcpp.hpp>

#include <ichthus_msgs/msg/common.hpp>

#include <memory>

namespace ichthus
{

class CANRecorder : public rclcpp::Node
{
  private:
    rclcpp::Publisher<ichthus_msgs::msg::Common>::SharedPtr vel_pub;
    rclcpp::Publisher<ichthus_msgs::msg::Common>::SharedPtr ang_pub;

    rclcpp::Subscription<ichthus_msgs::msg::Common>::SharedPtr ang_sub;
    rclcpp::Subscription<ichthus_msgs::msg::Common>::SharedPtr vel_sub;

  public:
    explicit CANRecorder(const rclcpp::NodeOptions &);
    ~CANRecorder() override;

    void spd_CB(const ichthus_msgs::msg::Common::SharedPtr);
    void ang_CB(const ichthus_msgs::msg::Common::SharedPtr);
};

}
