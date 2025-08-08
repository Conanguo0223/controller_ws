#pragma once

#include "unitree_go/msg/low_cmd.hpp"
#include "unitree_go/msg/motor_cmd.hpp"
#include "unitree_go/msg/bms_cmd.hpp"
#include "test_controller/motor_crc.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Low_level_control : public rclcpp::Node
{
    public:
        Low_level_control();
        ~Low_level_control();
        bool init();
        void update(const rclcpp::Time& time, const rclcpp::Duration& period);
        void starting(const rclcpp::Time& time);
        void stopping(const rclcpp::Time& /*time*/) { mpcRunning_ = false; };

    private:
        std::chrono::duration<double> dt = std::chrono::duration<double>(0.005); // 200Hz
        std::atomic_bool mpcRunning_ = false;
};
