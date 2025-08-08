#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <Eigen/Dense>

#include "test_controller/low_level_control.hpp"

using namespace std::chrono_literals;
using namespace Eigen;

// Create a low_level_cmd_sender class for low state receive
bool Low_level_control::init()
{
    RCLCPP_INFO(this->get_logger(), "Low level control initialized");
    return true;
}
void Low_level_control::update(const rclcpp::Time& time, const rclcpp::Duration& period)
{
    RCLCPP_INFO(this->get_logger(), "Low level control updated");
}
void Low_level_control::starting(const rclcpp::Time& time)
{
    RCLCPP_INFO(this->get_logger(), "Low level control starting");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Low_level_control>();
    
    if (!node->init()) {
        RCLCPP_ERROR(node->get_logger(), "Failed to initialize low level control");
        return 1;
    }

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}