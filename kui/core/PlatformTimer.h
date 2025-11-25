/*
===============================================================================

    PlatformTimer

===============================================================================
*/

#pragma once

namespace kui {

namespace PlatformTimer {

uint64_t cycles();

double cycles_to_seconds(uint64_t cycles);

double seconds();

uint64_t ms_to_cycles(double ms);

} // PlatformTimer

} // kui
