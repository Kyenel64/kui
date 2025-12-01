/*
===============================================================================

    NativeWindow

===============================================================================
*/

#pragma once

#include <string>

class GLFWwindow;

namespace kui {

/*=============================================================================
  NativeWindow
=============================================================================*/

class NativeWindow {
public:
  NativeWindow();
  ~NativeWindow() = default;

  bool create_window(const std::string& title, int width, int height);
  bool window_created() const { return m_glfw_window != nullptr; }

  void poll_events();

  bool should_close() const;
  void set_should_close(bool value);

  void set_maximized();

private:
  GLFWwindow *m_glfw_window = nullptr;
};

} // kui
