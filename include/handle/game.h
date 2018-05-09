#ifndef GAME_H_
#define GAME_H_

#include "level.h"
#include <memory>

class GameImpl;

class Game
{
public:
  Game();
  Game(const Game &);
  Game &operator=(const Game &);
  void gameLoop();
  bool HandleInput(const char &input);
  ~Game();

private:
  std::unique_ptr<GameImpl> game_impl;
};

#endif