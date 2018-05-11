#ifndef GAME_H_
#define GAME_H_

#include "level.h"
#include <memory>

class GameImpl;

class Game
{
public:
  Game(const int &);
  Game(const Game &);
  Game &operator=(const Game &);
  void MainGame();
  bool SwitchChoice(const char &input);
  ~Game();

private:
  std::unique_ptr<GameImpl> game_impl;
};

#endif