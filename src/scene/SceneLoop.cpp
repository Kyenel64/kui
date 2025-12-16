/*
===============================================================================

    SceneLoop

===============================================================================
*/

#include "SceneLoop.h"

#include "Event.h"
#include "Log.h"
#include "window/Window.h"

#define MS_PER_UPDATE (1000.0f / 60)

namespace kui {

void test_on_close(const WindowCloseEvent& event) {
  KUI_INFO("CLOSED");
}

void test_on_key_pressed(const KeyPressedEvent& event) {
  KUI_INFO(event.keycode);
}

SceneLoop::SceneLoop() {
  EventQueue::get()->subscribe<WindowCloseEvent>(test_on_close);
  EventQueue::get()->subscribe<KeyPressedEvent>(test_on_key_pressed);
}

void SceneLoop::init() {
  m_frame_timer.reset();
}

void SceneLoop::tick() {
  m_frame_timer.tick();

  Window::get()->poll_events();
  EventQueue::get()->process_all();

  int updateCount = 0;
  while (m_frame_timer.get_lag_ms() >= MS_PER_UPDATE && updateCount < 5)
  {
    //g_engine->fixed_tick();
    m_frame_timer.subtract_lag(MS_PER_UPDATE);
    updateCount++;
  }

  //g_engine->tick(m_frame_timer.get_delta_time());
  // double alpha = lag / 16; TODO: Alpha interpolate
  //g_engine->render();
}

void SceneLoop::exit() {}

} // kui
