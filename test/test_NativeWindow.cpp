/*
===============================================================================

    test_NativeWindow

===============================================================================
*/

#include <gtest/gtest.h>
#include <NativeWindow.h>

TEST(NativeWindow, ProperWindowCreation) {
  kui::NativeWindow native_window;

  bool success = native_window.create_window("Test", 640, 480);
  ASSERT_TRUE(success);
  ASSERT_TRUE(native_window.window_created());
}

TEST(NativeWindow, OnlyOneWindowInstance) {
  kui::NativeWindow native_window;

  bool success = native_window.create_window("Test", 640, 480);
  bool success2 = native_window.create_window("Test2", 640, 480);

  ASSERT_TRUE(success);
  ASSERT_FALSE(success2);
}
