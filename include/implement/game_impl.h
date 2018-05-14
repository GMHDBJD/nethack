#ifndef GAME_IMPL_H_
#define GAME_IMPL_H_
#include <vector>
#include "level.h"

class GameImpl
{
public:
  GameImpl(const int &);
  void MainGame();
  bool SwitchChoice(const char &input);

private:
  std::vector<Level> _level_vecotr;
  int _total_level;
  int _current_level;
  int _top_level;
  Player _player;
};

#endif