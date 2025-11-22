/*
===============================================================================

    Player

===============================================================================
*/

#include "Player.h"

#include <iostream>

void Player::Think() {
  std::cout << "Player: thinking\n";
  std::cout << "AWESOME KDSJFLKJSDLKFJLSkjdfkjDKJ!\n";
}


extern "C" {
kui::IObject* CreateObject() {
  return new Player();
}

void DestroyObject(kui::IObject* obj) {
  delete obj;
}
}
