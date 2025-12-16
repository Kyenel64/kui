/*
===============================================================================

    Event

===============================================================================
*/

#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <typeindex>

namespace kui {

enum Keycode : int;

/*=============================================================================
  Event
=============================================================================*/

struct Event {
  virtual ~Event() = default;

  uint64_t timestamp = 0;
};

/*=============================================================================
  KeyPressedEvent
=============================================================================*/

struct KeyPressedEvent : Event {
  Keycode keycode;
};

/*=============================================================================
  WindowResizeEvent
=============================================================================*/

struct WindowCloseEvent : Event {
};

struct WindowResizeEvent : Event {
  int width;
  int height;
};


template<typename T>
using EventListener = std::function<void(const T&)>;


/*=============================================================================
  EventQueue
=============================================================================*/

class EventQueue {
public:
  static EventQueue* get();

  explicit EventQueue(size_t capacity = 256);
  ~EventQueue();

  EventQueue(const EventQueue&) = delete;
  EventQueue& operator=(const EventQueue&) = delete;

  template<typename T>
  void subscribe(EventListener<T> listener) {
    auto type_index = std::type_index(typeid(T));
    auto wrapper = [listener](const Event& e) {
      listener(static_cast<const T&>(e));
    };
    m_listeners[type_index].push_back(wrapper);
  }

  template<typename T>
  bool post(const T& event) {
    if (is_full())
      return false;

    m_events[m_head] = std::make_unique<T>(event);
    m_head = (m_head + 1) % m_capacity;
    m_count++;
    return true;
  }

  void process_all();
  void process_one();

  size_t get_pending_count() const { return m_count; };
  bool is_empty() const { return m_count == 0; };
  bool is_full() const { return m_count == m_capacity; };

  void clear();

private:
  static EventQueue* m_singleton;

  using ListenerWrapper = std::function<void(const Event&)>;
  std::unordered_map<std::type_index, std::vector<ListenerWrapper>> m_listeners;

  // Ring buffer
  std::vector<std::unique_ptr<Event>> m_events;
  size_t m_head = 0;
  size_t m_tail = 0;
  size_t m_count = 0;
  size_t m_capacity;

};

} // kui
