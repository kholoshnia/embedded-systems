cmake_minimum_required(VERSION 3.19)
project(lab-1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_1 src/main.cpp
        src/utils/equipment.hpp
        src/utils/animation.hpp
        src/utils/switches.hpp
        src/utils/processor.hpp)