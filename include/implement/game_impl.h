#ifndef GAME_IMPL_H_
#define GAME_IMPL_H_

#include "level.h"

class GameImpl
{
public:
  GameImpl();
  void GameLoop();
  bool HandleInput(const char &input);

private:
  Level _levels[5];
  int _current_level;
  Player _player;
};

#endif