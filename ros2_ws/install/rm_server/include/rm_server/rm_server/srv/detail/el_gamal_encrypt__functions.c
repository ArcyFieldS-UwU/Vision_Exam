// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice
#include "rm_server/srv/detail/el_gamal_encrypt__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
rm_server__srv__ElGamalEncrypt_Request__init(rm_server__srv__ElGamalEncrypt_Request * msg)
{
  if (!msg) {
    return false;
  }
  // b
  return true;
}

void
rm_server__srv__ElGamalEncrypt_Request__fini(rm_server__srv__ElGamalEncrypt_Request * msg)
{
  if (!msg) {
    return;
  }
  // b
}

bool
rm_server__srv__ElGamalEncrypt_Request__are_equal(const rm_server__srv__ElGamalEncrypt_Request * lhs, const rm_server__srv__ElGamalEncrypt_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  return true;
}

bool
rm_server__srv__ElGamalEncrypt_Request__copy(
  const rm_server__srv__ElGamalEncrypt_Request * input,
  rm_server__srv__ElGamalEncrypt_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // b
  output->b = input->b;
  return true;
}

rm_server__srv__ElGamalEncrypt_Request *
rm_server__srv__ElGamalEncrypt_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__srv__ElGamalEncrypt_Request * msg = (rm_server__srv__ElGamalEncrypt_Request *)allocator.allocate(sizeof(rm_server__srv__ElGamalEncrypt_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_server__srv__ElGamalEncrypt_Request));
  bool success = rm_server__srv__ElGamalEncrypt_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_server__srv__ElGamalEncrypt_Request__destroy(rm_server__srv__ElGamalEncrypt_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_server__srv__ElGamalEncrypt_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_server__srv__ElGamalEncrypt_Request__Sequence__init(rm_server__srv__ElGamalEncrypt_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__srv__ElGamalEncrypt_Request * data = NULL;

  if (size) {
    data = (rm_server__srv__ElGamalEncrypt_Request *)allocator.zero_allocate(size, sizeof(rm_server__srv__ElGamalEncrypt_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_server__srv__ElGamalEncrypt_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_server__srv__ElGamalEncrypt_Request__fini(&data[i - 1]);
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
rm_server__srv__ElGamalEncrypt_Request__Sequence__fini(rm_server__srv__ElGamalEncrypt_Request__Sequence * array)
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
      rm_server__srv__ElGamalEncrypt_Request__fini(&array->data[i]);
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

rm_server__srv__ElGamalEncrypt_Request__Sequence *
rm_server__srv__ElGamalEncrypt_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__srv__ElGamalEncrypt_Request__Sequence * array = (rm_server__srv__ElGamalEncrypt_Request__Sequence *)allocator.allocate(sizeof(rm_server__srv__ElGamalEncrypt_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_server__srv__ElGamalEncrypt_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_server__srv__ElGamalEncrypt_Request__Sequence__destroy(rm_server__srv__ElGamalEncrypt_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_server__srv__ElGamalEncrypt_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_server__srv__ElGamalEncrypt_Request__Sequence__are_equal(const rm_server__srv__ElGamalEncrypt_Request__Sequence * lhs, const rm_server__srv__ElGamalEncrypt_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_server__srv__ElGamalEncrypt_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_server__srv__ElGamalEncrypt_Request__Sequence__copy(
  const rm_server__srv__ElGamalEncrypt_Request__Sequence * input,
  rm_server__srv__ElGamalEncrypt_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_server__srv__ElGamalEncrypt_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_server__srv__ElGamalEncrypt_Request * data =
      (rm_server__srv__ElGamalEncrypt_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_server__srv__ElGamalEncrypt_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_server__srv__ElGamalEncrypt_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_server__srv__ElGamalEncrypt_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
rm_server__srv__ElGamalEncrypt_Response__init(rm_server__srv__ElGamalEncrypt_Response * msg)
{
  if (!msg) {
    return false;
  }
  // y1
  // y2
  return true;
}

void
rm_server__srv__ElGamalEncrypt_Response__fini(rm_server__srv__ElGamalEncrypt_Response * msg)
{
  if (!msg) {
    return;
  }
  // y1
  // y2
}

bool
rm_server__srv__ElGamalEncrypt_Response__are_equal(const rm_server__srv__ElGamalEncrypt_Response * lhs, const rm_server__srv__ElGamalEncrypt_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // y1
  if (lhs->y1 != rhs->y1) {
    return false;
  }
  // y2
  if (lhs->y2 != rhs->y2) {
    return false;
  }
  return true;
}

bool
rm_server__srv__ElGamalEncrypt_Response__copy(
  const rm_server__srv__ElGamalEncrypt_Response * input,
  rm_server__srv__ElGamalEncrypt_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // y1
  output->y1 = input->y1;
  // y2
  output->y2 = input->y2;
  return true;
}

rm_server__srv__ElGamalEncrypt_Response *
rm_server__srv__ElGamalEncrypt_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__srv__ElGamalEncrypt_Response * msg = (rm_server__srv__ElGamalEncrypt_Response *)allocator.allocate(sizeof(rm_server__srv__ElGamalEncrypt_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_server__srv__ElGamalEncrypt_Response));
  bool success = rm_server__srv__ElGamalEncrypt_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_server__srv__ElGamalEncrypt_Response__destroy(rm_server__srv__ElGamalEncrypt_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_server__srv__ElGamalEncrypt_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_server__srv__ElGamalEncrypt_Response__Sequence__init(rm_server__srv__ElGamalEncrypt_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__srv__ElGamalEncrypt_Response * data = NULL;

  if (size) {
    data = (rm_server__srv__ElGamalEncrypt_Response *)allocator.zero_allocate(size, sizeof(rm_server__srv__ElGamalEncrypt_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_server__srv__ElGamalEncrypt_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_server__srv__ElGamalEncrypt_Response__fini(&data[i - 1]);
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
rm_server__srv__ElGamalEncrypt_Response__Sequence__fini(rm_server__srv__ElGamalEncrypt_Response__Sequence * array)
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
      rm_server__srv__ElGamalEncrypt_Response__fini(&array->data[i]);
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

rm_server__srv__ElGamalEncrypt_Response__Sequence *
rm_server__srv__ElGamalEncrypt_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_server__srv__ElGamalEncrypt_Response__Sequence * array = (rm_server__srv__ElGamalEncrypt_Response__Sequence *)allocator.allocate(sizeof(rm_server__srv__ElGamalEncrypt_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_server__srv__ElGamalEncrypt_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_server__srv__ElGamalEncrypt_Response__Sequence__destroy(rm_server__srv__ElGamalEncrypt_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_server__srv__ElGamalEncrypt_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_server__srv__ElGamalEncrypt_Response__Sequence__are_equal(const rm_server__srv__ElGamalEncrypt_Response__Sequence * lhs, const rm_server__srv__ElGamalEncrypt_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_server__srv__ElGamalEncrypt_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_server__srv__ElGamalEncrypt_Response__Sequence__copy(
  const rm_server__srv__ElGamalEncrypt_Response__Sequence * input,
  rm_server__srv__ElGamalEncrypt_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_server__srv__ElGamalEncrypt_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_server__srv__ElGamalEncrypt_Response * data =
      (rm_server__srv__ElGamalEncrypt_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_server__srv__ElGamalEncrypt_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_server__srv__ElGamalEncrypt_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_server__srv__ElGamalEncrypt_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
