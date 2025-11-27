cmake_minimum_required(VERSION 3.28)

project(kui CXX)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)

# main
add_executable(kui
        src/main/main.cpp
)
target_link_libraries(kui PUBLIC Scene)
