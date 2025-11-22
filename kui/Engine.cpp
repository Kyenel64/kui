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

Engine::Engine() {
  // Log::init(); // TODO: Move to Main::setup()?
  m_window = new Window("kui", 640, 480);
}

void Engine::run() {
  //m_SceneDOM->Load();

  using clock = std::chrono::high_resolution_clock;
  auto previous = clock::now();
  double lag = 0.0f;

  while (!m_window->should_close())
  {
    auto current = clock::now();
    const double elapsed = std::chrono::duration<double, std::milli>(current - previous).count();
    previous = current;
    lag += elapsed;

    m_window->poll_events();

    int updateCount = 0;
    while (lag >= MS_PER_UPDATE && updateCount < 5)
    {
      //m_SceneDOM->FixedUpdate();
      lag -= MS_PER_UPDATE;
      updateCount++;
    }

    //m_SceneDOM->Update(elapsed / 1000.0f);

    // double alpha = lag / 16; TODO: Alpha interpolate
    //m_SceneDOM->Render();
  }
  //m_SceneDOM->Quit();
}

} // kui
