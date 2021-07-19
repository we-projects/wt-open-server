cmake_minimum_required(VERSION 3.0)

project(gay_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
    ${CMAKE_BINARY_DIR}/../include
    ${CMAKE_BINARY_DIR}/../include/log_frame
)

add_definitions("-g -Wall")

add_library(gay_lib STATIC
    src/log_frame/log_manager.cpp
)
