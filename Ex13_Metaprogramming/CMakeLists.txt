cmake_minimum_required(VERSION 3.27)
project(Ex13_Metaprogramming)

set(CMAKE_CXX_STANDARD 20)

add_executable(Recurrent
        ex1_KlasyRekurencyjne.cpp
        Solutions/Binomial.h
        Solutions/Power.h)
add_executable(const
        constinit.cpp
        Solutions/PascalsTriangle.h)
add_executable(IntegerList
        ex3_IntegerList.cpp
        Solutions/IntegerList.h)
