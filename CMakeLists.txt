cmake_minimum_required(VERSION 3.22)

project(hermes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binaries)

include("3rdparty-refs/Qt.cmake")

add_subdirectory("sources")