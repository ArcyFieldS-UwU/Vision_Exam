// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__STRUCT_H_
#define RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ElGamalEncrypt in the package rm_server.
typedef struct rm_server__srv__ElGamalEncrypt_Request
{
  int64_t b;
} rm_server__srv__ElGamalEncrypt_Request;

// Struct for a sequence of rm_server__srv__ElGamalEncrypt_Request.
typedef struct rm_server__srv__ElGamalEncrypt_Request__Sequence
{
  rm_server__srv__ElGamalEncrypt_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_server__srv__ElGamalEncrypt_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ElGamalEncrypt in the package rm_server.
typedef struct rm_server__srv__ElGamalEncrypt_Response
{
  int64_t y1;
  int64_t y2;
} rm_server__srv__ElGamalEncrypt_Response;

// Struct for a sequence of rm_server__srv__ElGamalEncrypt_Response.
typedef struct rm_server__srv__ElGamalEncrypt_Response__Sequence
{
  rm_server__srv__ElGamalEncrypt_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_server__srv__ElGamalEncrypt_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__STRUCT_H_
