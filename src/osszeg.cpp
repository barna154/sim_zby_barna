#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class SumTwoSines : public rclcpp::Node
{
public:
    SumTwoSines() : Node("osszeg")
    {
        RCLCPP_INFO(this->get_logger(), "Szinusz jelek összeadása");
        pub_ = this->create_publisher<std_msgs::msg::Float32>("osszeg", 10);
        sub1_ = this->create_subscription<std_msgs::msg::Float32>( "sine1", 10,std::bind(&SumTwoSines::callback1, this, std::placeholders::_1));
        sub2_ = this->create_subscription<std_msgs::msg::Float32>("sine2", 10,std::bind(&SumTwoSines::callback2, this, std::placeholders::_1));
        sum_ready_ = false;
    }

private:
    void callback1(const std_msgs::msg::Float32::SharedPtr msg)
    {
        val1_ = msg->data;
        sum_ready_ = true;
        publish_sum();
    }

    void callback2(const std_msgs::msg::Float32::SharedPtr msg)
    {
        val2_ = msg->data;
        sum_ready_ = true;
        publish_sum();
    }

    void publish_sum()
    {
        if (!sum_ready_) return;

        auto sum_msg = std_msgs::msg::Float32();
        sum_msg.data = val1_ + val2_;
        pub_->publish(sum_msg);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr sub1_, sub2_;
    float val1_, val2_;
    bool sum_ready_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SumTwoSines>());
    rclcpp::shutdown();
    return 0;
}