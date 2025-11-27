/*
===============================================================================

    PlatformTimer

===============================================================================
*/

#pragma once

#include <cstdint>

namespace kui {
namespace PlatformTimer {

uint64_t cycles();
double seconds();

double cycles_to_seconds(uint64_t cycles);
uint64_t ms_to_cycles(double ms);

} // PlatformTimer
} // kui
