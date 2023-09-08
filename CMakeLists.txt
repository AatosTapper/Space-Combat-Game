cmake_minimum_required(VERSION 3.12)
project(Space-Combat-Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(OpenGL REQUIRED)
find_library(GLFW_LIBRARY glfw3 PATHS dep/lib-arm64)
include_directories(dep/include/GLFW)

add_subdirectory(src)