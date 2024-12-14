cmake_minimum_required(VERSION 3.29)
project(KorfsRubiksCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(KorfsRubiksCubeSolver main.cpp
        RubiksCube.cpp
        RubiksCube.h
        RubiksCube3d.cpp
)
