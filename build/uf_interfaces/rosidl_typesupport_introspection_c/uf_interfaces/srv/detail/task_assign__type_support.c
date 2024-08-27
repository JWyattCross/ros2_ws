// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uf_interfaces:srv/TaskAssign.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uf_interfaces/srv/detail/task_assign__rosidl_typesupport_introspection_c.h"
#include "uf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uf_interfaces/srv/detail/task_assign__functions.h"
#include "uf_interfaces/srv/detail/task_assign__struct.h"


// Include directives for member types
// Member `target`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uf_interfaces__srv__TaskAssign_Request__init(message_memory);
}

void uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_fini_function(void * message_memory)
{
  uf_interfaces__srv__TaskAssign_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_member_array[1] = {
  {
    "target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uf_interfaces__srv__TaskAssign_Request, target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_members = {
  "uf_interfaces__srv",  // message namespace
  "TaskAssign_Request",  // message name
  1,  // number of fields
  sizeof(uf_interfaces__srv__TaskAssign_Request),
  false,  // has_any_key_member_
  uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_member_array,  // message members
  uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_type_support_handle = {
  0,
  &uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_members,
  get_message_typesupport_handle_function,
  &uf_interfaces__srv__TaskAssign_Request__get_type_hash,
  &uf_interfaces__srv__TaskAssign_Request__get_type_description,
  &uf_interfaces__srv__TaskAssign_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uf_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Request)() {
  if (!uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_type_support_handle.typesupport_identifier) {
    uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "uf_interfaces/srv/detail/task_assign__rosidl_typesupport_introspection_c.h"
// already included above
// #include "uf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "uf_interfaces/srv/detail/task_assign__functions.h"
// already included above
// #include "uf_interfaces/srv/detail/task_assign__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uf_interfaces__srv__TaskAssign_Response__init(message_memory);
}

void uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_fini_function(void * message_memory)
{
  uf_interfaces__srv__TaskAssign_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uf_interfaces__srv__TaskAssign_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uf_interfaces__srv__TaskAssign_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_members = {
  "uf_interfaces__srv",  // message namespace
  "TaskAssign_Response",  // message name
  2,  // number of fields
  sizeof(uf_interfaces__srv__TaskAssign_Response),
  false,  // has_any_key_member_
  uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_member_array,  // message members
  uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_type_support_handle = {
  0,
  &uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_members,
  get_message_typesupport_handle_function,
  &uf_interfaces__srv__TaskAssign_Response__get_type_hash,
  &uf_interfaces__srv__TaskAssign_Response__get_type_description,
  &uf_interfaces__srv__TaskAssign_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uf_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Response)() {
  if (!uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_type_support_handle.typesupport_identifier) {
    uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "uf_interfaces/srv/detail/task_assign__rosidl_typesupport_introspection_c.h"
// already included above
// #include "uf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "uf_interfaces/srv/detail/task_assign__functions.h"
// already included above
// #include "uf_interfaces/srv/detail/task_assign__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "uf_interfaces/srv/task_assign.h"
// Member `request`
// Member `response`
// already included above
// #include "uf_interfaces/srv/detail/task_assign__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uf_interfaces__srv__TaskAssign_Event__init(message_memory);
}

void uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_fini_function(void * message_memory)
{
  uf_interfaces__srv__TaskAssign_Event__fini(message_memory);
}

size_t uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__size_function__TaskAssign_Event__request(
  const void * untyped_member)
{
  const uf_interfaces__srv__TaskAssign_Request__Sequence * member =
    (const uf_interfaces__srv__TaskAssign_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_const_function__TaskAssign_Event__request(
  const void * untyped_member, size_t index)
{
  const uf_interfaces__srv__TaskAssign_Request__Sequence * member =
    (const uf_interfaces__srv__TaskAssign_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_function__TaskAssign_Event__request(
  void * untyped_member, size_t index)
{
  uf_interfaces__srv__TaskAssign_Request__Sequence * member =
    (uf_interfaces__srv__TaskAssign_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__fetch_function__TaskAssign_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uf_interfaces__srv__TaskAssign_Request * item =
    ((const uf_interfaces__srv__TaskAssign_Request *)
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_const_function__TaskAssign_Event__request(untyped_member, index));
  uf_interfaces__srv__TaskAssign_Request * value =
    (uf_interfaces__srv__TaskAssign_Request *)(untyped_value);
  *value = *item;
}

void uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__assign_function__TaskAssign_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uf_interfaces__srv__TaskAssign_Request * item =
    ((uf_interfaces__srv__TaskAssign_Request *)
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_function__TaskAssign_Event__request(untyped_member, index));
  const uf_interfaces__srv__TaskAssign_Request * value =
    (const uf_interfaces__srv__TaskAssign_Request *)(untyped_value);
  *item = *value;
}

bool uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__resize_function__TaskAssign_Event__request(
  void * untyped_member, size_t size)
{
  uf_interfaces__srv__TaskAssign_Request__Sequence * member =
    (uf_interfaces__srv__TaskAssign_Request__Sequence *)(untyped_member);
  uf_interfaces__srv__TaskAssign_Request__Sequence__fini(member);
  return uf_interfaces__srv__TaskAssign_Request__Sequence__init(member, size);
}

size_t uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__size_function__TaskAssign_Event__response(
  const void * untyped_member)
{
  const uf_interfaces__srv__TaskAssign_Response__Sequence * member =
    (const uf_interfaces__srv__TaskAssign_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_const_function__TaskAssign_Event__response(
  const void * untyped_member, size_t index)
{
  const uf_interfaces__srv__TaskAssign_Response__Sequence * member =
    (const uf_interfaces__srv__TaskAssign_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_function__TaskAssign_Event__response(
  void * untyped_member, size_t index)
{
  uf_interfaces__srv__TaskAssign_Response__Sequence * member =
    (uf_interfaces__srv__TaskAssign_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__fetch_function__TaskAssign_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uf_interfaces__srv__TaskAssign_Response * item =
    ((const uf_interfaces__srv__TaskAssign_Response *)
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_const_function__TaskAssign_Event__response(untyped_member, index));
  uf_interfaces__srv__TaskAssign_Response * value =
    (uf_interfaces__srv__TaskAssign_Response *)(untyped_value);
  *value = *item;
}

void uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__assign_function__TaskAssign_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uf_interfaces__srv__TaskAssign_Response * item =
    ((uf_interfaces__srv__TaskAssign_Response *)
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_function__TaskAssign_Event__response(untyped_member, index));
  const uf_interfaces__srv__TaskAssign_Response * value =
    (const uf_interfaces__srv__TaskAssign_Response *)(untyped_value);
  *item = *value;
}

bool uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__resize_function__TaskAssign_Event__response(
  void * untyped_member, size_t size)
{
  uf_interfaces__srv__TaskAssign_Response__Sequence * member =
    (uf_interfaces__srv__TaskAssign_Response__Sequence *)(untyped_member);
  uf_interfaces__srv__TaskAssign_Response__Sequence__fini(member);
  return uf_interfaces__srv__TaskAssign_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uf_interfaces__srv__TaskAssign_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(uf_interfaces__srv__TaskAssign_Event, request),  // bytes offset in struct
    NULL,  // default value
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__size_function__TaskAssign_Event__request,  // size() function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_const_function__TaskAssign_Event__request,  // get_const(index) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_function__TaskAssign_Event__request,  // get(index) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__fetch_function__TaskAssign_Event__request,  // fetch(index, &value) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__assign_function__TaskAssign_Event__request,  // assign(index, value) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__resize_function__TaskAssign_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(uf_interfaces__srv__TaskAssign_Event, response),  // bytes offset in struct
    NULL,  // default value
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__size_function__TaskAssign_Event__response,  // size() function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_const_function__TaskAssign_Event__response,  // get_const(index) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__get_function__TaskAssign_Event__response,  // get(index) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__fetch_function__TaskAssign_Event__response,  // fetch(index, &value) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__assign_function__TaskAssign_Event__response,  // assign(index, value) function pointer
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__resize_function__TaskAssign_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_members = {
  "uf_interfaces__srv",  // message namespace
  "TaskAssign_Event",  // message name
  3,  // number of fields
  sizeof(uf_interfaces__srv__TaskAssign_Event),
  false,  // has_any_key_member_
  uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_member_array,  // message members
  uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_type_support_handle = {
  0,
  &uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_members,
  get_message_typesupport_handle_function,
  &uf_interfaces__srv__TaskAssign_Event__get_type_hash,
  &uf_interfaces__srv__TaskAssign_Event__get_type_description,
  &uf_interfaces__srv__TaskAssign_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uf_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Event)() {
  uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Request)();
  uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Response)();
  if (!uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_type_support_handle.typesupport_identifier) {
    uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "uf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "uf_interfaces/srv/detail/task_assign__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_service_members = {
  "uf_interfaces__srv",  // service namespace
  "TaskAssign",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_Request_message_type_support_handle,
  NULL,  // response message
  // uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_Response_message_type_support_handle
  NULL  // event_message
  // uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_Response_message_type_support_handle
};


static rosidl_service_type_support_t uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_service_type_support_handle = {
  0,
  &uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_service_members,
  get_service_typesupport_handle_function,
  &uf_interfaces__srv__TaskAssign_Request__rosidl_typesupport_introspection_c__TaskAssign_Request_message_type_support_handle,
  &uf_interfaces__srv__TaskAssign_Response__rosidl_typesupport_introspection_c__TaskAssign_Response_message_type_support_handle,
  &uf_interfaces__srv__TaskAssign_Event__rosidl_typesupport_introspection_c__TaskAssign_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    uf_interfaces,
    srv,
    TaskAssign
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    uf_interfaces,
    srv,
    TaskAssign
  ),
  &uf_interfaces__srv__TaskAssign__get_type_hash,
  &uf_interfaces__srv__TaskAssign__get_type_description,
  &uf_interfaces__srv__TaskAssign__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uf_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign)(void) {
  if (!uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_service_type_support_handle.typesupport_identifier) {
    uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uf_interfaces, srv, TaskAssign_Event)()->data;
  }

  return &uf_interfaces__srv__detail__task_assign__rosidl_typesupport_introspection_c__TaskAssign_service_type_support_handle;
}
