// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice
#include "rm_server/srv/detail/el_gamal_encrypt__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rm_server/srv/detail/el_gamal_encrypt__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rm_server
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
cdr_serialize(
  const rm_server::srv::ElGamalEncrypt_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: b
  cdr << ros_message.b;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_server::srv::ElGamalEncrypt_Request & ros_message)
{
  // Member: b
  cdr >> ros_message.b;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
get_serialized_size(
  const rm_server::srv::ElGamalEncrypt_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: b
  {
    size_t item_size = sizeof(ros_message.b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
max_serialized_size_ElGamalEncrypt_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: b
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rm_server::srv::ElGamalEncrypt_Request;
    is_plain =
      (
      offsetof(DataType, b) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ElGamalEncrypt_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_server::srv::ElGamalEncrypt_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ElGamalEncrypt_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_server::srv::ElGamalEncrypt_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ElGamalEncrypt_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_server::srv::ElGamalEncrypt_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ElGamalEncrypt_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ElGamalEncrypt_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ElGamalEncrypt_Request__callbacks = {
  "rm_server::srv",
  "ElGamalEncrypt_Request",
  _ElGamalEncrypt_Request__cdr_serialize,
  _ElGamalEncrypt_Request__cdr_deserialize,
  _ElGamalEncrypt_Request__get_serialized_size,
  _ElGamalEncrypt_Request__max_serialized_size
};

static rosidl_message_type_support_t _ElGamalEncrypt_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ElGamalEncrypt_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace rm_server

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rm_server
const rosidl_message_type_support_t *
get_message_type_support_handle<rm_server::srv::ElGamalEncrypt_Request>()
{
  return &rm_server::srv::typesupport_fastrtps_cpp::_ElGamalEncrypt_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_server, srv, ElGamalEncrypt_Request)() {
  return &rm_server::srv::typesupport_fastrtps_cpp::_ElGamalEncrypt_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rm_server
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
cdr_serialize(
  const rm_server::srv::ElGamalEncrypt_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: y1
  cdr << ros_message.y1;
  // Member: y2
  cdr << ros_message.y2;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rm_server::srv::ElGamalEncrypt_Response & ros_message)
{
  // Member: y1
  cdr >> ros_message.y1;

  // Member: y2
  cdr >> ros_message.y2;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
get_serialized_size(
  const rm_server::srv::ElGamalEncrypt_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: y1
  {
    size_t item_size = sizeof(ros_message.y1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y2
  {
    size_t item_size = sizeof(ros_message.y2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rm_server
max_serialized_size_ElGamalEncrypt_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: y1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: y2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rm_server::srv::ElGamalEncrypt_Response;
    is_plain =
      (
      offsetof(DataType, y2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ElGamalEncrypt_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rm_server::srv::ElGamalEncrypt_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ElGamalEncrypt_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rm_server::srv::ElGamalEncrypt_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ElGamalEncrypt_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rm_server::srv::ElGamalEncrypt_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ElGamalEncrypt_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ElGamalEncrypt_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ElGamalEncrypt_Response__callbacks = {
  "rm_server::srv",
  "ElGamalEncrypt_Response",
  _ElGamalEncrypt_Response__cdr_serialize,
  _ElGamalEncrypt_Response__cdr_deserialize,
  _ElGamalEncrypt_Response__get_serialized_size,
  _ElGamalEncrypt_Response__max_serialized_size
};

static rosidl_message_type_support_t _ElGamalEncrypt_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ElGamalEncrypt_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace rm_server

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rm_server
const rosidl_message_type_support_t *
get_message_type_support_handle<rm_server::srv::ElGamalEncrypt_Response>()
{
  return &rm_server::srv::typesupport_fastrtps_cpp::_ElGamalEncrypt_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_server, srv, ElGamalEncrypt_Response)() {
  return &rm_server::srv::typesupport_fastrtps_cpp::_ElGamalEncrypt_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace rm_server
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _ElGamalEncrypt__callbacks = {
  "rm_server::srv",
  "ElGamalEncrypt",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_server, srv, ElGamalEncrypt_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_server, srv, ElGamalEncrypt_Response)(),
};

static rosidl_service_type_support_t _ElGamalEncrypt__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ElGamalEncrypt__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace rm_server

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rm_server
const rosidl_service_type_support_t *
get_service_type_support_handle<rm_server::srv::ElGamalEncrypt>()
{
  return &rm_server::srv::typesupport_fastrtps_cpp::_ElGamalEncrypt__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rm_server, srv, ElGamalEncrypt)() {
  return &rm_server::srv::typesupport_fastrtps_cpp::_ElGamalEncrypt__handle;
}

#ifdef __cplusplus
}
#endif
