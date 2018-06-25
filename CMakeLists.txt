cmake_minimum_required(VERSION 3.10)
project(cs_academy)

set(CMAKE_CXX_STANDARD 11)
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DTTINPUT" )

add_executable(cs_academy leetcode/integer-to-roman.cpp)