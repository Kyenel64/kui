/*
===============================================================================

    Engine

===============================================================================
*/

#pragma once

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

  void run();

private:
  Window* m_window = nullptr;
};

} // kui
