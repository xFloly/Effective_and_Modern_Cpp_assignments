cmake_minimum_required(VERSION 3.00)
project(lab9_STL)

set(CMAKE_CXX_STANDARD 20)

add_executable(1_stlalgorithms ex_9_1_stdalgorithms.cpp
        Solution/Anagram.h)
add_executable(2_words ex_9_2_words.cpp
        Solution/WordCount.h
        Solution/countWords.cpp)
add_executable(3_trie ex_9_3_Trie.cpp
        Solution/Trie.h
        Solution/Trie.cpp)
