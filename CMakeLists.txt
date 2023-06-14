cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)
project(collisions)

include_directories(/usr/local/include include/)

add_executable(collisions src/main.cpp include/shapes.hpp include/collisions.hpp src/collisions.cpp)
