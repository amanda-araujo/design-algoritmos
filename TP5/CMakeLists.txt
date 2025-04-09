cmake_minimum_required(VERSION 3.30)
project(TP5)

set(CMAKE_CXX_STANDARD 20)

add_executable(TP5 main.cpp
        exercise1_changeMaking.cpp
        exercise2_knapsack01.cpp)
add_executable(exercise1 exercise1_changeMaking.cpp)
add_executable(exercise2_knapsack01 exercise2_knapsack01.cpp)
