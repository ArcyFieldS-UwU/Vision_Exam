// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_server:msg/GetElGamalParams.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__STRUCT_HPP_
#define RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_server__msg__GetElGamalParams __attribute__((deprecated))
#else
# define DEPRECATED__rm_server__msg__GetElGamalParams __declspec(deprecated)
#endif

namespace rm_server
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GetElGamalParams_
{
  using Type = GetElGamalParams_<ContainerAllocator>;

  explicit GetElGamalParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->p = 0ll;
      this->a = 0ll;
    }
  }

  explicit GetElGamalParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->p = 0ll;
      this->a = 0ll;
    }
  }

  // field types and members
  using _p_type =
    int64_t;
  _p_type p;
  using _a_type =
    int64_t;
  _a_type a;

  // setters for named parameter idiom
  Type & set__p(
    const int64_t & _arg)
  {
    this->p = _arg;
    return *this;
  }
  Type & set__a(
    const int64_t & _arg)
  {
    this->a = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_server::msg::GetElGamalParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_server::msg::GetElGamalParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_server::msg::GetElGamalParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_server::msg::GetElGamalParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_server__msg__GetElGamalParams
    std::shared_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_server__msg__GetElGamalParams
    std::shared_ptr<rm_server::msg::GetElGamalParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetElGamalParams_ & other) const
  {
    if (this->p != other.p) {
      return false;
    }
    if (this->a != other.a) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetElGamalParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetElGamalParams_

// alias to use template instance with default allocator
using GetElGamalParams =
  rm_server::msg::GetElGamalParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_server

#endif  // RM_SERVER__MSG__DETAIL__GET_EL_GAMAL_PARAMS__STRUCT_HPP_
