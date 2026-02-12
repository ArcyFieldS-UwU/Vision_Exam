//
// Created by arcyfields on 2026/2/12.
//

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rm_server/msg/get_el_gamal_params.hpp"
#include "rm_server/srv/el_gamal_encrypt.hpp"
#include "std_msgs/msg/int64.hpp"

int64_t quick_pow(int64_t a, int64_t b, int64_t p) { // Quick Pow
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

class Calculating : public rclcpp::Node { // Calculating node class
public:
    Calculating() : Node("calculating") {
        // Subscriber to get p and a.
        params_sub_ = this->create_subscription<rm_server::msg::GetElGamalParams>(
            "elgamal_params", 10,
            std::bind(&Calculating::params_callback_, this, std::placeholders::_1));
        // Client to send public_key.
        key_cli_ = this->create_client<rm_server::srv::ElGamalEncrypt>(
            "elgamal_service"
        );
        // Publisher to publish the result.
        result_pub_ = this->create_publisher<std_msgs::msg::Int64>("elgamal_result", 10);
    }
private:
    void params_callback_(const rm_server::msg::GetElGamalParams & params) {
        int64_t b = quick_pow(params.a, n_, params.p);
        RCLCPP_INFO(this->get_logger(), "%ld", b); // Output the public_key. (Debug Usage)
        key_call_(b, params.p); // To send the public_key and get the result (Which is the reason to pass the num p).
    }
    void key_call_(int64_t key, int64_t p) {
        if (!key_cli_->wait_for_service(std::chrono::seconds(1))) { // Make sure the service is available.
            RCLCPP_ERROR(this->get_logger(), "Cannot get service.");
            return;
        }

        auto request = std::make_shared<rm_server::srv::ElGamalEncrypt::Request>();
        request->b = key;

        auto result = key_cli_->async_send_request( // Get y1, y2 and calculating.
            request,
            [this, p](rclcpp::Client<rm_server::srv::ElGamalEncrypt>::SharedFuture future) {
                auto response = future.get();
                int64_t y1 = response->y1;
                int64_t y2 = response->y2;
                RCLCPP_INFO(this->get_logger(), "%ld %ld", y1, y2); // Output y1 and y2.

                int64_t x = y2 * (quick_pow(y1, n_ * (p - 2), p)) % p;
                auto msg = std_msgs::msg::Int64();
                msg.data = x;
                result_pub_->publish(msg);
            }
        );
    }
    rclcpp::Subscription<rm_server::msg::GetElGamalParams>::SharedPtr params_sub_;
    rclcpp::Client<rm_server::srv::ElGamalEncrypt>::SharedPtr key_cli_;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr result_pub_;
    const int64_t n_ = 5; // Private Key
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Calculating>();
    rclcpp::spin(node); // Spin the node.
    rclcpp::shutdown();
    return 0;
}