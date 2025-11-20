/*
===============================================================================

    main

===============================================================================
*/

#include <iostream>
#include <dlfcn.h>

#include <Engine.h>
#include <IObject.h>

typedef kui::IObject* (*CreateObjectFunc)();
typedef void (*DestroyObjectFunc)(kui::IObject*);

int main()
{
    // Register functions


    void* handle = dlopen("./libgame.dylib", RTLD_LAZY);
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

    kui::Engine engine;

    return 0;
}
