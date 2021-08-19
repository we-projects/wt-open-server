cmake_minimum_required(VERSION 3.10) 

# set the project name 
project(gay_server) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/bin)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/lib/g_log/include
    ${PROJECT_SOURCE_DIR}/lib/expre_to_json/include
)

AUX_SOURCE_DIRECTORY(. DIR_SOURCE)
AUX_SOURCE_DIRECTORY(src DIR_SOURCE)

add_definitions("-g -Wall")

ADD_EXECUTABLE(gay_server ${DIR_SOURCE})

TARGET_LINK_LIBRARIES(gay_server 
    libg_log.a 
    libexpre_parser.a
)
