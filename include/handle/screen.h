#ifndef SCREEN__H_
#define SCREEN__H_
#include "position.h"
#include <memory>

class ScreenImpl;

class Screen
{
public:
  Screen();
  Screen(const Screen &);
  Screen &operator=(const Screen &);
  int CheckPosition(const Position &) const;
  ~Screen();

private:
  std::unique_ptr<ScreenImpl> screen_impl;
};

#endif