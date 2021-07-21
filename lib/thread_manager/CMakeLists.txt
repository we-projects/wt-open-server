cmake_minimum_required(VERSION 3.0)

project(thread_mgr_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_definitions("-g -Wall")

add_library(thread_mgr STATIC
    src/thread_manager.cpp
)
