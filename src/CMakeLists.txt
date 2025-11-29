cmake_minimum_required(VERSION 3.28)

include(deps.cmake)

# Separate libraries per layer to prevent any upward dependencies and possibly moving to dynamic modules in the future.

# Platform layer
set(PLATFORM_SRCS "")
if (APPLE)
list(APPEND PLATFORM_SRCS
        platform/osx/OSXPlatformTimer.cpp
)
endif()

add_library(Platform STATIC
        platform/PlatformTimer.h
        platform/NativeWindow.h
        platform/NativeWindow.cpp
        ${PLATFORM_SRCS}
)
target_include_directories(Platform PUBLIC platform)
target_link_libraries(Platform PRIVATE glfw)

# Core layer
add_library(Core STATIC
        core/CoreGlobals.h
        core/CoreGlobals.cpp
        core/EngineState.h
        core/EngineState.cpp
        core/FrameTimer.h
        core/FrameTimer.cpp
        platform/Key.h
        platform/MouseButton.h
        core/IMainLoop.h
)
target_include_directories(Core PUBLIC core)
target_link_libraries(Core PUBLIC Platform)

# Subsystems layer
add_library(Subsystems STATIC
        subsystems/renderer/Renderer.h
        subsystems/renderer/Renderer.cpp
        subsystems/window/Window.cpp
        subsystems/window/Window.h
)
target_include_directories(Subsystems PUBLIC subsystems)
target_link_libraries(Subsystems PUBLIC Core)

# Scene layer
add_library(Scene STATIC
        scene/SceneLoop.h
        scene/SceneLoop.cpp
)
target_include_directories(Scene PUBLIC scene)
target_link_libraries(Scene PUBLIC Subsystems)
