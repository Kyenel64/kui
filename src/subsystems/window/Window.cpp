/*
===============================================================================

    Window

===============================================================================
*/

#include "Window.h"

#include <GLFW/glfw3.h>

#include "CoreGlobals.h"
#include "Event.h"
#include "Log.h"

namespace kui {

static void glfw_error_callback(const int error, const char *desc) {
  KUI_ERROR("GLFW error: {0}: {1}", error, desc);
}

Window* Window::m_singleton = nullptr;

Window* Window::get() {
  return m_singleton;
}

Window::Window() {
  KUI_ASSERT(m_singleton == nullptr, "Engine singleton already instantiated");
  m_singleton = this;

  KUI_ASSERT(glfwInit(), "Failed to initialize glfw");
  glfwSetErrorCallback(glfw_error_callback);
}

Window::~Window() {
  if (m_singleton == this)
    m_singleton = nullptr;
}

void Window::create_window(std::string window_title, int width, int height, bool maximized) {
  m_title = std::move(window_title);
  m_width = width;
  m_height = height;

  KUI_ASSERT(!m_glfw_window, "Window instance already created."); // TODO: Enable multiple windows.
  m_glfw_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

  if (!m_glfw_window) {
    glfwTerminate();
    KUI_ASSERT(false, "Failed to create glfw window");
  }

  glfwMakeContextCurrent(m_glfw_window);
  glfwSetWindowUserPointer(m_glfw_window, this);

  glfwSetKeyCallback(m_glfw_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
      KeyPressedEvent event;
      event.keycode = static_cast<Keycode>(key);
      EventQueue::get()->post(event);
    }
  });

  glfwSetWindowCloseCallback(m_glfw_window, [](GLFWwindow* window) {
    WindowCloseEvent event;
    EventQueue::get()->post(event);
    g_engine_exit_requested = true;
  });
}

void Window::poll_events() {
  glfwPollEvents();
}

void Window::set_maximized() {
  glfwMaximizeWindow(m_glfw_window);
}

} // kui
