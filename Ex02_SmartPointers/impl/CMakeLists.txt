cmake_minimum_required(VERSION 3.27)
project(Lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(StaticContainer Ex1_StaticContainer.cpp
        StaticContainer.h)

add_executable(StaticContainer2 Ex2_StaticContainer2.cpp
        StaticContainer2.h)

add_executable(DynamicContainer Ex3_DynamicContainer.cpp
        DynamicContainer.h)

add_executable(String Ex4_String.cpp
        String_my.h
        String.cpp)

