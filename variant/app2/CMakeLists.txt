cmake_minimum_required(VERSION 3.5.1)

project(Application2)
include_directories("c:/Documents and Settings/vaddina/workspace/third-party/boost_1_66_0")
include_directories("..")

add_executable(app2 app2.cpp ../impl/impl.cpp ../if/def.h ../if/supported_if.h ../if/i2c.h ../if/sb.h)



