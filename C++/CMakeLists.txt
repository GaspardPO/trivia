cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C__
        Game.cpp
        Game.h
        GameRunner.cpp
        )


add_subdirectory(Google_tests)
