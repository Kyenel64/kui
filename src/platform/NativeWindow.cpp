/*
===============================================================================

    NativeWindow

===============================================================================
*/

#include "NativeWindow.h"

#include <iostream>

#include <GLFW/glfw3.h>

static void glfw_error_callback(const int error, const char *desc) {
  std::cerr << "GLFW error" << error << ": " << desc << std::endl;
}

namespace kui {

NativeWindow::NativeWindow() {
  if (!glfwInit()) { // If already initialized, returns true immediately.
    std::cerr << "Failed to initialize glfw" << std::endl;
    return;
  }
  glfwSetErrorCallback(glfw_error_callback);
}

bool NativeWindow::should_close() const {
  return glfwWindowShouldClose(m_glfw_window);
}

void NativeWindow::set_should_close(const bool value) {
  glfwSetWindowShouldClose(m_glfw_window, value);
}

void NativeWindow::set_maximized() {
  glfwMaximizeWindow(m_glfw_window);
}

bool NativeWindow::create_window(const std::string& title, int width, int height) {
  if (m_glfw_window) {
    std::cerr << "Native window instance already created." << std::endl;
    return false;
  }
  m_glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!m_glfw_window) {
    std::cerr << "Failed to create glfw window" << std::endl;
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(m_glfw_window);
  glfwSetWindowUserPointer(m_glfw_window, this);
  return true;
}

void NativeWindow::poll_events() {
  glfwPollEvents();
}

} // kui
