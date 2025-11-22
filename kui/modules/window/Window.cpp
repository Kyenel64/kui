/*
===============================================================================

    Window

===============================================================================
*/

#include "Window.h"
#include "kuiPCH.h"

#include <GLFW/glfw3.h>

static void glfw_error_callback(const int error, const char* desc) {
  std::cerr << "GLFW error" << error << ": " << desc << std::endl;
}

namespace kui {

Window::Window(const std::string &p_title, const uint32_t p_width, const uint32_t p_height, const bool p_maximize)
  : m_title(p_title), m_width(p_width), m_height(p_height) {

  if (!glfwInit()) {
    std::cerr << "Failed to initialize glfw" << std::endl;
    return;
  }

  glfwSetErrorCallback(glfw_error_callback);

  m_glfw_window = glfwCreateWindow(static_cast<int>(m_width), static_cast<int>(m_height), m_title.c_str(), nullptr, nullptr);
  if (!m_glfw_window) {
    glfwTerminate();
  }

  glfwMakeContextCurrent(m_glfw_window);

  if (p_maximize)
    glfwMaximizeWindow(m_glfw_window);

  glfwSetWindowUserPointer(m_glfw_window, this);

  // register_callbacks();
}

bool Window::should_close() const {
  return glfwWindowShouldClose(m_glfw_window);
}

void Window::set_should_close(const bool p_value) {
  glfwSetWindowShouldClose(m_glfw_window, p_value);
}

void Window::poll_events() {
  glfwPollEvents();
}

} // kui
