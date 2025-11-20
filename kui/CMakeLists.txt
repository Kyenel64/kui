cmake_minimum_required(VERSION 3.28)

project(kui CXX)
set(CMAKE_CXX_STANDARD 23)

add_library(kui SHARED
        Engine.cpp
        Engine.h
        IObject.cpp
        IObject.h
)

target_include_directories(kui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
