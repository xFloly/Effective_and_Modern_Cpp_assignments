<<<<<<< Updated upstream
cmake_minimum_required(VERSION 3.00)
=======
cmake_minimum_required(VERSION 3.27)
>>>>>>> Stashed changes
project(Ex07_Traits&Policies)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex1_type_traits ex_7_1_type_traits.cpp)
<<<<<<< Updated upstream
add_executable(ex2_traits ex_7_2_Vector_traits.cpp
        Solutions/vector_traits.h
        Solutions/vector_policies.h
        Solutions/Vector.h)
add_executable(ex3_policies ex_7_3_Vector_policies.cpp
        Solutions/vector_policies.h
        Solutions/vector_traits.h
        Solutions/Vector.h)
add_executable(ex4_operators ex_7_4_Vector_operators.cpp
        Solutions/Nodes.h)
=======
add_executable(ex2_traits ex_7_2_Vector_traits.cpp)
add_executable(ex3_policies ex_7_3_Vector_policies.cpp)
add_executable(ex4_operators ex_7_4_Vector_operators.cpp)
>>>>>>> Stashed changes
