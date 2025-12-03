/*
===============================================================================

    test_FrameTimer

===============================================================================
*/

#include <gtest/gtest.h>
#include <FrameTimer.h>

#include <thread>
#include <chrono>
using namespace std::chrono_literals;

TEST(FrameTimer, ProperInitialValues) {
  kui::FrameTimer frame_timer;
  EXPECT_EQ(frame_timer.get_delta_time(), 0);
  EXPECT_EQ(frame_timer.get_lag_ms(), 0);
}

TEST(FrameTimer, Tick) {
  kui::FrameTimer frame_timer;
  std::this_thread::sleep_for(200ms);

  frame_timer.tick();
  double deltaTime = frame_timer.get_delta_time();
  double lag_ms = frame_timer.get_lag_ms();

  // 10ms tolerance
  EXPECT_NEAR(deltaTime, 0.2, 0.01);
  EXPECT_NEAR(lag_ms, 200, 10);
}

TEST(FrameTimer, Reset) {
  kui::FrameTimer frame_timer;
  std::this_thread::sleep_for(50ms);

  frame_timer.tick();

  frame_timer.reset();
  EXPECT_EQ(frame_timer.get_delta_time(), 0);
  EXPECT_EQ(frame_timer.get_lag_ms(), 0);
}

TEST(FrameTimer, SubtractLag) {
  kui::FrameTimer frame_timer;
  std::this_thread::sleep_for(100ms);

  frame_timer.tick();

  double lag_ms = frame_timer.get_lag_ms();
  EXPECT_NEAR(lag_ms, 100, 10);

  frame_timer.subtract_lag(30);
  double new_lag_ms = frame_timer.get_lag_ms();
  EXPECT_NEAR(new_lag_ms, 70, 10);
}
