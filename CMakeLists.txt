cmake_minimum_required(VERSION 3.28)

project(kui_runtime CXX)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(kui)
add_subdirectory(game)

add_executable(kui_runtime
        runtime/main.cpp
)

target_link_libraries(kui_runtime PRIVATE kui)
