# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_autonomy_park_viz_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED autonomy_park_viz_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(autonomy_park_viz_FOUND FALSE)
  elseif(NOT autonomy_park_viz_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(autonomy_park_viz_FOUND FALSE)
  endif()
  return()
endif()
set(_autonomy_park_viz_CONFIG_INCLUDED TRUE)

# output package information
if(NOT autonomy_park_viz_FIND_QUIETLY)
  message(STATUS "Found autonomy_park_viz: 0.0.0 (${autonomy_park_viz_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'autonomy_park_viz' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${autonomy_park_viz_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(autonomy_park_viz_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${autonomy_park_viz_DIR}/${_extra}")
endforeach()
