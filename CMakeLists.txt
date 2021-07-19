cmake_minimum_required(VERSION 3.10) 

# set the project name 
project(gay_server) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

include_directories(
    ${CMAKE_BINARY_DIR}/../include
)

add_executable(gay_server
    src/server.cpp
)


