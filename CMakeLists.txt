cmake_minimum_required(VERSION 3.16)

project(sentinel-platform LANGUAGES CXX)

if(NOT DEFINED SENTINEL_PLATFORM)
  message(FATAL_ERROR "SENTINEL_PLATFORM is not set")
endif()

set(platform_dir "${CMAKE_CURRENT_SOURCE_DIR}/${SENTINEL_PLATFORM}")
set(platform_target "platform_${SENTINEL_PLATFORM}")

if(NOT EXISTS "${platform_dir}/platform.hpp")
  message(FATAL_ERROR "Unsupported sentinel platform: ${SENTINEL_PLATFORM}")
endif()

add_library(${platform_target} INTERFACE)
add_library(sentinel::${platform_target} ALIAS ${platform_target})

target_include_directories(${platform_target}
  INTERFACE
    "${platform_dir}"
)
