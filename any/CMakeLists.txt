cmake_minimum_required(VERSION 3.5.1)

project(Message-Properties-with-Flags)
set(CMAKE_CXX_STANDARD 11)
set(TARGET any)
set(SOURCES any.cpp)

add_executable(${TARGET} ${SOURCES})

message(STATUS "${MY_INC_PATH}")

target_include_directories(${TARGET} PRIVATE $ENV{MY_INC_PATH}/boost)
