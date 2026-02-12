// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__BUILDER_HPP_
#define RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_server/srv/detail/el_gamal_encrypt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_server
{

namespace srv
{

namespace builder
{

class Init_ElGamalEncrypt_Request_b
{
public:
  Init_ElGamalEncrypt_Request_b()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rm_server::srv::ElGamalEncrypt_Request b(::rm_server::srv::ElGamalEncrypt_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_server::srv::ElGamalEncrypt_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_server::srv::ElGamalEncrypt_Request>()
{
  return rm_server::srv::builder::Init_ElGamalEncrypt_Request_b();
}

}  // namespace rm_server


namespace rm_server
{

namespace srv
{

namespace builder
{

class Init_ElGamalEncrypt_Response_y2
{
public:
  explicit Init_ElGamalEncrypt_Response_y2(::rm_server::srv::ElGamalEncrypt_Response & msg)
  : msg_(msg)
  {}
  ::rm_server::srv::ElGamalEncrypt_Response y2(::rm_server::srv::ElGamalEncrypt_Response::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_server::srv::ElGamalEncrypt_Response msg_;
};

class Init_ElGamalEncrypt_Response_y1
{
public:
  Init_ElGamalEncrypt_Response_y1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ElGamalEncrypt_Response_y2 y1(::rm_server::srv::ElGamalEncrypt_Response::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_ElGamalEncrypt_Response_y2(msg_);
  }

private:
  ::rm_server::srv::ElGamalEncrypt_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_server::srv::ElGamalEncrypt_Response>()
{
  return rm_server::srv::builder::Init_ElGamalEncrypt_Response_y1();
}

}  // namespace rm_server

#endif  // RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__BUILDER_HPP_
