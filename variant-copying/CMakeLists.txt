cmake_minimum_required(VERSION 3.5.1)

project(Variant_demo)
set(CMAKE_CXX_STANDARD 11)
set(TARGET variant_demo)
set(SOURCES var.cpp)

include_directories(${TARGET} PRIVATE "c:/Users/praka/workspace/third-party/boost")

add_executable(${TARGET} ${SOURCES})

message(STATUS "${MY_INC_PATH}")

target_include_directories(${TARGET} PRIVATE $ENV{MY_INC_PATH}/boost)
