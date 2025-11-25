/*
===============================================================================

    EngineLoop

===============================================================================
*/

#pragma once

#include "core/FrameTimer.h"

namespace kui {

class EngineLoop {
public:
  EngineLoop() = default;
  ~EngineLoop() = default;

  bool pre_init();
  bool init();
  void tick();
  void exit();

private:
  FrameTimer m_frame_timer;
};

} // kui
