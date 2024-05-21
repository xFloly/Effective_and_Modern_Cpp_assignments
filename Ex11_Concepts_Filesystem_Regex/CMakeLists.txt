cmake_minimum_required(VERSION 3.27)
project(Ex11_Concepts_Filesystem_Regex)

set(CMAKE_CXX_STANDARD 20)

add_executable(Literals
        literals.cpp
        Solutions/Literals.h)

add_executable(FileSystem
        paths.cpp
        Solutions/FileSystem.h)

add_executable(Container
        concepts.cpp
        Solutions/ConceptsContainer.h
        paths.cpp
)

