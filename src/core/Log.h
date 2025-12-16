/*
===============================================================================

    Log

===============================================================================
*/

#pragma once

#include <spdlog/spdlog.h>

#include <memory>

#include "Key.h"
#include "MouseButton.h"

/*=============================================================================
  Custom formattings
=============================================================================*/

namespace fmt {
  // Keycode
  template <>
  struct formatter<kui::Keycode> : formatter<int> {
    auto format(const kui::Keycode key, format_context& ctx) const {
      return formatter<int>::format(key, ctx);
    }
  };

  // MouseButton
  template <>
  struct formatter<kui::MouseButton> : formatter<int> {
    auto format(const kui::MouseButton mouse_button, format_context& ctx) const {
      return formatter<int>::format(mouse_button, ctx);
    }
  };
} // fmt


namespace kui {

/*=============================================================================
  Log
=============================================================================*/

class Log {
public:
  static void init();

  static std::shared_ptr<spdlog::logger>& GetLogger()
  {
    if (!spdlog::get("KUI"))
      init();
    return s_Logger;
  }
private:
  static std::shared_ptr<spdlog::logger> s_Logger;
};

} // kui

#define KUI_INFO(...) ::kui::Log::GetLogger()->info(__VA_ARGS__)
#define KUI_TRACE(...) ::kui::Log::GetLogger()->trace(__VA_ARGS__)
#define KUI_WARN(...) ::kui::Log::GetLogger()->warn(__VA_ARGS__)
#define KUI_ERROR(...) ::kui::Log::GetLogger()->error(__VA_ARGS__)

#ifdef KUI_DEBUG
#define KUI_ASSERT(x, ...) \
do { \
if (!(x)) { \
if constexpr (sizeof(#__VA_ARGS__) > 1) \
::kui::Log::GetLogger()->error("Assertion Failed: {}", ##__VA_ARGS__); \
else \
::kui::Log::GetLogger()->error("Assertion Failed"); \
abort(); \
} \
} while(0)
#else
#define KUI_ASSERT(x, ...)
#endif

