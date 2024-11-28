cmake_minimum_required(VERSION 3.30)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        Classes/Map.cpp
        Classes/Map.h
        Enums/Difficulty.cpp
        Classes/MapRenderer.cpp
        Classes/MapRenderer.h)
