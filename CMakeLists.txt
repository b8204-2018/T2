cmake_minimum_required(VERSION 3.12)
project(T2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(cmake-build-debug)
include_directories(src)

add_executable(T2
    .idea/codeStyles/Project.xml
    .idea/misc.xml
    .idea/modules.xml
    .idea/T2.iml
    .idea/vcs.xml
    .idea/workspace.xml
    cmake-build-debug/CMakeCache.txt
    src/translit.cpp
    src/translit.h
    CMakeLists.txt
    main.cpp
    README.md)
