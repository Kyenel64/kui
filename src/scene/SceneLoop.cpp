/*
===============================================================================

    SceneLoop

===============================================================================
*/

#include "SceneLoop.h"

#define MS_PER_UPDATE (1000.0f / 60)

namespace kui {

SceneLoop::SceneLoop() {}

void SceneLoop::init() {
  m_frame_timer.reset();
}

void SceneLoop::tick() {

  m_frame_timer.tick();

  //g_engine->get_window()->poll_events();

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
