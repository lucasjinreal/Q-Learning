cmake_minimum_required(VERSION 3.6)
project(QLearning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp utils/utils.cpp utils/utils.h)
add_executable(QLearning ${SOURCE_FILES})