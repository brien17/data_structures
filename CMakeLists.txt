cmake_minimum_required(VERSION 3.14)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures src/main.cpp src/double_linked_list.cpp src/double_linked_list.h src/word_tree.cpp src/word_tree.h)