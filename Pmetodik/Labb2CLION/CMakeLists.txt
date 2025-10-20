cmake_minimum_required(VERSION 4.0)
project(Labb2CLION)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labb2CLION main.cpp
        shape.cpp
        shape.h
        circle.cpp
        circle.h
        cylinder.cpp
        cylinder.h
        rectangle.cpp
        rectangle.h
        parallelpiped.cpp
        parallelpiped.h
        rounded_rectangle.cpp
        rounded_rectangle.h
        square.cpp
        square.h)
