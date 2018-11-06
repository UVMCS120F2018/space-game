cmake_minimum_required(VERSION 3.12)
project(project4)

set(CMAKE_CXX_STANDARD 17)

add_executable(stellar_exploration
        starship.cpp
        star_system.cpp
        main.cpp)
add_executable(testing
        starship.cpp
        star_system.cpp
        testing.cpp)