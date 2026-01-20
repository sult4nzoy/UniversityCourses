cmake_minimum_required(VERSION 3.31)
project(projekt)

set(CMAKE_CXX_STANDARD 26)

set(SFML_DIR "C:/cpp_libraries/SFML-3.0.0/lib/cmake/SFML")

find_package(SFML 3 REQUIRED Graphics Window System)


add_executable(projekt main.cpp
        int_buffer.cpp
        int_buffer.h
        int_sorted.cpp
        int_sorted.h)

target_link_libraries(projekt
        SFML::Graphics
        SFML::Window
        SFML::System
)