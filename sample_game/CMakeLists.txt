cmake_minimum_required(VERSION 3.28)

project(game CXX)
set(CMAKE_CXX_STANDARD 23)

add_library(game SHARED
        Player.cpp
        Player.h
)
target_link_libraries(game PRIVATE kui)
