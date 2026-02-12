// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice
#include "rm_server/srv/detail/el_gamal_encrypt__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rm_server/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_server/srv/detail/el_gamal_encrypt__struct.h"
#include "rm_server/srv/detail/el_gamal_encrypt__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ElGamalEncrypt_Request__ros_msg_type = rm_server__srv__ElGamalEncrypt_Request;

static bool _ElGamalEncrypt_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ElGamalEncrypt_Request__ros_msg_type * ros_message = static_cast<const _ElGamalEncrypt_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: b
  {
    cdr << ros_message->b;
  }

  return true;
}

static bool _ElGamalEncrypt_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ElGamalEncrypt_Request__ros_msg_type * ros_message = static_cast<_ElGamalEncrypt_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: b
  {
    cdr >> ros_message->b;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_server
size_t get_serialized_size_rm_server__srv__ElGamalEncrypt_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ElGamalEncrypt_Request__ros_msg_type * ros_message = static_cast<const _ElGamalEncrypt_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name b
  {
    size_t item_size = sizeof(ros_message->b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ElGamalEncrypt_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_server__srv__ElGamalEncrypt_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_server
size_t max_serialized_size_rm_server__srv__ElGamalEncrypt_Request(
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

  // member: b
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
    using DataType = rm_server__srv__ElGamalEncrypt_Request;
    is_plain =
      (
      offsetof(DataType, b) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ElGamalEncrypt_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rm_server__srv__ElGamalEncrypt_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ElGamalEncrypt_Request = {
  "rm_server::srv",
  "ElGamalEncrypt_Request",
  _ElGamalEncrypt_Request__cdr_serialize,
  _ElGamalEncrypt_Request__cdr_deserialize,
  _ElGamalEncrypt_Request__get_serialized_size,
  _ElGamalEncrypt_Request__max_serialized_size
};

static rosidl_message_type_support_t _ElGamalEncrypt_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ElGamalEncrypt_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_server, srv, ElGamalEncrypt_Request)() {
  return &_ElGamalEncrypt_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rm_server/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "rm_server/srv/detail/el_gamal_encrypt__struct.h"
// already included above
// #include "rm_server/srv/detail/el_gamal_encrypt__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ElGamalEncrypt_Response__ros_msg_type = rm_server__srv__ElGamalEncrypt_Response;

static bool _ElGamalEncrypt_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ElGamalEncrypt_Response__ros_msg_type * ros_message = static_cast<const _ElGamalEncrypt_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: y1
  {
    cdr << ros_message->y1;
  }

  // Field name: y2
  {
    cdr << ros_message->y2;
  }

  return true;
}

static bool _ElGamalEncrypt_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ElGamalEncrypt_Response__ros_msg_type * ros_message = static_cast<_ElGamalEncrypt_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: y1
  {
    cdr >> ros_message->y1;
  }

  // Field name: y2
  {
    cdr >> ros_message->y2;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_server
size_t get_serialized_size_rm_server__srv__ElGamalEncrypt_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ElGamalEncrypt_Response__ros_msg_type * ros_message = static_cast<const _ElGamalEncrypt_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name y1
  {
    size_t item_size = sizeof(ros_message->y1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y2
  {
    size_t item_size = sizeof(ros_message->y2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ElGamalEncrypt_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rm_server__srv__ElGamalEncrypt_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rm_server
size_t max_serialized_size_rm_server__srv__ElGamalEncrypt_Response(
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

  // member: y1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y2
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
    using DataType = rm_server__srv__ElGamalEncrypt_Response;
    is_plain =
      (
      offsetof(DataType, y2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ElGamalEncrypt_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rm_server__srv__ElGamalEncrypt_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ElGamalEncrypt_Response = {
  "rm_server::srv",
  "ElGamalEncrypt_Response",
  _ElGamalEncrypt_Response__cdr_serialize,
  _ElGamalEncrypt_Response__cdr_deserialize,
  _ElGamalEncrypt_Response__get_serialized_size,
  _ElGamalEncrypt_Response__max_serialized_size
};

static rosidl_message_type_support_t _ElGamalEncrypt_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ElGamalEncrypt_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_server, srv, ElGamalEncrypt_Response)() {
  return &_ElGamalEncrypt_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rm_server/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rm_server/srv/el_gamal_encrypt.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ElGamalEncrypt__callbacks = {
  "rm_server::srv",
  "ElGamalEncrypt",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_server, srv, ElGamalEncrypt_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_server, srv, ElGamalEncrypt_Response)(),
};

static rosidl_service_type_support_t ElGamalEncrypt__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ElGamalEncrypt__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rm_server, srv, ElGamalEncrypt)() {
  return &ElGamalEncrypt__handle;
}

#if defined(__cplusplus)
}
#endif
