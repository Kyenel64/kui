/*
===============================================================================

    main

===============================================================================
*/

#include <thread>

#include <CoreGlobals.h>
#include <SceneLoop.h>

kui::EngineLoop engine_loop;

int main(int argc, const char* argv[]) {
  kui::g_game_thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());

  // Be sure engine cleans up at all times. exit() gets called right before ~engine_loop()
  struct EngineLoopCleanup {
    ~EngineLoopCleanup() {
      engine_loop.exit();
    }
  } cleanup_guard;

  if (!engine_loop.pre_init()) // load engine and game dlls.
    return 1;

  if (!engine_loop.init())
    return 1;

  while (!kui::g_engine_exit_requested) {
    engine_loop.tick();
  }

  return 0;
}
