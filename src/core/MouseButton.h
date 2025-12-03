/*
===============================================================================

    MouseButton

===============================================================================
*/

#pragma once

namespace kui {

// From GLFW3
enum MouseButton: int {
  Button0 = 0,
  Button1 = 1,
  Button2 = 2,
  Button3 = 3,
  Button4 = 4,
  Button5 = 5,
  Button6 = 6,
  Button7 = 7,

  Last = Button7,
  Left = Button0,
  Right = Button1,
  Middle = Button2
};

} // kui

template <>
struct fmt::formatter<kui::MouseButton> : fmt::formatter<int>
{
  auto format(const kui::MouseButton mouse_button, fmt::format_context& ctx) const
  {
    return formatter<int>::format(mouse_button, ctx);
  }
};
