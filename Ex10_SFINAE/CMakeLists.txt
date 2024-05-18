cmake_minimum_required(VERSION 3.27)
project(Ex10_SFINAE)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ex1
        ex_10_1.cpp
        Solution/Ex1.h
        Solution/Timer.cpp)

add_executable(Ex2 ex_10_2_tag_dispaching.cpp
        Solution/Ex2.h)

add_executable(Ex3
        ex_10_3_chrono.cpp
        Solution/Ex3_Timer.h
        Solution/Timer.cpp)
