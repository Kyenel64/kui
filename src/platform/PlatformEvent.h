/*
===============================================================================

    Event

===============================================================================
*/

#pragma once

#include <cstdint>

#include "Key.h"
#include "MouseButton.h"


namespace kui {

enum EventType {
  EVENT_NONE = -1,
  EVENT_WINDOW_CLOSED, EVENT_WINDOW_RESIZED,
  EVENT_KEY_PRESSED, EVENT_KEY_RELEASED,
  EVENT_MOUSE_BUTTON_PRESSED, EVENT_MOUSE_BUTTON_RELEASED, EVENT_MOUSE_MOVED, EVENT_MOUSE_SCROLLED
};

/*=============================================================================
  Event
=============================================================================*/

class Event {
public:
  virtual ~Event() = default;

  virtual EventType get_type() const = 0;
};


/*=============================================================================
  WindowClosedEvent
=============================================================================*/

class WindowClosedEvent final : public Event {
public:
  WindowClosedEvent() = default;

  EventType get_type() const override { return EVENT_WINDOW_CLOSED; }
};

/*=============================================================================
  WindowResizedEvent
=============================================================================*/

class WindowResizedEvent final : public Event {
public:
  WindowResizedEvent(const uint32_t p_width, const uint32_t p_height) : m_width(p_width), m_height(p_height) {}

  EventType get_type() const override { return EVENT_WINDOW_RESIZED; }

  uint32_t get_width() const { return m_width; }
  uint32_t get_height() const { return m_height; }

private:
  uint32_t m_width, m_height;
};


/*=============================================================================
  KeyPressedEvent
=============================================================================*/

class KeyPressedEvent final : public Event {
public:
  explicit KeyPressedEvent(const Keycode p_key) : m_key(p_key) {}

  EventType get_type() const override { return EVENT_KEY_PRESSED; }

  Keycode get_key() const { return m_key; }

public:
  Keycode m_key;
};

/*=============================================================================
  KeyReleasedEvent
=============================================================================*/

class KeyReleasedEvent final : public Event {
public:
  explicit KeyReleasedEvent(const Keycode p_key) : m_key(p_key) {}

  EventType get_type() const override { return EVENT_KEY_RELEASED; }

  Keycode GetKey() const { return m_key; }

public:
  Keycode m_key;
};


/*=============================================================================
  MouseButtonPressedEvent
=============================================================================*/

class MouseButtonPressedEvent final : public Event {
public:
  explicit MouseButtonPressedEvent(const MouseButton p_mouse_button) : m_mouse_button(p_mouse_button) {}

  EventType get_type() const override { return EVENT_MOUSE_BUTTON_PRESSED; }

  MouseButton get_mouse_button() const { return m_mouse_button; }

public:
  MouseButton m_mouse_button;
};

/*=============================================================================
  MouseButtonReleasedEvent
=============================================================================*/

class MouseButtonReleasedEvent final : public Event {
public:
  explicit MouseButtonReleasedEvent(const MouseButton p_mouse_button) : m_mouse_button(p_mouse_button) {}

  EventType get_type() const override { return EVENT_MOUSE_BUTTON_RELEASED; }

  MouseButton get_mouse_button() const { return m_mouse_button; }

public:
  MouseButton m_mouse_button;
};

/*=============================================================================
  MouseMovedEvent
=============================================================================*/

class MouseMovedEvent final : public Event {
public:
  MouseMovedEvent(const double p_x, const double p_y) : m_x_pos(p_x), m_y_pos(p_y) {}

  EventType get_type() const override { return EVENT_MOUSE_MOVED; }

  double get_x_pos() const { return m_x_pos; }
  double get_y_pos() const { return m_y_pos; }

public:
  double m_x_pos, m_y_pos;
};

/*=============================================================================
  MouseScrolledEvent
=============================================================================*/

class MouseScrolledEvent final : public Event {
public:
  MouseScrolledEvent(const double p_x_offset, const double p_y_offset) : m_x_offset(p_x_offset),
                                                                         m_y_offset(p_y_offset) {}

  EventType get_type() const override { return EVENT_MOUSE_SCROLLED; }

  double get_x_offset() const { return m_x_offset; }
  double get_y_offset() const { return m_y_offset; }

public:
  double m_x_offset, m_y_offset;
};

}
