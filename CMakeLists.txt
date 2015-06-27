cmake_minimum_required(VERSION 3.2)
project(BrainfckInterpreterC__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wextra")

set(SOURCE_FILES main.cpp)
add_executable(BrainfckInterpreterC__ ${SOURCE_FILES})