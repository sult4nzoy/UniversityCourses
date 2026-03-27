cmake_minimum_required(VERSION 4.1)
project(labb1)

set(CMAKE_CXX_STANDARD 20)

add_executable(labb1 main.cpp
        reader.cpp
        reader.h
        graph.cpp
        graph.h
        dijkstras.cpp
        dijkstras.h)
