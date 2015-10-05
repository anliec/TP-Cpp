cmake_minimum_required(VERSION 3.3)
project(C__TP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Test.cpp Test.h)
add_executable(C__TP1 ${SOURCE_FILES})