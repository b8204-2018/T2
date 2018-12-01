cmake_minimum_required(VERSION 3.12)
project(T2)

set(CMAKE_CXX_STANDARD 17)

add_executable(T2 main.cpp src/translit.h src/translit.cpp)