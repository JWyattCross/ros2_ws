// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uf_interfaces:srv/GeoConv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "uf_interfaces/srv/geo_conv.hpp"


#ifndef UF_INTERFACES__SRV__DETAIL__GEO_CONV__TRAITS_HPP_
#define UF_INTERFACES__SRV__DETAIL__GEO_CONV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "uf_interfaces/srv/detail/geo_conv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace uf_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GeoConv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: input_x
  {
    out << "input_x: ";
    rosidl_generator_traits::value_to_yaml(msg.input_x, out);
    out << ", ";
  }

  // member: input_y
  {
    out << "input_y: ";
    rosidl_generator_traits::value_to_yaml(msg.input_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GeoConv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: input_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_x: ";
    rosidl_generator_traits::value_to_yaml(msg.input_x, out);
    out << "\n";
  }

  // member: input_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_y: ";
    rosidl_generator_traits::value_to_yaml(msg.input_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GeoConv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace uf_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use uf_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const uf_interfaces::srv::GeoConv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  uf_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use uf_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const uf_interfaces::srv::GeoConv_Request & msg)
{
  return uf_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<uf_interfaces::srv::GeoConv_Request>()
{
  return "uf_interfaces::srv::GeoConv_Request";
}

template<>
inline const char * name<uf_interfaces::srv::GeoConv_Request>()
{
  return "uf_interfaces/srv/GeoConv_Request";
}

template<>
struct has_fixed_size<uf_interfaces::srv::GeoConv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<uf_interfaces::srv::GeoConv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<uf_interfaces::srv::GeoConv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace uf_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GeoConv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: output_x
  {
    out << "output_x: ";
    rosidl_generator_traits::value_to_yaml(msg.output_x, out);
    out << ", ";
  }

  // member: output_y
  {
    out << "output_y: ";
    rosidl_generator_traits::value_to_yaml(msg.output_y, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GeoConv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: output_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output_x: ";
    rosidl_generator_traits::value_to_yaml(msg.output_x, out);
    out << "\n";
  }

  // member: output_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output_y: ";
    rosidl_generator_traits::value_to_yaml(msg.output_y, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GeoConv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace uf_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use uf_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const uf_interfaces::srv::GeoConv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  uf_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use uf_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const uf_interfaces::srv::GeoConv_Response & msg)
{
  return uf_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<uf_interfaces::srv::GeoConv_Response>()
{
  return "uf_interfaces::srv::GeoConv_Response";
}

template<>
inline const char * name<uf_interfaces::srv::GeoConv_Response>()
{
  return "uf_interfaces/srv/GeoConv_Response";
}

template<>
struct has_fixed_size<uf_interfaces::srv::GeoConv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<uf_interfaces::srv::GeoConv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<uf_interfaces::srv::GeoConv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace uf_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GeoConv_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GeoConv_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GeoConv_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace uf_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use uf_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const uf_interfaces::srv::GeoConv_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  uf_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use uf_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const uf_interfaces::srv::GeoConv_Event & msg)
{
  return uf_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<uf_interfaces::srv::GeoConv_Event>()
{
  return "uf_interfaces::srv::GeoConv_Event";
}

template<>
inline const char * name<uf_interfaces::srv::GeoConv_Event>()
{
  return "uf_interfaces/srv/GeoConv_Event";
}

template<>
struct has_fixed_size<uf_interfaces::srv::GeoConv_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<uf_interfaces::srv::GeoConv_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<uf_interfaces::srv::GeoConv_Request>::value && has_bounded_size<uf_interfaces::srv::GeoConv_Response>::value> {};

template<>
struct is_message<uf_interfaces::srv::GeoConv_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uf_interfaces::srv::GeoConv>()
{
  return "uf_interfaces::srv::GeoConv";
}

template<>
inline const char * name<uf_interfaces::srv::GeoConv>()
{
  return "uf_interfaces/srv/GeoConv";
}

template<>
struct has_fixed_size<uf_interfaces::srv::GeoConv>
  : std::integral_constant<
    bool,
    has_fixed_size<uf_interfaces::srv::GeoConv_Request>::value &&
    has_fixed_size<uf_interfaces::srv::GeoConv_Response>::value
  >
{
};

template<>
struct has_bounded_size<uf_interfaces::srv::GeoConv>
  : std::integral_constant<
    bool,
    has_bounded_size<uf_interfaces::srv::GeoConv_Request>::value &&
    has_bounded_size<uf_interfaces::srv::GeoConv_Response>::value
  >
{
};

template<>
struct is_service<uf_interfaces::srv::GeoConv>
  : std::true_type
{
};

template<>
struct is_service_request<uf_interfaces::srv::GeoConv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<uf_interfaces::srv::GeoConv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UF_INTERFACES__SRV__DETAIL__GEO_CONV__TRAITS_HPP_
