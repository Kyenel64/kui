/*
===============================================================================

    Player

===============================================================================
*/

#pragma once

#include "IObject.h"

class Player : public kui::IObject {
public:
  Player() = default;

  void Think() override;

private:
};
