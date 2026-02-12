// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_server:msg/GetElGamalParams.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__BUILDER_HPP_
#define RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_server/msg/detail/get_el_gamal_params__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_server
{

namespace msg
{

namespace builder
{

class Init_GetElGamalParams_a
{
public:
  explicit Init_GetElGamalParams_a(::rm_server::msg::GetElGamalParams & msg)
  : msg_(msg)
  {}
  ::rm_server::msg::GetElGamalParams a(::rm_server::msg::GetElGamalParams::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_server::msg::GetElGamalParams msg_;
};

class Init_GetElGamalParams_p
{
public:
  Init_GetElGamalParams_p()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetElGamalParams_a p(::rm_server::msg::GetElGamalParams::_p_type arg)
  {
    msg_.p = std::move(arg);
    return Init_GetElGamalParams_a(msg_);
  }

private:
  ::rm_server::msg::GetElGamalParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_server::msg::GetElGamalParams>()
{
  return rm_server::msg::builder::Init_GetElGamalParams_p();
}

}  // namespace rm_server

#endif  // RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__BUILDER_HPP_
