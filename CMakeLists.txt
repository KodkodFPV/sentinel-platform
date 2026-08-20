cmake_minimum_required(VERSION 3.16)

project(sentinel-platform LANGUAGES CXX)

option(SENTINEL_PLATFORM_BUILD_DOCS "Build the Doxygen documentation" OFF)

# Sentinel platform target
set(SENTINEL_PLATFORM "none" CACHE STRING "sentinel platform backend")

# Set root directory
set(SENTINEL_PLATFORM_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

# Select platform
set_property(CACHE SENTINEL_PLATFORM PROPERTY STRINGS none esp stderr)

if(SENTINEL_PLATFORM STREQUAL "none")
  set(SENTINEL_PLATFORM_DIR "${SENTINEL_PLATFORM_ROOT_DIR}/none")
  set(SENTINEL_PLATFORM_TARGET platform_none)
elseif(SENTINEL_PLATFORM STREQUAL "esp")
  set(SENTINEL_PLATFORM_DIR "${SENTINEL_PLATFORM_ROOT_DIR}/esp")
  set(SENTINEL_PLATFORM_TARGET platform_esp)
elseif(SENTINEL_PLATFORM STREQUAL "stderr")
  set(SENTINEL_PLATFORM_DIR "${SENTINEL_PLATFORM_ROOT_DIR}/stderr")
  set(SENTINEL_PLATFORM_TARGET platform_stderr)
else()
  message(FATAL_ERROR "Unsupported sentinel platform backend: ${SENTINEL_PLATFORM}")
endif()

if(NOT EXISTS "${SENTINEL_PLATFORM_DIR}/platform.hpp")
  message(FATAL_ERROR "Unsupported sentinel platform backend: ${SENTINEL_PLATFORM}")
endif()

add_library(${SENTINEL_PLATFORM_TARGET} INTERFACE)
add_library(sentinel::${SENTINEL_PLATFORM_TARGET} ALIAS ${SENTINEL_PLATFORM_TARGET})

target_include_directories(${SENTINEL_PLATFORM_TARGET}
  INTERFACE
    "${SENTINEL_PLATFORM_DIR}"
)

# Doxygen documentation
if(SENTINEL_PLATFORM_BUILD_DOCS)
  find_package(Doxygen REQUIRED)

  set(SENTINEL_PLATFORM_DOXYGEN_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/docs")

  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
    @ONLY
  )

  add_custom_target(sentinel-platform.docs
    COMMAND
      ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_SOURCE_DIR}"
    COMMENT
      "Generating sentinel-platform Doxygen documentation"
    VERBATIM
  )
endif()
