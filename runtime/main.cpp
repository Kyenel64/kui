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
#if 0
  typedef kui::IObject* (*CreateObjectFunc)();
  typedef void (*DestroyObjectFunc)(kui::IObject*);

  void* handle = dlopen("./game/libgame.dylib", RTLD_LAZY);
  if (!handle) {
    std::cerr << "Failed to load game.dylib: " << dlerror() << std::endl;
    return 1;
  }

  auto createFunc = reinterpret_cast<CreateObjectFunc>(dlsym(handle, "CreateObject"));
  auto destroyFunc = reinterpret_cast<DestroyObjectFunc>(dlsym(handle, "DestroyObject"));

  if (!createFunc || !destroyFunc) {
    std::cerr << "Failed to load functions: " << dlerror() << std::endl;
    dlclose(handle);
    return 1;
  }

  kui::IObject* playerObj = createFunc();
  playerObj->Think();
  destroyFunc(playerObj);
  dlclose(handle);

#endif

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
