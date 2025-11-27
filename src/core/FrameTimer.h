/*
===============================================================================

    FrameTimer

===============================================================================
*/

#pragma once

#include <PlatformTimer.h>

namespace kui {

class FrameTimer {
public:
  FrameTimer();
  ~FrameTimer() = default;

  double get_lag_ms() const { return PlatformTimer::cycles_to_seconds(m_lag_cycles) * 1000.0; }
  double get_delta_time() const { return PlatformTimer::cycles_to_seconds(m_delta_cycles); }

  void tick();

  void subtract_lag(double ms);
  void reset();

private:
  uint64_t m_last_cycles = 0;
  uint64_t m_delta_cycles = 0;
  uint64_t m_lag_cycles = 0;
};

} // kui
