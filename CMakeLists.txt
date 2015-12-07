cmake_minimum_required(VERSION 3.3)
project(TP-Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DataManager.cpp DataManager.h LogOtherInfos.cpp LogOtherInfos.h config.h test.cpp test.h)
add_executable(Tp-Cpp ${SOURCE_FILES})