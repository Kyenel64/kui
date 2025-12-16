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

  float get_ms_per_update() const { return m_ms_per_update; }


private:
  static EngineState* m_singleton;

  float m_ms_per_update = 1000.0f / 60.0f; // 60FPS
};

} // kui
