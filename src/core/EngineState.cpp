/*
===============================================================================

    EngineState

===============================================================================
*/

#include "EngineState.h"

#include <assert.h>
#include <iostream>

namespace kui {

EngineState *EngineState::m_singleton = nullptr;

EngineState::EngineState() {
  if (m_singleton != nullptr) {
    std::cerr << "Engine singleton already instantiated" << std::endl;
    assert(false);
  }
  m_singleton = this;
}

EngineState::~EngineState() {
  if (m_singleton == this)
    m_singleton = nullptr;
}

} // kui
