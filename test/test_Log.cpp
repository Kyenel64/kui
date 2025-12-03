/*
===============================================================================

    test_Log

===============================================================================
*/

#include <gtest/gtest.h>
#include <Log.h>

#include "Key.h"
#include "MouseButton.h"

TEST(Log, LogPrimitives) {
  const char* str = "Hello world";
  testing::internal::CaptureStdout();
  KUI_INFO(1);
  KUI_TRACE("Hello world");
  KUI_WARN(true);
  KUI_WARN(str);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_TRUE(output.contains("KUI: 1"));
  EXPECT_TRUE(output.contains("KUI: Hello world"));
  EXPECT_TRUE(output.contains("KUI: true"));
  EXPECT_TRUE(output.contains("KUI: Hello world"));
}

TEST(Log, LogEnums)
{
  testing::internal::CaptureStdout();
  KUI_INFO(kui::Keycode::A);
  KUI_TRACE(kui::MouseButton::Left);
  KUI_WARN(kui::Keycode::Space);
  KUI_ERROR(kui::MouseButton::Middle);

  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_TRUE(output.contains(fmt::format("KUI: ", kui::Keycode::A)));
  EXPECT_TRUE(output.contains(fmt::format("KUI: ", kui::MouseButton::Left)));
  EXPECT_TRUE(output.contains(fmt::format("KUI: ", kui::Keycode::Space)));
  EXPECT_TRUE(output.contains(fmt::format("KUI: ", kui::MouseButton::Middle)));
}
