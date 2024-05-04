cmake_minimum_required(VERSION 3.00)
project(lab7)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(Range ex_8_1_Range.cpp Solutions/Range.h)

add_executable(MatrixModifiers ex_8_2_MatrixModifiers.cpp Solutions/Matrix.h)

add_executable(MatrixIterator ex_8_3_MatrixIterator.cpp Solutions/Matrix.h)

add_executable(Filter ex_8_4_Filter.cpp Solutions/Filter.h)

