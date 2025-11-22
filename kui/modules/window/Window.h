/*
===============================================================================

    Window

===============================================================================
*/

#pragma once

#include "modules/events/Event.h"

class GLFWwindow;

namespace kui {

/*=============================================================================
  Window
=============================================================================*/

class Window {
public:
  Window(const std::string &p_title, uint32_t p_width, uint32_t p_height, bool p_maximize = false);

  ~Window() = default;

  bool should_close() const;

  void set_should_close(bool p_value);

  void poll_events();

  void dispatch_event(Event &p_event) const { if (m_event_callback) m_event_callback(p_event); }

  template<typename Fn>
  void set_event_callback(Fn &&eventFn) { m_event_callback = std::forward<Fn>(eventFn); }

private:
  void register_callbacks();

private:
  GLFWwindow *m_glfw_window = nullptr;

  std::string m_title;
  uint32_t m_width, m_height;
  std::function<void(Event &)> m_event_callback = nullptr;
};

} // kui
