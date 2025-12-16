/*
===============================================================================

    Event

===============================================================================
*/

#include "Event.h"

#include "Log.h"

namespace kui {

EventQueue* EventQueue::m_singleton = nullptr;

EventQueue* EventQueue::get() {
  return m_singleton;
}

EventQueue::EventQueue(size_t capacity)
  : m_capacity(capacity) {
  KUI_ASSERT(!m_singleton, "Engine singleton already instantiated");

  m_singleton = this;

  m_events.resize(capacity);
}

EventQueue::~EventQueue() {
  if (m_singleton == this)
    m_singleton = nullptr;
}

void EventQueue::process_all() {
  while (!is_empty())
    process_one();
}

void EventQueue::process_one() {
  if (is_empty())
    return;

  // Get event at tail
  Event* event = m_events[m_tail].get();
  auto type_index = std::type_index(typeid(*event));

  // Dispatch to listeners
  auto it = m_listeners.find(type_index);
  if (it != m_listeners.end()) {
    for (auto& listener : it->second) {
      listener(*event);
    }
  }

  // Move tail forward and decrement
  m_tail = (m_tail + 1) % m_capacity;
  m_count--;
}

void EventQueue::clear() {
  m_head = 0;
  m_tail = 0;
  m_count = 0;
}


} // kui
