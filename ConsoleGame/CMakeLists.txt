cmake_minimum_required(VERSION 3.30)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(untitled1 main.cpp
        Classes/Map.cpp
        Classes/Map.h
        Enums/Difficulty.cpp
        Classes/Math.cpp
        Classes/Math.h
        Classes/Terminal.cpp
        Classes/Terminal.h
        Classes/Enemy.cpp
        Classes/Enemy.h
        Classes/Player.cpp
        Classes/Player.h
)
