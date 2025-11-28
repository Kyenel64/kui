/*
===============================================================================

    EngineState

===============================================================================
*/

#pragma once

namespace kui {

/*=============================================================================
  EngineState
=============================================================================*/

/**
 * Holds config state of engine.
 */
class EngineState {
public:
  EngineState();
  ~EngineState();

  EngineState(const EngineState&) = delete;
  EngineState& operator=(const EngineState&) = delete;

  static EngineState* get() {
    return m_singleton;
  }

private:
  static EngineState* m_singleton;
};

} // kui
