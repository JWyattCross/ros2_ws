// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uf_interfaces:srv/GeoConv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "uf_interfaces/srv/geo_conv.hpp"


#ifndef UF_INTERFACES__SRV__DETAIL__GEO_CONV__BUILDER_HPP_
#define UF_INTERFACES__SRV__DETAIL__GEO_CONV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "uf_interfaces/srv/detail/geo_conv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace uf_interfaces
{

namespace srv
{

namespace builder
{

class Init_GeoConv_Request_input_y
{
public:
  explicit Init_GeoConv_Request_input_y(::uf_interfaces::srv::GeoConv_Request & msg)
  : msg_(msg)
  {}
  ::uf_interfaces::srv::GeoConv_Request input_y(::uf_interfaces::srv::GeoConv_Request::_input_y_type arg)
  {
    msg_.input_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Request msg_;
};

class Init_GeoConv_Request_input_x
{
public:
  Init_GeoConv_Request_input_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GeoConv_Request_input_y input_x(::uf_interfaces::srv::GeoConv_Request::_input_x_type arg)
  {
    msg_.input_x = std::move(arg);
    return Init_GeoConv_Request_input_y(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uf_interfaces::srv::GeoConv_Request>()
{
  return uf_interfaces::srv::builder::Init_GeoConv_Request_input_x();
}

}  // namespace uf_interfaces


namespace uf_interfaces
{

namespace srv
{

namespace builder
{

class Init_GeoConv_Response_message
{
public:
  explicit Init_GeoConv_Response_message(::uf_interfaces::srv::GeoConv_Response & msg)
  : msg_(msg)
  {}
  ::uf_interfaces::srv::GeoConv_Response message(::uf_interfaces::srv::GeoConv_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Response msg_;
};

class Init_GeoConv_Response_success
{
public:
  explicit Init_GeoConv_Response_success(::uf_interfaces::srv::GeoConv_Response & msg)
  : msg_(msg)
  {}
  Init_GeoConv_Response_message success(::uf_interfaces::srv::GeoConv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GeoConv_Response_message(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Response msg_;
};

class Init_GeoConv_Response_output_y
{
public:
  explicit Init_GeoConv_Response_output_y(::uf_interfaces::srv::GeoConv_Response & msg)
  : msg_(msg)
  {}
  Init_GeoConv_Response_success output_y(::uf_interfaces::srv::GeoConv_Response::_output_y_type arg)
  {
    msg_.output_y = std::move(arg);
    return Init_GeoConv_Response_success(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Response msg_;
};

class Init_GeoConv_Response_output_x
{
public:
  Init_GeoConv_Response_output_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GeoConv_Response_output_y output_x(::uf_interfaces::srv::GeoConv_Response::_output_x_type arg)
  {
    msg_.output_x = std::move(arg);
    return Init_GeoConv_Response_output_y(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uf_interfaces::srv::GeoConv_Response>()
{
  return uf_interfaces::srv::builder::Init_GeoConv_Response_output_x();
}

}  // namespace uf_interfaces


namespace uf_interfaces
{

namespace srv
{

namespace builder
{

class Init_GeoConv_Event_response
{
public:
  explicit Init_GeoConv_Event_response(::uf_interfaces::srv::GeoConv_Event & msg)
  : msg_(msg)
  {}
  ::uf_interfaces::srv::GeoConv_Event response(::uf_interfaces::srv::GeoConv_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Event msg_;
};

class Init_GeoConv_Event_request
{
public:
  explicit Init_GeoConv_Event_request(::uf_interfaces::srv::GeoConv_Event & msg)
  : msg_(msg)
  {}
  Init_GeoConv_Event_response request(::uf_interfaces::srv::GeoConv_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GeoConv_Event_response(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Event msg_;
};

class Init_GeoConv_Event_info
{
public:
  Init_GeoConv_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GeoConv_Event_request info(::uf_interfaces::srv::GeoConv_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GeoConv_Event_request(msg_);
  }

private:
  ::uf_interfaces::srv::GeoConv_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uf_interfaces::srv::GeoConv_Event>()
{
  return uf_interfaces::srv::builder::Init_GeoConv_Event_info();
}

}  // namespace uf_interfaces

#endif  // UF_INTERFACES__SRV__DETAIL__GEO_CONV__BUILDER_HPP_
