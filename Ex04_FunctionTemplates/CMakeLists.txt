cmake_minimum_required(VERSION 3.27)
project(Ex04_FunctionTemplates)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ex04_FunctionTemplates
        ex_4_1_templates.cpp
        ex_4_2_compare.cpp
        ex_4_3_selectIf.cpp
        Templates.h
        Templates_EX1.tpp)
