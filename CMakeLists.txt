cmake_minimum_required(VERSION 3.13)
project(T2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(T2
        CMakeLists.txt
        main.cpp
        translit.cpp
        translit.h)
