/*
===============================================================================

    Engine

===============================================================================
*/

#pragma once

#include "core/FrameTimer.h"
#include "modules/window/Window.h"

namespace kui {

/*=============================================================================
  Engine
=============================================================================*/

/**
 * Core Engine class. Main loop runs here.
 */
class Engine {
public:
  Engine();
  ~Engine() = default;

  void fixed_tick() {}

  void tick(double delta_time) {}

  void render() {}

private:
  Window* m_window = nullptr;
};

extern Engine* g_engine;

} // kui
