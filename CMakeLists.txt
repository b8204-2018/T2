cmake_minimum_required(VERSION 3.12)
project(T2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(T2
        src/translit.cpp
        src/translit.h
        CMakeLists.txt
        main.cpp)
