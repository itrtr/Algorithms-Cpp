cmake_minimum_required(VERSION 3.29)
project(Algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algorithms main.cpp
        src/GraphAlgorithm.cpp
        header/GraphAlgorithm.h
        src/GraphAlgorithm.cpp)
