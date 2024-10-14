// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from uf_interfaces:action/Defend.idl
// generated code does not contain a copyright notice

#ifndef UF_INTERFACES__ACTION__DETAIL__DEFEND__FUNCTIONS_H_
#define UF_INTERFACES__ACTION__DETAIL__DEFEND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "uf_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "uf_interfaces/action/detail/defend__struct.h"

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_Goal
 * )) before or use
 * uf_interfaces__action__Defend_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Goal__init(uf_interfaces__action__Defend_Goal * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Goal__fini(uf_interfaces__action__Defend_Goal * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_Goal *
uf_interfaces__action__Defend_Goal__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Goal__destroy(uf_interfaces__action__Defend_Goal * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Goal__are_equal(const uf_interfaces__action__Defend_Goal * lhs, const uf_interfaces__action__Defend_Goal * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Goal__copy(
  const uf_interfaces__action__Defend_Goal * input,
  uf_interfaces__action__Defend_Goal * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Goal__Sequence__init(uf_interfaces__action__Defend_Goal__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Goal__Sequence__fini(uf_interfaces__action__Defend_Goal__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_Goal__Sequence *
uf_interfaces__action__Defend_Goal__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Goal__Sequence__destroy(uf_interfaces__action__Defend_Goal__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Goal__Sequence__are_equal(const uf_interfaces__action__Defend_Goal__Sequence * lhs, const uf_interfaces__action__Defend_Goal__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Goal__Sequence__copy(
  const uf_interfaces__action__Defend_Goal__Sequence * input,
  uf_interfaces__action__Defend_Goal__Sequence * output);

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_Result
 * )) before or use
 * uf_interfaces__action__Defend_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Result__init(uf_interfaces__action__Defend_Result * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Result__fini(uf_interfaces__action__Defend_Result * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_Result *
uf_interfaces__action__Defend_Result__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Result__destroy(uf_interfaces__action__Defend_Result * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Result__are_equal(const uf_interfaces__action__Defend_Result * lhs, const uf_interfaces__action__Defend_Result * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Result__copy(
  const uf_interfaces__action__Defend_Result * input,
  uf_interfaces__action__Defend_Result * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Result__Sequence__init(uf_interfaces__action__Defend_Result__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Result__Sequence__fini(uf_interfaces__action__Defend_Result__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_Result__Sequence *
uf_interfaces__action__Defend_Result__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Result__Sequence__destroy(uf_interfaces__action__Defend_Result__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Result__Sequence__are_equal(const uf_interfaces__action__Defend_Result__Sequence * lhs, const uf_interfaces__action__Defend_Result__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Result__Sequence__copy(
  const uf_interfaces__action__Defend_Result__Sequence * input,
  uf_interfaces__action__Defend_Result__Sequence * output);

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_Feedback
 * )) before or use
 * uf_interfaces__action__Defend_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Feedback__init(uf_interfaces__action__Defend_Feedback * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Feedback__fini(uf_interfaces__action__Defend_Feedback * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_Feedback *
uf_interfaces__action__Defend_Feedback__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Feedback__destroy(uf_interfaces__action__Defend_Feedback * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Feedback__are_equal(const uf_interfaces__action__Defend_Feedback * lhs, const uf_interfaces__action__Defend_Feedback * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Feedback__copy(
  const uf_interfaces__action__Defend_Feedback * input,
  uf_interfaces__action__Defend_Feedback * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Feedback__Sequence__init(uf_interfaces__action__Defend_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Feedback__Sequence__fini(uf_interfaces__action__Defend_Feedback__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_Feedback__Sequence *
uf_interfaces__action__Defend_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_Feedback__Sequence__destroy(uf_interfaces__action__Defend_Feedback__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Feedback__Sequence__are_equal(const uf_interfaces__action__Defend_Feedback__Sequence * lhs, const uf_interfaces__action__Defend_Feedback__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_Feedback__Sequence__copy(
  const uf_interfaces__action__Defend_Feedback__Sequence * input,
  uf_interfaces__action__Defend_Feedback__Sequence * output);

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_SendGoal_Request
 * )) before or use
 * uf_interfaces__action__Defend_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Request__init(uf_interfaces__action__Defend_SendGoal_Request * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Request__fini(uf_interfaces__action__Defend_SendGoal_Request * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_SendGoal_Request *
uf_interfaces__action__Defend_SendGoal_Request__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Request__destroy(uf_interfaces__action__Defend_SendGoal_Request * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Request__are_equal(const uf_interfaces__action__Defend_SendGoal_Request * lhs, const uf_interfaces__action__Defend_SendGoal_Request * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Request__copy(
  const uf_interfaces__action__Defend_SendGoal_Request * input,
  uf_interfaces__action__Defend_SendGoal_Request * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Request__Sequence__init(uf_interfaces__action__Defend_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Request__Sequence__fini(uf_interfaces__action__Defend_SendGoal_Request__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_SendGoal_Request__Sequence *
uf_interfaces__action__Defend_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Request__Sequence__destroy(uf_interfaces__action__Defend_SendGoal_Request__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Request__Sequence__are_equal(const uf_interfaces__action__Defend_SendGoal_Request__Sequence * lhs, const uf_interfaces__action__Defend_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Request__Sequence__copy(
  const uf_interfaces__action__Defend_SendGoal_Request__Sequence * input,
  uf_interfaces__action__Defend_SendGoal_Request__Sequence * output);

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_SendGoal_Response
 * )) before or use
 * uf_interfaces__action__Defend_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Response__init(uf_interfaces__action__Defend_SendGoal_Response * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Response__fini(uf_interfaces__action__Defend_SendGoal_Response * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_SendGoal_Response *
uf_interfaces__action__Defend_SendGoal_Response__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Response__destroy(uf_interfaces__action__Defend_SendGoal_Response * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Response__are_equal(const uf_interfaces__action__Defend_SendGoal_Response * lhs, const uf_interfaces__action__Defend_SendGoal_Response * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Response__copy(
  const uf_interfaces__action__Defend_SendGoal_Response * input,
  uf_interfaces__action__Defend_SendGoal_Response * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Response__Sequence__init(uf_interfaces__action__Defend_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Response__Sequence__fini(uf_interfaces__action__Defend_SendGoal_Response__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_SendGoal_Response__Sequence *
uf_interfaces__action__Defend_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_SendGoal_Response__Sequence__destroy(uf_interfaces__action__Defend_SendGoal_Response__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Response__Sequence__are_equal(const uf_interfaces__action__Defend_SendGoal_Response__Sequence * lhs, const uf_interfaces__action__Defend_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_SendGoal_Response__Sequence__copy(
  const uf_interfaces__action__Defend_SendGoal_Response__Sequence * input,
  uf_interfaces__action__Defend_SendGoal_Response__Sequence * output);

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_GetResult_Request
 * )) before or use
 * uf_interfaces__action__Defend_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Request__init(uf_interfaces__action__Defend_GetResult_Request * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Request__fini(uf_interfaces__action__Defend_GetResult_Request * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_GetResult_Request *
uf_interfaces__action__Defend_GetResult_Request__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Request__destroy(uf_interfaces__action__Defend_GetResult_Request * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Request__are_equal(const uf_interfaces__action__Defend_GetResult_Request * lhs, const uf_interfaces__action__Defend_GetResult_Request * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Request__copy(
  const uf_interfaces__action__Defend_GetResult_Request * input,
  uf_interfaces__action__Defend_GetResult_Request * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Request__Sequence__init(uf_interfaces__action__Defend_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Request__Sequence__fini(uf_interfaces__action__Defend_GetResult_Request__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_GetResult_Request__Sequence *
uf_interfaces__action__Defend_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Request__Sequence__destroy(uf_interfaces__action__Defend_GetResult_Request__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Request__Sequence__are_equal(const uf_interfaces__action__Defend_GetResult_Request__Sequence * lhs, const uf_interfaces__action__Defend_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Request__Sequence__copy(
  const uf_interfaces__action__Defend_GetResult_Request__Sequence * input,
  uf_interfaces__action__Defend_GetResult_Request__Sequence * output);

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_GetResult_Response
 * )) before or use
 * uf_interfaces__action__Defend_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Response__init(uf_interfaces__action__Defend_GetResult_Response * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Response__fini(uf_interfaces__action__Defend_GetResult_Response * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_GetResult_Response *
uf_interfaces__action__Defend_GetResult_Response__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Response__destroy(uf_interfaces__action__Defend_GetResult_Response * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Response__are_equal(const uf_interfaces__action__Defend_GetResult_Response * lhs, const uf_interfaces__action__Defend_GetResult_Response * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Response__copy(
  const uf_interfaces__action__Defend_GetResult_Response * input,
  uf_interfaces__action__Defend_GetResult_Response * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Response__Sequence__init(uf_interfaces__action__Defend_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Response__Sequence__fini(uf_interfaces__action__Defend_GetResult_Response__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_GetResult_Response__Sequence *
uf_interfaces__action__Defend_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_GetResult_Response__Sequence__destroy(uf_interfaces__action__Defend_GetResult_Response__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Response__Sequence__are_equal(const uf_interfaces__action__Defend_GetResult_Response__Sequence * lhs, const uf_interfaces__action__Defend_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_GetResult_Response__Sequence__copy(
  const uf_interfaces__action__Defend_GetResult_Response__Sequence * input,
  uf_interfaces__action__Defend_GetResult_Response__Sequence * output);

/// Initialize action/Defend message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uf_interfaces__action__Defend_FeedbackMessage
 * )) before or use
 * uf_interfaces__action__Defend_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_FeedbackMessage__init(uf_interfaces__action__Defend_FeedbackMessage * msg);

/// Finalize action/Defend message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_FeedbackMessage__fini(uf_interfaces__action__Defend_FeedbackMessage * msg);

/// Create action/Defend message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uf_interfaces__action__Defend_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_FeedbackMessage *
uf_interfaces__action__Defend_FeedbackMessage__create();

/// Destroy action/Defend message.
/**
 * It calls
 * uf_interfaces__action__Defend_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_FeedbackMessage__destroy(uf_interfaces__action__Defend_FeedbackMessage * msg);

/// Check for action/Defend message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_FeedbackMessage__are_equal(const uf_interfaces__action__Defend_FeedbackMessage * lhs, const uf_interfaces__action__Defend_FeedbackMessage * rhs);

/// Copy a action/Defend message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_FeedbackMessage__copy(
  const uf_interfaces__action__Defend_FeedbackMessage * input,
  uf_interfaces__action__Defend_FeedbackMessage * output);

/// Initialize array of action/Defend messages.
/**
 * It allocates the memory for the number of elements and calls
 * uf_interfaces__action__Defend_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_FeedbackMessage__Sequence__init(uf_interfaces__action__Defend_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_FeedbackMessage__Sequence__fini(uf_interfaces__action__Defend_FeedbackMessage__Sequence * array);

/// Create array of action/Defend messages.
/**
 * It allocates the memory for the array and calls
 * uf_interfaces__action__Defend_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
uf_interfaces__action__Defend_FeedbackMessage__Sequence *
uf_interfaces__action__Defend_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Defend messages.
/**
 * It calls
 * uf_interfaces__action__Defend_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
void
uf_interfaces__action__Defend_FeedbackMessage__Sequence__destroy(uf_interfaces__action__Defend_FeedbackMessage__Sequence * array);

/// Check for action/Defend message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_FeedbackMessage__Sequence__are_equal(const uf_interfaces__action__Defend_FeedbackMessage__Sequence * lhs, const uf_interfaces__action__Defend_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Defend messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uf_interfaces
bool
uf_interfaces__action__Defend_FeedbackMessage__Sequence__copy(
  const uf_interfaces__action__Defend_FeedbackMessage__Sequence * input,
  uf_interfaces__action__Defend_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UF_INTERFACES__ACTION__DETAIL__DEFEND__FUNCTIONS_H_
