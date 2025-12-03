/*
===============================================================================

    test_PlatformTimer

===============================================================================
*/

#include <gtest/gtest.h>
#include <PlatformTimer.h>

#include <thread>
#include <chrono>
using namespace std::chrono_literals;

TEST(PlatformTimer, ValidCycleValues) {
  uint64_t cycles = kui::PlatformTimer::cycles();
  ASSERT_GT(cycles, 0);
}

TEST(PlatformTimer, MonotonicCycles) {
  uint64_t cycles = kui::PlatformTimer::cycles();
  std::this_thread::sleep_for(50ms);
  uint64_t cycles_2 = kui::PlatformTimer::cycles();
  ASSERT_LT(cycles, cycles_2);
}

TEST(PlatformTimer, ProperConversions) {
  uint64_t cycles = kui::PlatformTimer::cycles();
  double seconds = kui::PlatformTimer::cycles_to_seconds(cycles);
  EXPECT_GT(cycles, seconds);

  double zero_seconds = kui::PlatformTimer::cycles_to_seconds(0);
  ASSERT_EQ(zero_seconds, 0);
  uint64_t zero_cycles = kui::PlatformTimer::ms_to_cycles(0);
  ASSERT_EQ(zero_cycles, 0);
}
