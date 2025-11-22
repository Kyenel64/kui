cmake_minimum_required(VERSION 3.28)

project(kui CXX)
set(CMAKE_CXX_STANDARD 23)

include(deps.cmake)

add_library(kui SHARED
        Engine.cpp
        Engine.h
        IObject.cpp
        IObject.h
        modules/window/Window.cpp
        modules/window/Window.h
        modules/events/Event.h
        modules/input/Key.h
        modules/input/MouseButton.h
)

target_link_libraries(kui PRIVATE glfw)

target_include_directories(kui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(kui PUBLIC kuiPCH.h)
