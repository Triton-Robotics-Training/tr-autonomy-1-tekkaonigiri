#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

using std::placeholders::_1;

class PredictedPosPublisher : public rclcpp::Node
{
public:
    PredictedPosPublisher() : Node("predictedpos_publisher")
    {
        // Create publisher
        publisher_ = this->create_publisher<geometry_msgs::msg::Point>("/predictedpos", 10);
        // Publish on a timer every 100ms
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&PredictedPosPublisher::timer_callback, this)
        );
    }

private:
    void timer_callback()
    {
        auto msg = geometry_msgs::msg::Point();
        msg.x = 1.0;  // replace with your predicted x
        msg.y = 2.0;  // replace with your predicted y
        publisher_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Published: x=%f, y=%f", msg.x, msg.y);
    }

    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PredictedPosPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
