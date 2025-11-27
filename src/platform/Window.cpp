/*
===============================================================================

    Window

===============================================================================
*/

#include "Window.h"

#include <iostream>

#include <GLFW/glfw3.h>

static void glfw_error_callback(const int error, const char *desc) {
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

  m_glfw_window = glfwCreateWindow(static_cast<int>(m_width), static_cast<int>(m_height), m_title.c_str(), nullptr,
                                   nullptr);
  if (!m_glfw_window) {
    glfwTerminate();
  }

  glfwMakeContextCurrent(m_glfw_window);

  if (p_maximize)
    glfwMaximizeWindow(m_glfw_window);

  glfwSetWindowUserPointer(m_glfw_window, this);

  register_callbacks();
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

void Window::register_callbacks() {
  // Window
  glfwSetWindowCloseCallback(m_glfw_window, [](GLFWwindow *window) {
    if (const auto *win = static_cast<Window *>(glfwGetWindowUserPointer(window))) {
      if (win->m_event_callback) {
        WindowClosedEvent event;
        win->m_event_callback(event);
      }
    }
  });

  glfwSetWindowSizeCallback(m_glfw_window, [](GLFWwindow *window, const int width, const int height) {
    if (auto *win = static_cast<Window *>(glfwGetWindowUserPointer(window)); win->m_event_callback) {
      WindowResizedEvent event(width, height);
      win->m_width = width; // Setting window width and height here.
      win->m_height = height;
      win->m_event_callback(event);
    }
  });

  // Key
  glfwSetKeyCallback(m_glfw_window, [](GLFWwindow *window, const int key, const int scancode, const int action, const int mods) {
    if (const auto *win = static_cast<Window *>(glfwGetWindowUserPointer(window)); win->
      m_event_callback) {
      if (action == GLFW_PRESS) {
        KeyPressedEvent event(static_cast<Keycode>(key));
        win->m_event_callback(event);
      } else if (action == GLFW_RELEASE) {
        KeyReleasedEvent event(static_cast<Keycode>(key));
        win->m_event_callback(event);
      }
    }
  });

  // Mouse
  glfwSetMouseButtonCallback(m_glfw_window, [](GLFWwindow *window, const int button, const int action, const int mods) {
    if (const auto *win = static_cast<Window *>(glfwGetWindowUserPointer(window)); win->m_event_callback) {
      if (action == GLFW_PRESS) {
        MouseButtonPressedEvent event(static_cast<MouseButton>(button));
        win->m_event_callback(event);
      } else if (action == GLFW_RELEASE) {
        MouseButtonReleasedEvent event(static_cast<MouseButton>(button));
        win->m_event_callback(event);
      }
    }
  });

  glfwSetCursorPosCallback(m_glfw_window, [](GLFWwindow *window, const double xpos, const double ypos) {
    if (const auto *win = static_cast<Window *>(glfwGetWindowUserPointer(window)); win->m_event_callback) {
      MouseMovedEvent event(xpos, ypos);
      win->m_event_callback(event);
    }
  });

  glfwSetScrollCallback(m_glfw_window, [](GLFWwindow *window, const double xoffset, const double yoffset) {
    if (const auto *win = static_cast<Window *>(glfwGetWindowUserPointer(window)); win->m_event_callback) {
      MouseScrolledEvent event(xoffset, yoffset);
      win->m_event_callback(event);
    }
  });
}

} // kui
