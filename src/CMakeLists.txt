cmake_minimum_required(VERSION 2.8)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

project(CE3D)

set(CE3D_VERSION_MAJOR 0)
set(CE3D_VERSION_MINOR 0)
set(CE3D_VERSION_MICRO 1)

find_package(Boost REQUIRED)

# Get the current working branch
execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_HEAD
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# TODO we need some dependency checking here -> boost

configure_file(
    "${PROJECT_SOURCE_DIR}/CE3D_config.h.in"
    "${PROJECT_BINARY_DIR}/CE3D_config.h"
    )

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_BINARY_DIR}")


add_subdirectory("util")
add_subdirectory("world")
add_subdirectory("model")
add_subdirectory("console")

add_library(CE3D STATIC ${SRC})
