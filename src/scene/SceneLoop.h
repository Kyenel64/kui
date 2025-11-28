/*
===============================================================================

    SceneLoop

===============================================================================
*/

#pragma once

#include "FrameTimer.h"
#include "IMainLoop.h"

namespace kui {

class SceneLoop : public IMainLoop {
public:
  SceneLoop();

  void init() override;
  void tick() override;
  void exit() override;

private:
  FrameTimer m_frame_timer;
};

} // kui
