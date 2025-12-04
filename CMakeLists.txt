cmake_minimum_required(VERSION 3.28)

project(kui CXX)
set(CMAKE_CXX_STANDARD 23)

include(deps.cmake)

if (APPLE)
    add_compile_definitions(KUI_APPLE)
elseif (WIN32)
    add_compile_definitions(KUI_WINDOWS)
elseif (UNIX)
    add_compile_definitions(KUI_LINUX)
endif()

add_compile_definitions($<$<CONFIG:Debug>:KUI_DEBUG>)
add_compile_definitions($<$<CONFIG:Release>:KUI_RELEASE>)

# Separate libraries per layer to prevent any upward dependencies and possibly moving to dynamic modules in the future.

# Platform layer
set(PLATFORM_SRCS "")
if (APPLE)
    list(APPEND PLATFORM_SRCS
            src/platform/osx/OSXPlatformTimer.cpp
    )
endif()

add_library(Platform STATIC
        src/platform/PlatformTimer.h
        src/platform/NativeWindow.h
        src/platform/NativeWindow.cpp
        ${PLATFORM_SRCS}
)
target_include_directories(Platform PUBLIC src/platform)
target_link_libraries(Platform PRIVATE glfw)

# Core layer
add_library(Core STATIC
        src/core/CoreGlobals.h
        src/core/CoreGlobals.cpp
        src/core/EngineState.h
        src/core/EngineState.cpp
        src/core/FrameTimer.h
        src/core/FrameTimer.cpp
        src/core/Key.h
        src/core/MouseButton.h
        src/core/IMainLoop.h
        src/core/Log.cpp
        src/core/Log.h
)
target_include_directories(Core PUBLIC src/core)
target_link_libraries(Core PUBLIC Platform spdlog)

# Subsystems layer
add_library(Subsystems STATIC
        src/subsystems/renderer/Renderer.h
        src/subsystems/renderer/Renderer.cpp
        src/subsystems/window/Window.h
        src/subsystems/window/Window.cpp
)
target_include_directories(Subsystems PUBLIC src/subsystems)
target_link_libraries(Subsystems PUBLIC Core)

# Scene layer
add_library(Scene STATIC
        src/scene/SceneLoop.h
        src/scene/SceneLoop.cpp
)
target_include_directories(Scene PUBLIC src/scene)
target_link_libraries(Scene PUBLIC Subsystems)


# main
add_executable(kui
        src/main/main.cpp
)
target_link_libraries(kui PUBLIC Scene)


# tests
option(KUI_BUILD_TESTS "Build kui unit tests" ON)
if (KUI_BUILD_TESTS)
    enable_testing()

    set(SOURCES
            test/test_PlatformTimer.cpp
            test/test_NativeWindow.cpp
            test/Test_FrameTimer.cpp
            test/test_Log.cpp
    )

    # Files to not test on CI
    if (DEFINED ENV{GITHUB_ACTIONS})
        list(REMOVE_ITEM SOURCES
                test/test_NativeWindow.cpp
        )
    endif()

    add_executable(kui_test ${SOURCES})
    target_link_libraries(kui_test PRIVATE Scene GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(kui_test)

endif()
