// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from uf_interfaces:srv/TaskAssign.idl
// generated code does not contain a copyright notice

#include "uf_interfaces/srv/detail/task_assign__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
const rosidl_type_hash_t *
uf_interfaces__srv__TaskAssign__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbf, 0x3e, 0xd1, 0xf1, 0x13, 0x5e, 0xeb, 0x5b,
      0x35, 0xbd, 0x94, 0xef, 0xc3, 0x13, 0xb5, 0x16,
      0xd5, 0xc7, 0xc9, 0xc5, 0xa1, 0xe5, 0x62, 0xfd,
      0xbf, 0x70, 0x6b, 0x6f, 0xad, 0xaf, 0x54, 0xd0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
const rosidl_type_hash_t *
uf_interfaces__srv__TaskAssign_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa4, 0xcc, 0xfd, 0x60, 0xf7, 0xc8, 0xb6, 0xf1,
      0xba, 0x9a, 0xd0, 0x07, 0x4e, 0xa3, 0x43, 0xfc,
      0xe8, 0x7e, 0xce, 0x24, 0x7e, 0x5b, 0x13, 0x81,
      0xc1, 0x61, 0x6e, 0xb4, 0x40, 0xb2, 0xb1, 0x7a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
const rosidl_type_hash_t *
uf_interfaces__srv__TaskAssign_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x42, 0x8e, 0xd6, 0x3b, 0x22, 0x86, 0xa4, 0x12,
      0x25, 0x53, 0xab, 0x51, 0x45, 0xcd, 0x32, 0x8c,
      0x69, 0xea, 0x0b, 0xd9, 0x99, 0xc5, 0x0c, 0xab,
      0x4b, 0x0e, 0x55, 0x18, 0xfd, 0x8d, 0x50, 0x5e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
const rosidl_type_hash_t *
uf_interfaces__srv__TaskAssign_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfc, 0x1e, 0x61, 0x32, 0xc1, 0x57, 0xcb, 0x1a,
      0x71, 0x6e, 0x1f, 0x6f, 0x5e, 0xfc, 0xf4, 0x3d,
      0x9a, 0xdc, 0x5d, 0x9f, 0xdf, 0x9a, 0x91, 0x19,
      0x7a, 0xe0, 0xaa, 0x7e, 0x81, 0x06, 0xed, 0xf6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char uf_interfaces__srv__TaskAssign__TYPE_NAME[] = "uf_interfaces/srv/TaskAssign";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char uf_interfaces__srv__TaskAssign_Event__TYPE_NAME[] = "uf_interfaces/srv/TaskAssign_Event";
static char uf_interfaces__srv__TaskAssign_Request__TYPE_NAME[] = "uf_interfaces/srv/TaskAssign_Request";
static char uf_interfaces__srv__TaskAssign_Response__TYPE_NAME[] = "uf_interfaces/srv/TaskAssign_Response";

// Define type names, field names, and default values
static char uf_interfaces__srv__TaskAssign__FIELD_NAME__request_message[] = "request_message";
static char uf_interfaces__srv__TaskAssign__FIELD_NAME__response_message[] = "response_message";
static char uf_interfaces__srv__TaskAssign__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field uf_interfaces__srv__TaskAssign__FIELDS[] = {
  {
    {uf_interfaces__srv__TaskAssign__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {uf_interfaces__srv__TaskAssign_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {uf_interfaces__srv__TaskAssign_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {uf_interfaces__srv__TaskAssign_Event__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription uf_interfaces__srv__TaskAssign__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Event__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
uf_interfaces__srv__TaskAssign__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {uf_interfaces__srv__TaskAssign__TYPE_NAME, 28, 28},
      {uf_interfaces__srv__TaskAssign__FIELDS, 3, 3},
    },
    {uf_interfaces__srv__TaskAssign__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = uf_interfaces__srv__TaskAssign_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = uf_interfaces__srv__TaskAssign_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = uf_interfaces__srv__TaskAssign_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char uf_interfaces__srv__TaskAssign_Request__FIELD_NAME__target[] = "target";

static rosidl_runtime_c__type_description__Field uf_interfaces__srv__TaskAssign_Request__FIELDS[] = {
  {
    {uf_interfaces__srv__TaskAssign_Request__FIELD_NAME__target, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
uf_interfaces__srv__TaskAssign_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {uf_interfaces__srv__TaskAssign_Request__TYPE_NAME, 36, 36},
      {uf_interfaces__srv__TaskAssign_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char uf_interfaces__srv__TaskAssign_Response__FIELD_NAME__success[] = "success";
static char uf_interfaces__srv__TaskAssign_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field uf_interfaces__srv__TaskAssign_Response__FIELDS[] = {
  {
    {uf_interfaces__srv__TaskAssign_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
uf_interfaces__srv__TaskAssign_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {uf_interfaces__srv__TaskAssign_Response__TYPE_NAME, 37, 37},
      {uf_interfaces__srv__TaskAssign_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char uf_interfaces__srv__TaskAssign_Event__FIELD_NAME__info[] = "info";
static char uf_interfaces__srv__TaskAssign_Event__FIELD_NAME__request[] = "request";
static char uf_interfaces__srv__TaskAssign_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field uf_interfaces__srv__TaskAssign_Event__FIELDS[] = {
  {
    {uf_interfaces__srv__TaskAssign_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {uf_interfaces__srv__TaskAssign_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {uf_interfaces__srv__TaskAssign_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription uf_interfaces__srv__TaskAssign_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {uf_interfaces__srv__TaskAssign_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
uf_interfaces__srv__TaskAssign_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {uf_interfaces__srv__TaskAssign_Event__TYPE_NAME, 34, 34},
      {uf_interfaces__srv__TaskAssign_Event__FIELDS, 3, 3},
    },
    {uf_interfaces__srv__TaskAssign_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = uf_interfaces__srv__TaskAssign_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = uf_interfaces__srv__TaskAssign_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string target\n"
  "---\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
uf_interfaces__srv__TaskAssign__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {uf_interfaces__srv__TaskAssign__TYPE_NAME, 28, 28},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 46, 46},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
uf_interfaces__srv__TaskAssign_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {uf_interfaces__srv__TaskAssign_Request__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
uf_interfaces__srv__TaskAssign_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {uf_interfaces__srv__TaskAssign_Response__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
uf_interfaces__srv__TaskAssign_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {uf_interfaces__srv__TaskAssign_Event__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
uf_interfaces__srv__TaskAssign__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *uf_interfaces__srv__TaskAssign__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *uf_interfaces__srv__TaskAssign_Event__get_individual_type_description_source(NULL);
    sources[4] = *uf_interfaces__srv__TaskAssign_Request__get_individual_type_description_source(NULL);
    sources[5] = *uf_interfaces__srv__TaskAssign_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
uf_interfaces__srv__TaskAssign_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *uf_interfaces__srv__TaskAssign_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
uf_interfaces__srv__TaskAssign_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *uf_interfaces__srv__TaskAssign_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
uf_interfaces__srv__TaskAssign_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *uf_interfaces__srv__TaskAssign_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *uf_interfaces__srv__TaskAssign_Request__get_individual_type_description_source(NULL);
    sources[4] = *uf_interfaces__srv__TaskAssign_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
