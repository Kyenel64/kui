/*
===============================================================================

    main

    Main bootstrap. Manages engine lifetime, init & clean up.

===============================================================================
*/

#include <cstdlib>

#include <CoreGlobals.h>
#include <SceneLoop.h>

#include "EngineState.h"
#include "window/Window.h"


// platform, core objects
static kui::EngineState* engine_state = nullptr;

// subsystem objects
static kui::Window* window = nullptr;
//static kui::Renderer* renderer = nullptr;

static kui::IMainLoop* main_loop = nullptr;


// Initialize engine and low level systems
static bool pre_init() {
  engine_state = new kui::EngineState;

  return true;
}

// Initialize subsystems
static bool init() {
  window = new kui::Window;

  main_loop = new kui::SceneLoop;

  return true;
}

// Initialize and run main loop
static void start() {
  window->create_window("kui", 640, 480);

  main_loop->init();
  while (!kui::g_engine_exit_requested) {
    main_loop->tick();
  }
  main_loop->exit();
}

int main(int argc, const char* argv[]) {

  // Be sure to clean everything up at all times.
  struct CleanupGuard {
    ~CleanupGuard() {
      delete window;

      delete main_loop;
      delete engine_state;
    }
  } cleanup_guard;

  if (!pre_init())
    return EXIT_FAILURE;

  if (!init())
    return EXIT_FAILURE;

  start();

  return EXIT_SUCCESS;
}
