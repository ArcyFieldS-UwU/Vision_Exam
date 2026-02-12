// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__TRAITS_HPP_
#define RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_server/srv/detail/el_gamal_encrypt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_server
{

namespace srv
{

inline void to_flow_style_yaml(
  const ElGamalEncrypt_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ElGamalEncrypt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ElGamalEncrypt_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rm_server

namespace rosidl_generator_traits
{

[[deprecated("use rm_server::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rm_server::srv::ElGamalEncrypt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_server::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_server::srv::to_yaml() instead")]]
inline std::string to_yaml(const rm_server::srv::ElGamalEncrypt_Request & msg)
{
  return rm_server::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rm_server::srv::ElGamalEncrypt_Request>()
{
  return "rm_server::srv::ElGamalEncrypt_Request";
}

template<>
inline const char * name<rm_server::srv::ElGamalEncrypt_Request>()
{
  return "rm_server/srv/ElGamalEncrypt_Request";
}

template<>
struct has_fixed_size<rm_server::srv::ElGamalEncrypt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_server::srv::ElGamalEncrypt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_server::srv::ElGamalEncrypt_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rm_server
{

namespace srv
{

inline void to_flow_style_yaml(
  const ElGamalEncrypt_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: y1
  {
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << ", ";
  }

  // member: y2
  {
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ElGamalEncrypt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << "\n";
  }

  // member: y2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ElGamalEncrypt_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rm_server

namespace rosidl_generator_traits
{

[[deprecated("use rm_server::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rm_server::srv::ElGamalEncrypt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_server::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_server::srv::to_yaml() instead")]]
inline std::string to_yaml(const rm_server::srv::ElGamalEncrypt_Response & msg)
{
  return rm_server::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rm_server::srv::ElGamalEncrypt_Response>()
{
  return "rm_server::srv::ElGamalEncrypt_Response";
}

template<>
inline const char * name<rm_server::srv::ElGamalEncrypt_Response>()
{
  return "rm_server/srv/ElGamalEncrypt_Response";
}

template<>
struct has_fixed_size<rm_server::srv::ElGamalEncrypt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_server::srv::ElGamalEncrypt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_server::srv::ElGamalEncrypt_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rm_server::srv::ElGamalEncrypt>()
{
  return "rm_server::srv::ElGamalEncrypt";
}

template<>
inline const char * name<rm_server::srv::ElGamalEncrypt>()
{
  return "rm_server/srv/ElGamalEncrypt";
}

template<>
struct has_fixed_size<rm_server::srv::ElGamalEncrypt>
  : std::integral_constant<
    bool,
    has_fixed_size<rm_server::srv::ElGamalEncrypt_Request>::value &&
    has_fixed_size<rm_server::srv::ElGamalEncrypt_Response>::value
  >
{
};

template<>
struct has_bounded_size<rm_server::srv::ElGamalEncrypt>
  : std::integral_constant<
    bool,
    has_bounded_size<rm_server::srv::ElGamalEncrypt_Request>::value &&
    has_bounded_size<rm_server::srv::ElGamalEncrypt_Response>::value
  >
{
};

template<>
struct is_service<rm_server::srv::ElGamalEncrypt>
  : std::true_type
{
};

template<>
struct is_service_request<rm_server::srv::ElGamalEncrypt_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rm_server::srv::ElGamalEncrypt_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__TRAITS_HPP_
