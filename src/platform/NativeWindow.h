/*
===============================================================================

    NativeWindow

===============================================================================
*/

#pragma once

#include <string>
#include <functional>

#include "PlatformEvent.h"

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

  std::function<void(Event &)> m_event_callback = nullptr;
};

} // kui
