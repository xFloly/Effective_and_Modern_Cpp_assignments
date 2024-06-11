cmake_minimum_required(VERSION 3.27)
project(VectorLibrary)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_FILES
    Solutions/main.cpp
)

set(MODULE_FILES
    Solutions/vector_traits.cppm
    Solutions/vector_policies.cppm
    Solutions/vector.cppm
)

add_library(emcpp_vector STATIC ${MODULE_FILES})

add_executable(main_exe ${SRC_FILES})

target_link_libraries(main_exe PRIVATE emcpp_vector)

target_compile_options(emcpp_vector PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fmodules-ts>)
target_compile_options(main_exe PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fmodules-ts>)

add_dependencies(main_exe emcpp_vector)

add_custom_target(link_main
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts $<TARGET_OBJECTS:emcpp_vector> $<TARGET_OBJECTS:main_exe> -o main
    DEPENDS emcpp_vector main_exe
)
