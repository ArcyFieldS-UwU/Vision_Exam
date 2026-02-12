// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_server:srv/ElGamalEncrypt.idl
// generated code does not contain a copyright notice

#ifndef RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__STRUCT_HPP_
#define RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_server__srv__ElGamalEncrypt_Request __attribute__((deprecated))
#else
# define DEPRECATED__rm_server__srv__ElGamalEncrypt_Request __declspec(deprecated)
#endif

namespace rm_server
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ElGamalEncrypt_Request_
{
  using Type = ElGamalEncrypt_Request_<ContainerAllocator>;

  explicit ElGamalEncrypt_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->b = 0ll;
    }
  }

  explicit ElGamalEncrypt_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->b = 0ll;
    }
  }

  // field types and members
  using _b_type =
    int64_t;
  _b_type b;

  // setters for named parameter idiom
  Type & set__b(
    const int64_t & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_server__srv__ElGamalEncrypt_Request
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_server__srv__ElGamalEncrypt_Request
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ElGamalEncrypt_Request_ & other) const
  {
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const ElGamalEncrypt_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ElGamalEncrypt_Request_

// alias to use template instance with default allocator
using ElGamalEncrypt_Request =
  rm_server::srv::ElGamalEncrypt_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rm_server


#ifndef _WIN32
# define DEPRECATED__rm_server__srv__ElGamalEncrypt_Response __attribute__((deprecated))
#else
# define DEPRECATED__rm_server__srv__ElGamalEncrypt_Response __declspec(deprecated)
#endif

namespace rm_server
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ElGamalEncrypt_Response_
{
  using Type = ElGamalEncrypt_Response_<ContainerAllocator>;

  explicit ElGamalEncrypt_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->y1 = 0ll;
      this->y2 = 0ll;
    }
  }

  explicit ElGamalEncrypt_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->y1 = 0ll;
      this->y2 = 0ll;
    }
  }

  // field types and members
  using _y1_type =
    int64_t;
  _y1_type y1;
  using _y2_type =
    int64_t;
  _y2_type y2;

  // setters for named parameter idiom
  Type & set__y1(
    const int64_t & _arg)
  {
    this->y1 = _arg;
    return *this;
  }
  Type & set__y2(
    const int64_t & _arg)
  {
    this->y2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_server__srv__ElGamalEncrypt_Response
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_server__srv__ElGamalEncrypt_Response
    std::shared_ptr<rm_server::srv::ElGamalEncrypt_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ElGamalEncrypt_Response_ & other) const
  {
    if (this->y1 != other.y1) {
      return false;
    }
    if (this->y2 != other.y2) {
      return false;
    }
    return true;
  }
  bool operator!=(const ElGamalEncrypt_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ElGamalEncrypt_Response_

// alias to use template instance with default allocator
using ElGamalEncrypt_Response =
  rm_server::srv::ElGamalEncrypt_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rm_server

namespace rm_server
{

namespace srv
{

struct ElGamalEncrypt
{
  using Request = rm_server::srv::ElGamalEncrypt_Request;
  using Response = rm_server::srv::ElGamalEncrypt_Response;
};

}  // namespace srv

}  // namespace rm_server

#endif  // RM_SERVER__SRV__DETAIL__EL_GAMAL_ENCRYPT__STRUCT_HPP_
