#ifndef GAME_IMPL_H_
#define GAME_IMPL_H_

#include "level.h"

class GameImpl
{
public:
  GameImpl(const int &);
  void MainGame();
  bool SwitchChoice(const char &input);

private:
  Level _levels[20];
  int _total_level;
  int _current_level;
  Player _player;
};

#endif