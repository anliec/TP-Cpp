cmake_minimum_required(VERSION 3.3)
project(TP-Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BoolContainer.cpp BoolContainer.h errorCode.h Test.cpp)
add_executable(Tp-Cpp ${SOURCE_FILES})