// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_server:msg/GetElGamalParams.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__TRAITS_HPP_
#define RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_server/msg/detail/get_el_gamal_params__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_server
{

namespace msg
{

inline void to_flow_style_yaml(
  const GetElGamalParams & msg,
  std::ostream & out)
{
  out << "{";
  // member: p
  {
    out << "p: ";
    rosidl_generator_traits::value_to_yaml(msg.p, out);
    out << ", ";
  }

  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetElGamalParams & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: p
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p: ";
    rosidl_generator_traits::value_to_yaml(msg.p, out);
    out << "\n";
  }

  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetElGamalParams & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rm_server

namespace rosidl_generator_traits
{

[[deprecated("use rm_server::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rm_server::msg::GetElGamalParams & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_server::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_server::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_server::msg::GetElGamalParams & msg)
{
  return rm_server::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_server::msg::GetElGamalParams>()
{
  return "rm_server::msg::GetElGamalParams";
}

template<>
inline const char * name<rm_server::msg::GetElGamalParams>()
{
  return "rm_server/msg/GetElGamalParams";
}

template<>
struct has_fixed_size<rm_server::msg::GetElGamalParams>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_server::msg::GetElGamalParams>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_server::msg::GetElGamalParams>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__TRAITS_HPP_
