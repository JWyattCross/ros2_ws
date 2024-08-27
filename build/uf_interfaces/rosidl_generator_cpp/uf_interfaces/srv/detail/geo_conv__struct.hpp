// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uf_interfaces:srv/GeoConv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "uf_interfaces/srv/geo_conv.hpp"


#ifndef UF_INTERFACES__SRV__DETAIL__GEO_CONV__STRUCT_HPP_
#define UF_INTERFACES__SRV__DETAIL__GEO_CONV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__uf_interfaces__srv__GeoConv_Request __attribute__((deprecated))
#else
# define DEPRECATED__uf_interfaces__srv__GeoConv_Request __declspec(deprecated)
#endif

namespace uf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GeoConv_Request_
{
  using Type = GeoConv_Request_<ContainerAllocator>;

  explicit GeoConv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input_x = 0.0;
      this->input_y = 0.0;
    }
  }

  explicit GeoConv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input_x = 0.0;
      this->input_y = 0.0;
    }
  }

  // field types and members
  using _input_x_type =
    double;
  _input_x_type input_x;
  using _input_y_type =
    double;
  _input_y_type input_y;

  // setters for named parameter idiom
  Type & set__input_x(
    const double & _arg)
  {
    this->input_x = _arg;
    return *this;
  }
  Type & set__input_y(
    const double & _arg)
  {
    this->input_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uf_interfaces::srv::GeoConv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const uf_interfaces::srv::GeoConv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uf_interfaces__srv__GeoConv_Request
    std::shared_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uf_interfaces__srv__GeoConv_Request
    std::shared_ptr<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GeoConv_Request_ & other) const
  {
    if (this->input_x != other.input_x) {
      return false;
    }
    if (this->input_y != other.input_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const GeoConv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GeoConv_Request_

// alias to use template instance with default allocator
using GeoConv_Request =
  uf_interfaces::srv::GeoConv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uf_interfaces


#ifndef _WIN32
# define DEPRECATED__uf_interfaces__srv__GeoConv_Response __attribute__((deprecated))
#else
# define DEPRECATED__uf_interfaces__srv__GeoConv_Response __declspec(deprecated)
#endif

namespace uf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GeoConv_Response_
{
  using Type = GeoConv_Response_<ContainerAllocator>;

  explicit GeoConv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output_x = 0.0;
      this->output_y = 0.0;
      this->success = false;
      this->message = "";
    }
  }

  explicit GeoConv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output_x = 0.0;
      this->output_y = 0.0;
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _output_x_type =
    double;
  _output_x_type output_x;
  using _output_y_type =
    double;
  _output_y_type output_y;
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__output_x(
    const double & _arg)
  {
    this->output_x = _arg;
    return *this;
  }
  Type & set__output_y(
    const double & _arg)
  {
    this->output_y = _arg;
    return *this;
  }
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
    uf_interfaces::srv::GeoConv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const uf_interfaces::srv::GeoConv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uf_interfaces__srv__GeoConv_Response
    std::shared_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uf_interfaces__srv__GeoConv_Response
    std::shared_ptr<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GeoConv_Response_ & other) const
  {
    if (this->output_x != other.output_x) {
      return false;
    }
    if (this->output_y != other.output_y) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const GeoConv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GeoConv_Response_

// alias to use template instance with default allocator
using GeoConv_Response =
  uf_interfaces::srv::GeoConv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uf_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uf_interfaces__srv__GeoConv_Event __attribute__((deprecated))
#else
# define DEPRECATED__uf_interfaces__srv__GeoConv_Event __declspec(deprecated)
#endif

namespace uf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GeoConv_Event_
{
  using Type = GeoConv_Event_<ContainerAllocator>;

  explicit GeoConv_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GeoConv_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::GeoConv_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uf_interfaces::srv::GeoConv_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uf_interfaces::srv::GeoConv_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const uf_interfaces::srv::GeoConv_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::GeoConv_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uf_interfaces::srv::GeoConv_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uf_interfaces__srv__GeoConv_Event
    std::shared_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uf_interfaces__srv__GeoConv_Event
    std::shared_ptr<uf_interfaces::srv::GeoConv_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GeoConv_Event_ & other) const
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
  bool operator!=(const GeoConv_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GeoConv_Event_

// alias to use template instance with default allocator
using GeoConv_Event =
  uf_interfaces::srv::GeoConv_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uf_interfaces

namespace uf_interfaces
{

namespace srv
{

struct GeoConv
{
  using Request = uf_interfaces::srv::GeoConv_Request;
  using Response = uf_interfaces::srv::GeoConv_Response;
  using Event = uf_interfaces::srv::GeoConv_Event;
};

}  // namespace srv

}  // namespace uf_interfaces

#endif  // UF_INTERFACES__SRV__DETAIL__GEO_CONV__STRUCT_HPP_
