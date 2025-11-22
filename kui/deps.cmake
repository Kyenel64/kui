include(FetchContent)

# GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY "https://github.com/glfw/glfw"
        GIT_TAG "7b6aead9fb88b3623e3b3725ebb42670cbe4c579" # v3.4
)
FetchContent_MakeAvailable(glfw)
