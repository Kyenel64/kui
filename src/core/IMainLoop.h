/*
===============================================================================

    MainLoop

===============================================================================
*/

#pragma once

namespace kui {

class IMainLoop {
public:
  virtual ~IMainLoop() = default;

  virtual void init() = 0;
  virtual void tick() = 0;
  virtual void exit() = 0;
};

}
