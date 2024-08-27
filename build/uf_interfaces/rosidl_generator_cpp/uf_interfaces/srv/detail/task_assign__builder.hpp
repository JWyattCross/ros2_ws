// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uf_interfaces:srv/TaskAssign.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "uf_interfaces/srv/task_assign.hpp"


#ifndef UF_INTERFACES__SRV__DETAIL__TASK_ASSIGN__BUILDER_HPP_
#define UF_INTERFACES__SRV__DETAIL__TASK_ASSIGN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "uf_interfaces/srv/detail/task_assign__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace uf_interfaces
{

namespace srv
{

namespace builder
{

class Init_TaskAssign_Request_target
{
public:
  Init_TaskAssign_Request_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::uf_interfaces::srv::TaskAssign_Request target(::uf_interfaces::srv::TaskAssign_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uf_interfaces::srv::TaskAssign_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uf_interfaces::srv::TaskAssign_Request>()
{
  return uf_interfaces::srv::builder::Init_TaskAssign_Request_target();
}

}  // namespace uf_interfaces


namespace uf_interfaces
{

namespace srv
{

namespace builder
{

class Init_TaskAssign_Response_message
{
public:
  explicit Init_TaskAssign_Response_message(::uf_interfaces::srv::TaskAssign_Response & msg)
  : msg_(msg)
  {}
  ::uf_interfaces::srv::TaskAssign_Response message(::uf_interfaces::srv::TaskAssign_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uf_interfaces::srv::TaskAssign_Response msg_;
};

class Init_TaskAssign_Response_success
{
public:
  Init_TaskAssign_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskAssign_Response_message success(::uf_interfaces::srv::TaskAssign_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_TaskAssign_Response_message(msg_);
  }

private:
  ::uf_interfaces::srv::TaskAssign_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uf_interfaces::srv::TaskAssign_Response>()
{
  return uf_interfaces::srv::builder::Init_TaskAssign_Response_success();
}

}  // namespace uf_interfaces


namespace uf_interfaces
{

namespace srv
{

namespace builder
{

class Init_TaskAssign_Event_response
{
public:
  explicit Init_TaskAssign_Event_response(::uf_interfaces::srv::TaskAssign_Event & msg)
  : msg_(msg)
  {}
  ::uf_interfaces::srv::TaskAssign_Event response(::uf_interfaces::srv::TaskAssign_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uf_interfaces::srv::TaskAssign_Event msg_;
};

class Init_TaskAssign_Event_request
{
public:
  explicit Init_TaskAssign_Event_request(::uf_interfaces::srv::TaskAssign_Event & msg)
  : msg_(msg)
  {}
  Init_TaskAssign_Event_response request(::uf_interfaces::srv::TaskAssign_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_TaskAssign_Event_response(msg_);
  }

private:
  ::uf_interfaces::srv::TaskAssign_Event msg_;
};

class Init_TaskAssign_Event_info
{
public:
  Init_TaskAssign_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskAssign_Event_request info(::uf_interfaces::srv::TaskAssign_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_TaskAssign_Event_request(msg_);
  }

private:
  ::uf_interfaces::srv::TaskAssign_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uf_interfaces::srv::TaskAssign_Event>()
{
  return uf_interfaces::srv::builder::Init_TaskAssign_Event_info();
}

}  // namespace uf_interfaces

#endif  // UF_INTERFACES__SRV__DETAIL__TASK_ASSIGN__BUILDER_HPP_
