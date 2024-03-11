cmake_minimum_required(VERSION 3.17)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(DynamicContainer Ex3_DynamicContainer.cpp
        String.cpp
        String.cpp)
add_executable(StaticContainer Ex1_StaticContainer.cpp
        String.cpp
        String.cpp)
add_executable(StaticContainer2 Ex2_StaticContainer2.cpp
        String.cpp
        String.cpp)

add_executable(String Ex4_String.cpp
        String.cpp
        String.cpp)