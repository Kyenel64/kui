cmake_minimum_required(VERSION 3.28)

project(kui CXX)
set(CMAKE_CXX_STANDARD 23)

include(deps.cmake)

set(PLATFORM_SRCS "")

if (APPLE)
    list(APPEND PLATFORM_SRCS
            core/platform/osx/OSXPlatformTimer.h
    )
endif()

add_library(kui SHARED
        Engine.cpp
        Engine.h
        IObject.cpp
        IObject.h
        EngineLoop.cpp
        EngineLoop.h
        modules/window/Window.cpp
        modules/window/Window.h
        modules/events/Event.h
        modules/input/Key.h
        modules/input/MouseButton.h
        core/CoreGlobals.cpp
        core/CoreGlobals.h
        core/FrameTimer.cpp
        core/FrameTimer.h
        ${PLATFORM_SRCS}
        core/IPlatformTimer.h
)

target_link_libraries(kui PRIVATE glfw)

target_include_directories(kui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(kui PUBLIC kuiPCH.h)
