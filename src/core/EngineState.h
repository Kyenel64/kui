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
  static EngineState* get();

  EngineState();
  ~EngineState();

  EngineState(const EngineState&) = delete;
  EngineState& operator=(const EngineState&) = delete;


private:
  static EngineState* m_singleton;
};

} // kui
