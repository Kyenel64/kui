cmake_minimum_required(VERSION 3.28)

project(kui CXX)
set(CMAKE_CXX_STANDARD 23)

add_library(kui SHARED
        src/Engine.h
        src/Engine.cpp
)

target_include_directories(kui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)


project(kui_main CXX)
set(CMAKE_CXX_STANDARD 23)
add_executable(kui_main src/main.cpp)
target_link_libraries(kui_main PRIVATE kui)
