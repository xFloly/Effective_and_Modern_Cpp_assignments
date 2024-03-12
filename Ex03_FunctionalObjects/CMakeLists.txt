cmake_minimum_required(VERSION 3.27)
project(Ex03_FunctionalObjects)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex03_FunctionalObjects
        FunctionPointers/function_pointers.cpp
        LambdaExpressions/lambda_expressions.cpp
        Printer/Printer.cpp)
