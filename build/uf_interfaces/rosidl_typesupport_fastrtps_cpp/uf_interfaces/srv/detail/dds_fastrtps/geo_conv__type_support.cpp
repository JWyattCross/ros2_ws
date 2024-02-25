// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from uf_interfaces:srv/GeoConv.idl
// generated code does not contain a copyright notice
#include "uf_interfaces/srv/detail/geo_conv__rosidl_typesupport_fastrtps_cpp.hpp"
#include "uf_interfaces/srv/detail/geo_conv__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace uf_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
cdr_serialize(
  const uf_interfaces::srv::GeoConv_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: input_x
  cdr << ros_message.input_x;
  // Member: input_y
  cdr << ros_message.input_y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uf_interfaces::srv::GeoConv_Request & ros_message)
{
  // Member: input_x
  cdr >> ros_message.input_x;

  // Member: input_y
  cdr >> ros_message.input_y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
get_serialized_size(
  const uf_interfaces::srv::GeoConv_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: input_x
  {
    size_t item_size = sizeof(ros_message.input_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: input_y
  {
    size_t item_size = sizeof(ros_message.input_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
max_serialized_size_GeoConv_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: input_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: input_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = uf_interfaces::srv::GeoConv_Request;
    is_plain =
      (
      offsetof(DataType, input_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GeoConv_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const uf_interfaces::srv::GeoConv_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GeoConv_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<uf_interfaces::srv::GeoConv_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GeoConv_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const uf_interfaces::srv::GeoConv_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GeoConv_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GeoConv_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GeoConv_Request__callbacks = {
  "uf_interfaces::srv",
  "GeoConv_Request",
  _GeoConv_Request__cdr_serialize,
  _GeoConv_Request__cdr_deserialize,
  _GeoConv_Request__get_serialized_size,
  _GeoConv_Request__max_serialized_size
};

static rosidl_message_type_support_t _GeoConv_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GeoConv_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace uf_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_uf_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<uf_interfaces::srv::GeoConv_Request>()
{
  return &uf_interfaces::srv::typesupport_fastrtps_cpp::_GeoConv_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uf_interfaces, srv, GeoConv_Request)() {
  return &uf_interfaces::srv::typesupport_fastrtps_cpp::_GeoConv_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace uf_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
cdr_serialize(
  const uf_interfaces::srv::GeoConv_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: output_x
  cdr << ros_message.output_x;
  // Member: output_y
  cdr << ros_message.output_y;
  // Member: success
  cdr << (ros_message.success ? true : false);
  // Member: message
  cdr << ros_message.message;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uf_interfaces::srv::GeoConv_Response & ros_message)
{
  // Member: output_x
  cdr >> ros_message.output_x;

  // Member: output_y
  cdr >> ros_message.output_y;

  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  // Member: message
  cdr >> ros_message.message;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
get_serialized_size(
  const uf_interfaces::srv::GeoConv_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: output_x
  {
    size_t item_size = sizeof(ros_message.output_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: output_y
  {
    size_t item_size = sizeof(ros_message.output_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.message.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uf_interfaces
max_serialized_size_GeoConv_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: output_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: output_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: message
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = uf_interfaces::srv::GeoConv_Response;
    is_plain =
      (
      offsetof(DataType, message) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GeoConv_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const uf_interfaces::srv::GeoConv_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GeoConv_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<uf_interfaces::srv::GeoConv_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GeoConv_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const uf_interfaces::srv::GeoConv_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GeoConv_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GeoConv_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GeoConv_Response__callbacks = {
  "uf_interfaces::srv",
  "GeoConv_Response",
  _GeoConv_Response__cdr_serialize,
  _GeoConv_Response__cdr_deserialize,
  _GeoConv_Response__get_serialized_size,
  _GeoConv_Response__max_serialized_size
};

static rosidl_message_type_support_t _GeoConv_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GeoConv_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace uf_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_uf_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<uf_interfaces::srv::GeoConv_Response>()
{
  return &uf_interfaces::srv::typesupport_fastrtps_cpp::_GeoConv_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uf_interfaces, srv, GeoConv_Response)() {
  return &uf_interfaces::srv::typesupport_fastrtps_cpp::_GeoConv_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace uf_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _GeoConv__callbacks = {
  "uf_interfaces::srv",
  "GeoConv",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uf_interfaces, srv, GeoConv_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uf_interfaces, srv, GeoConv_Response)(),
};

static rosidl_service_type_support_t _GeoConv__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GeoConv__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace uf_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_uf_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<uf_interfaces::srv::GeoConv>()
{
  return &uf_interfaces::srv::typesupport_fastrtps_cpp::_GeoConv__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uf_interfaces, srv, GeoConv)() {
  return &uf_interfaces::srv::typesupport_fastrtps_cpp::_GeoConv__handle;
}

#ifdef __cplusplus
}
#endif
