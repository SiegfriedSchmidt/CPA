cmake_minimum_required(VERSION 3.22)
project(CPA)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPA main.cpp)
add_executable(random_numbers random/random_numbers.cpp)
add_executable(ordered_set ordered_set/ordered_set.cpp)

add_executable(1 test/1.cpp)
add_executable(segment_tree segment_tree/segment_tree.cpp)