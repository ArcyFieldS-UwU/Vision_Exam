// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_server:msg/GetElGamalParams.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__STRUCT_H_
#define RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GetElGamalParams in the package rm_server.
typedef struct rm_server__msg__GetElGamalParams
{
  int64_t p;
  int64_t a;
} rm_server__msg__GetElGamalParams;

// Struct for a sequence of rm_server__msg__GetElGamalParams.
typedef struct rm_server__msg__GetElGamalParams__Sequence
{
  rm_server__msg__GetElGamalParams * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_server__msg__GetElGamalParams__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__STRUCT_H_
