cmake_minimum_required(VERSION 3.7.1)
project(Mushroom)

## Compile as C++14
add_compile_options(-std=c++11)

find_package(PROJ)
add_executable(Mushroom cpp_data_structure/数组/动态数组/vector_demo.cpp cpp_data_structure/string_demo.cpp)
TARGET_LINK_LIBRARIES(Mushroom ${PROJ_LIBRARIES})