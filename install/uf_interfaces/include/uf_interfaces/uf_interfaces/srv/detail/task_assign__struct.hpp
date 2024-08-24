// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uf_interfaces:srv/TaskAssign.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "uf_interfaces/srv/task_assign.hpp"


#ifndef UF_INTERFACES__SRV__DETAIL__TASK_ASSIGN__STRUCT_HPP_
#define UF_INTERFACES__SRV__DETAIL__TASK_ASSIGN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__uf_interfaces__srv__TaskAssign_Request __attribute__((deprecated))
#else
# define DEPRECATED__uf_interfaces__srv__TaskAssign_Request __declspec(deprecated)
#endif

namespace uf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskAssign_Request_
{
  using Type = TaskAssign_Request_<ContainerAllocator>;

  explicit TaskAssign_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target = "";
    }
  }

  explicit TaskAssign_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target = "";
    }
  }

  // field types and members
  using _target_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_type target;

  // setters for named parameter idiom
  Type & set__target(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uf_interfaces__srv__TaskAssign_Request
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uf_interfaces__srv__TaskAssign_Request
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskAssign_Request_ & other) const
  {
    if (this->target != other.target) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskAssign_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskAssign_Request_

// alias to use template instance with default allocator
using TaskAssign_Request =
  uf_interfaces::srv::TaskAssign_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uf_interfaces


#ifndef _WIN32
# define DEPRECATED__uf_interfaces__srv__TaskAssign_Response __attribute__((deprecated))
#else
# define DEPRECATED__uf_interfaces__srv__TaskAssign_Response __declspec(deprecated)
#endif

namespace uf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskAssign_Response_
{
  using Type = TaskAssign_Response_<ContainerAllocator>;

  explicit TaskAssign_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit TaskAssign_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uf_interfaces__srv__TaskAssign_Response
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uf_interfaces__srv__TaskAssign_Response
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskAssign_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskAssign_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskAssign_Response_

// alias to use template instance with default allocator
using TaskAssign_Response =
  uf_interfaces::srv::TaskAssign_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uf_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uf_interfaces__srv__TaskAssign_Event __attribute__((deprecated))
#else
# define DEPRECATED__uf_interfaces__srv__TaskAssign_Event __declspec(deprecated)
#endif

namespace uf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskAssign_Event_
{
  using Type = TaskAssign_Event_<ContainerAllocator>;

  explicit TaskAssign_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit TaskAssign_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::TaskAssign_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::TaskAssign_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uf_interfaces__srv__TaskAssign_Event
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uf_interfaces__srv__TaskAssign_Event
    std::shared_ptr<uf_interfaces::srv::TaskAssign_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskAssign_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskAssign_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskAssign_Event_

// alias to use template instance with default allocator
using TaskAssign_Event =
  uf_interfaces::srv::TaskAssign_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uf_interfaces

namespace uf_interfaces
{

namespace srv
{

struct TaskAssign
{
  using Request = uf_interfaces::srv::TaskAssign_Request;
  using Response = uf_interfaces::srv::TaskAssign_Response;
  using Event = uf_interfaces::srv::TaskAssign_Event;
};

}  // namespace srv

}  // namespace uf_interfaces

#endif  // UF_INTERFACES__SRV__DETAIL__TASK_ASSIGN__STRUCT_HPP_
