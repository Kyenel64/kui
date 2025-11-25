/*
===============================================================================

    OSXPlatformTimer

===============================================================================
*/

#include "core/PlatformTimer.h"
#include "kuiPCH.h"

#include <mach/mach_time.h>

namespace kui {

namespace PlatformTimer {

static mach_timebase_info_data_t timebase_info;
static bool timebase_initialized = false;

void init_timebase() {
  if (!timebase_initialized) {
    mach_timebase_info(&timebase_info);
    timebase_initialized = true;
  }
}

uint64_t cycles() {
  return mach_absolute_time();
}

double cycles_to_seconds(const uint64_t cycles) {
  init_timebase();
  const uint64_t nanoseconds = cycles * timebase_info.numer / timebase_info.denom;
  return static_cast<double>(nanoseconds) / 1000000000.0;
}

double seconds() {
  return cycles_to_seconds(cycles());
}

uint64_t ms_to_cycles(const double ms) {
  init_timebase();
  return static_cast<uint64_t>((ms * 1000000.0 * timebase_info.denom) / timebase_info.numer);
}

} // PlatformTimer

} // kui
