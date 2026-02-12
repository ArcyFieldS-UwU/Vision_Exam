// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_server/srv/detail/el_gamal_encrypt__rosidl_typesupport_introspection_c.h"
#include "rm_server/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_server/srv/detail/el_gamal_encrypt__functions.h"
#include "rm_server/srv/detail/el_gamal_encrypt__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_server__srv__ElGamalEncrypt_Request__init(message_memory);
}

void rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_fini_function(void * message_memory)
{
  rm_server__srv__ElGamalEncrypt_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_member_array[1] = {
  {
    "b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_server__srv__ElGamalEncrypt_Request, b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_members = {
  "rm_server__srv",  // message namespace
  "ElGamalEncrypt_Request",  // message name
  1,  // number of fields
  sizeof(rm_server__srv__ElGamalEncrypt_Request),
  rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_member_array,  // message members
  rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_type_support_handle = {
  0,
  &rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_server
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_server, srv, ElGamalEncrypt_Request)() {
  if (!rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_type_support_handle.typesupport_identifier) {
    rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rm_server__srv__ElGamalEncrypt_Request__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rm_server/srv/detail/el_gamal_encrypt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rm_server/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rm_server/srv/detail/el_gamal_encrypt__functions.h"
// already included above
// #include "rm_server/srv/detail/el_gamal_encrypt__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_server__srv__ElGamalEncrypt_Response__init(message_memory);
}

void rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_fini_function(void * message_memory)
{
  rm_server__srv__ElGamalEncrypt_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_member_array[2] = {
  {
    "y1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_server__srv__ElGamalEncrypt_Response, y1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_server__srv__ElGamalEncrypt_Response, y2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_members = {
  "rm_server__srv",  // message namespace
  "ElGamalEncrypt_Response",  // message name
  2,  // number of fields
  sizeof(rm_server__srv__ElGamalEncrypt_Response),
  rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_member_array,  // message members
  rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_type_support_handle = {
  0,
  &rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_server
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_server, srv, ElGamalEncrypt_Response)() {
  if (!rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_type_support_handle.typesupport_identifier) {
    rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rm_server__srv__ElGamalEncrypt_Response__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rm_server/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rm_server/srv/detail/el_gamal_encrypt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_service_members = {
  "rm_server__srv",  // service namespace
  "ElGamalEncrypt",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_Request_message_type_support_handle,
  NULL  // response message
  // rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_Response_message_type_support_handle
};

static rosidl_service_type_support_t rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_service_type_support_handle = {
  0,
  &rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_server, srv, ElGamalEncrypt_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_server, srv, ElGamalEncrypt_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_server
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_server, srv, ElGamalEncrypt)() {
  if (!rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_service_type_support_handle.typesupport_identifier) {
    rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_server, srv, ElGamalEncrypt_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_server, srv, ElGamalEncrypt_Response)()->data;
  }

  return &rm_server__srv__detail__el_gamal_encrypt__rosidl_typesupport_introspection_c__ElGamalEncrypt_service_type_support_handle;
}
