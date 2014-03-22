cmake_minimum_required(VERSION 2.8)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

project(CE3D)

set(CE3D_VERSION_MAJOR 0)
set(CE3D_VERSION_MINOR 1)

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
