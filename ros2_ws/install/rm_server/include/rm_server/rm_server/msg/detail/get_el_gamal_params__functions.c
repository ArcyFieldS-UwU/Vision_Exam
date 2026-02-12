// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_server:msg/GetElGamalParams.idl
// generated code does not contain a copyright notice
#include "rm_server/msg/detail/get_el_gamal_params__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_server__msg__GetElGamalParams__init(rm_server__msg__GetElGamalParams * msg)
{
  if (!msg) {
    return false;
  }
  // p
  // a
  return true;
}

void
rm_server__msg__GetElGamalParams__fini(rm_server__msg__GetElGamalParams * msg)
{
  if (!msg) {
    return;
  }
  // p
  // a
}

bool
rm_server__msg__GetElGamalParams__are_equal(const rm_server__msg__GetElGamalParams * lhs, const rm_server__msg__GetElGamalParams * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // p
  if (lhs->p != rhs->p) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  return true;
}

bool
rm_server__msg__GetElGamalParams__copy(
  const rm_server__msg__GetElGamalParams * input,
  rm_server__msg__GetElGamalParams * output)
{
  if (!input || !output) {
    return false;
  }
  // p
  output->p = input->p;
  // a
  output->a = input->a;
  return true;
}

rm_server__msg__GetElGamalParams *
rm_server__msg__GetElGamalParams__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__msg__GetElGamalParams * msg = (rm_server__msg__GetElGamalParams *)allocator.allocate(sizeof(rm_server__msg__GetElGamalParams), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_server__msg__GetElGamalParams));
  bool success = rm_server__msg__GetElGamalParams__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_server__msg__GetElGamalParams__destroy(rm_server__msg__GetElGamalParams * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_server__msg__GetElGamalParams__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_server__msg__GetElGamalParams__Sequence__init(rm_server__msg__GetElGamalParams__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__msg__GetElGamalParams * data = NULL;

  if (size) {
    data = (rm_server__msg__GetElGamalParams *)allocator.zero_allocate(size, sizeof(rm_server__msg__GetElGamalParams), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_server__msg__GetElGamalParams__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_server__msg__GetElGamalParams__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rm_server__msg__GetElGamalParams__Sequence__fini(rm_server__msg__GetElGamalParams__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rm_server__msg__GetElGamalParams__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rm_server__msg__GetElGamalParams__Sequence *
rm_server__msg__GetElGamalParams__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__msg__GetElGamalParams__Sequence * array = (rm_server__msg__GetElGamalParams__Sequence *)allocator.allocate(sizeof(rm_server__msg__GetElGamalParams__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_server__msg__GetElGamalParams__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_server__msg__GetElGamalParams__Sequence__destroy(rm_server__msg__GetElGamalParams__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_server__msg__GetElGamalParams__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_server__msg__GetElGamalParams__Sequence__are_equal(const rm_server__msg__GetElGamalParams__Sequence * lhs, const rm_server__msg__GetElGamalParams__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_server__msg__GetElGamalParams__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_server__msg__GetElGamalParams__Sequence__copy(
  const rm_server__msg__GetElGamalParams__Sequence * input,
  rm_server__msg__GetElGamalParams__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_server__msg__GetElGamalParams);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_server__msg__GetElGamalParams * data =
      (rm_server__msg__GetElGamalParams *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_server__msg__GetElGamalParams__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_server__msg__GetElGamalParams__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_server__msg__GetElGamalParams__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
