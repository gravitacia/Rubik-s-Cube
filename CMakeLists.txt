cmake_minimum_required(VERSION 3.17)
project(Rubik)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubik main.cpp Cube.cpp Cube.h SolvingAlgorithm.cpp SolvingAlgorithm.h Green.cpp Blue.cpp Red.cpp Orange.cpp)