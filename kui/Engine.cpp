/*
===============================================================================

    Engine

===============================================================================
*/

#include "Engine.h"
#include "kuiPCH.h"

#include <chrono>

#define MS_PER_UPDATE 60 // TODO: Make modifiable

namespace kui {

Engine* g_engine = nullptr;

Engine::Engine() {
  // Log::init(); // TODO: Move to Main::setup()?
  m_window = new Window("kui", 640, 480);
}

} // kui
