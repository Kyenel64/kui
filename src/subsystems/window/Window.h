/*
===============================================================================

    Window

===============================================================================
*/

#pragma once

#include <string>

#include "NativeWindow.h"

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

private:
  static Window* m_singleton;

  NativeWindow m_native_window;

  std::string m_title;
  int m_width = 0, m_height = 0;
};

} // kui
