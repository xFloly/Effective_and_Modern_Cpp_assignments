cmake_minimum_required(VERSION 3.27)
project(Matrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrix main.cpp
        matrix.h
        matrix.cpp
        matrix_with_label.cpp)
