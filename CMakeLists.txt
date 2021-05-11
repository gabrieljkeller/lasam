cmake_minimum_required(VERSION 3.17)
project(lasam)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/lasam)

add_executable(lasam
        src/lasam/LASAM.cpp
        src/lasam/LASAM.h)
