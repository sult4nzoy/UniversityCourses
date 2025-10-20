cmake_minimum_required(VERSION 3.31)
project(tentaPlugg)

set(CMAKE_CXX_STANDARD 26)

add_executable(tentaPlugg main.cpp
        cmake-build-release/blaa.cpp
        cmake-build-release/blaa.h
)
