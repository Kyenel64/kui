/*
===============================================================================

    main

===============================================================================
*/

#include <thread>

#include <core/CoreGlobals.h>
#include <EngineLoop.h>

kui::EngineLoop engine_loop;

int main(int argc, const char* argv[]) {
  kui::g_game_thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());

  // Be sure engine cleans up at all times. exit() gets called right before ~engine_loop()
  struct EngineLoopCleanup {
    ~EngineLoopCleanup() {
      engine_loop.exit();
    }
  } cleanup_guard;

  bool success = engine_loop.pre_init(); // load engine and game dlls.

  success = engine_loop.init();

  while (!kui::g_engine_exit_requested) {
    engine_loop.tick();
  }

  return 0;
}
