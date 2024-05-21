cmake_minimum_required(VERSION 3.27)
project(Ex12_Threads)

set(CMAKE_CXX_STANDARD 20)

include_directories(mandelbrot)

add_executable(random
        random.cpp)

add_executable(mandelbrot
        mandelbrot/EasyBMP.cpp
        mandelbrot/EasyBMP.h
        mandelbrot/EasyBMP_BMP.h
        mandelbrot/EasyBMP_DataStructures.h
        mandelbrot/EasyBMP_VariousBMPutilities.h
        mandelbrot/ex_11_2_Mandelbrot.cpp)

