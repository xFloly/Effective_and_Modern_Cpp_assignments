cmake_minimum_required(VERSION 3.27)
project(Ex06_VariadicTemplate)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "C:/Program Files/boost_1_84_0")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/libs")

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(VariadicFunctions
        ex1_variadicFunctions.cpp
        Solutions/Functions.h)

add_executable(Mixins
        ex3_Mixins.cpp
        Solutions/Mixins.h)

add_executable(Proxy
        proxy.cpp
        Solutions/Proxy.h)

add_executable(MultiVector
        ex4_MultiVector.cpp
        Solutions/MultiVector.h
)


target_link_libraries(Proxy ${Boost_LIBRARIES})
