/*
===============================================================================

    Window

===============================================================================
*/

#pragma once

#include <string>

class GLFWwindow;

namespace kui {

class Window {
public:
  static Window* get();

  Window();
  ~Window();

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  void create_window(std::string window_title, int width, int height, bool maximized = false);

  void poll_events();

  void set_maximized();

private:
  static Window* m_singleton;

  GLFWwindow* m_glfw_window = nullptr;

  std::string m_title;
  int m_width = 0, m_height = 0;
};

} // kui
