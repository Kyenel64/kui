/*
===============================================================================

    FrameTimer

===============================================================================
*/

#include "FrameTimer.h"

#include "core/PlatformTimer.h"

namespace kui {

FrameTimer::FrameTimer() {
  m_last_cycles = PlatformTimer::cycles();
}

void FrameTimer::subtract_lag(const double ms) {
  const uint64_t cycles = PlatformTimer::ms_to_cycles(ms);
  m_lag_cycles -= cycles;
}

void FrameTimer::tick() {
  const uint64_t current_cycles = PlatformTimer::cycles();
  const uint64_t delta_cycles = current_cycles - m_last_cycles;

  m_delta_cycles = delta_cycles;
  m_lag_cycles += m_delta_cycles;
  m_last_cycles = current_cycles;
}

void FrameTimer::reset() {
  m_last_cycles = PlatformTimer::cycles();
}

} // kui
