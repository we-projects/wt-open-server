cmake_minimum_required(VERSION 3.0)

project(expre_pars_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_definitions("-g -Wall")

AUX_SOURCE_DIRECTORY(. DIR_SOURCE)
AUX_SOURCE_DIRECTORY(src DIR_SOURCE)

add_library(expre_parser STATIC ${DIR_SOURCE})
