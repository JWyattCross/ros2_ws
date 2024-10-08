// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from uf_interfaces:srv/GeoConv.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "uf_interfaces/srv/detail/geo_conv__struct.h"
#include "uf_interfaces/srv/detail/geo_conv__type_support.h"
#include "uf_interfaces/srv/detail/geo_conv__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace uf_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GeoConv_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GeoConv_Request_type_support_ids_t;

static const _GeoConv_Request_type_support_ids_t _GeoConv_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GeoConv_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GeoConv_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GeoConv_Request_type_support_symbol_names_t _GeoConv_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uf_interfaces, srv, GeoConv_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, GeoConv_Request)),
  }
};

typedef struct _GeoConv_Request_type_support_data_t
{
  void * data[2];
} _GeoConv_Request_type_support_data_t;

static _GeoConv_Request_type_support_data_t _GeoConv_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GeoConv_Request_message_typesupport_map = {
  2,
  "uf_interfaces",
  &_GeoConv_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GeoConv_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GeoConv_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GeoConv_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GeoConv_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &uf_interfaces__srv__GeoConv_Request__get_type_hash,
  &uf_interfaces__srv__GeoConv_Request__get_type_description,
  &uf_interfaces__srv__GeoConv_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace uf_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, uf_interfaces, srv, GeoConv_Request)() {
  return &::uf_interfaces::srv::rosidl_typesupport_c::GeoConv_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uf_interfaces/srv/detail/geo_conv__struct.h"
// already included above
// #include "uf_interfaces/srv/detail/geo_conv__type_support.h"
// already included above
// #include "uf_interfaces/srv/detail/geo_conv__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uf_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GeoConv_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GeoConv_Response_type_support_ids_t;

static const _GeoConv_Response_type_support_ids_t _GeoConv_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GeoConv_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GeoConv_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GeoConv_Response_type_support_symbol_names_t _GeoConv_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uf_interfaces, srv, GeoConv_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, GeoConv_Response)),
  }
};

typedef struct _GeoConv_Response_type_support_data_t
{
  void * data[2];
} _GeoConv_Response_type_support_data_t;

static _GeoConv_Response_type_support_data_t _GeoConv_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GeoConv_Response_message_typesupport_map = {
  2,
  "uf_interfaces",
  &_GeoConv_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GeoConv_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GeoConv_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GeoConv_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GeoConv_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &uf_interfaces__srv__GeoConv_Response__get_type_hash,
  &uf_interfaces__srv__GeoConv_Response__get_type_description,
  &uf_interfaces__srv__GeoConv_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace uf_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, uf_interfaces, srv, GeoConv_Response)() {
  return &::uf_interfaces::srv::rosidl_typesupport_c::GeoConv_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uf_interfaces/srv/detail/geo_conv__struct.h"
// already included above
// #include "uf_interfaces/srv/detail/geo_conv__type_support.h"
// already included above
// #include "uf_interfaces/srv/detail/geo_conv__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uf_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GeoConv_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GeoConv_Event_type_support_ids_t;

static const _GeoConv_Event_type_support_ids_t _GeoConv_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GeoConv_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GeoConv_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GeoConv_Event_type_support_symbol_names_t _GeoConv_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uf_interfaces, srv, GeoConv_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, GeoConv_Event)),
  }
};

typedef struct _GeoConv_Event_type_support_data_t
{
  void * data[2];
} _GeoConv_Event_type_support_data_t;

static _GeoConv_Event_type_support_data_t _GeoConv_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GeoConv_Event_message_typesupport_map = {
  2,
  "uf_interfaces",
  &_GeoConv_Event_message_typesupport_ids.typesupport_identifier[0],
  &_GeoConv_Event_message_typesupport_symbol_names.symbol_name[0],
  &_GeoConv_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GeoConv_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GeoConv_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &uf_interfaces__srv__GeoConv_Event__get_type_hash,
  &uf_interfaces__srv__GeoConv_Event__get_type_description,
  &uf_interfaces__srv__GeoConv_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace uf_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, uf_interfaces, srv, GeoConv_Event)() {
  return &::uf_interfaces::srv::rosidl_typesupport_c::GeoConv_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "uf_interfaces/srv/detail/geo_conv__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace uf_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _GeoConv_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GeoConv_type_support_ids_t;

static const _GeoConv_type_support_ids_t _GeoConv_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GeoConv_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GeoConv_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GeoConv_type_support_symbol_names_t _GeoConv_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uf_interfaces, srv, GeoConv)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, GeoConv)),
  }
};

typedef struct _GeoConv_type_support_data_t
{
  void * data[2];
} _GeoConv_type_support_data_t;

static _GeoConv_type_support_data_t _GeoConv_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GeoConv_service_typesupport_map = {
  2,
  "uf_interfaces",
  &_GeoConv_service_typesupport_ids.typesupport_identifier[0],
  &_GeoConv_service_typesupport_symbol_names.symbol_name[0],
  &_GeoConv_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GeoConv_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GeoConv_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &GeoConv_Request_message_type_support_handle,
  &GeoConv_Response_message_type_support_handle,
  &GeoConv_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    uf_interfaces,
    srv,
    GeoConv
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    uf_interfaces,
    srv,
    GeoConv
  ),
  &uf_interfaces__srv__GeoConv__get_type_hash,
  &uf_interfaces__srv__GeoConv__get_type_description,
  &uf_interfaces__srv__GeoConv__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace uf_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, uf_interfaces, srv, GeoConv)() {
  return &::uf_interfaces::srv::rosidl_typesupport_c::GeoConv_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
