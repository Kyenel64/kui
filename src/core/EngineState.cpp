/*
===============================================================================

    EngineState

===============================================================================
*/

#include "EngineState.h"

#include "Log.h"

namespace kui {

EngineState* EngineState::m_singleton = nullptr;

EngineState* EngineState::get() {
  return m_singleton;
}

EngineState::EngineState() {
  KUI_ASSERT(!m_singleton, "EngineState singleton already instantiated");
  m_singleton = this;
}

EngineState::~EngineState() {
  if (m_singleton == this)
    m_singleton = nullptr;
}

} // kui
