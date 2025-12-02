/*
===============================================================================

    Window

===============================================================================
*/

#include "Window.h"

#include <assert.h>
#include <iostream>

namespace kui {

Window* Window::m_singleton = nullptr;

Window* Window::get() {
  return m_singleton;
}

Window::Window() {
  if (m_singleton != nullptr) {
    std::cerr << "Engine singleton already instantiated" << std::endl;
    assert(false);
  }

  m_singleton = this;
}

Window::~Window() {
  if (m_singleton == this)
    m_singleton = nullptr;
}

void Window::create_window(std::string window_title, int width, int height, bool maximized) {
  if (m_native_window.window_created()) {
    std::cerr << "Window already created" << std::endl;
    return;
  }

  m_title = std::move(window_title);
  m_width = width;
  m_height = height;

  m_native_window.create_window(m_title, m_width, m_height);

  if (maximized)
    m_native_window.set_maximized();
}

void Window::poll_events() {
  m_native_window.poll_events();
}

} // kui
