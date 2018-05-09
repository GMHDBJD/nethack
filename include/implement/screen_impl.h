#ifndef SCREEN_IMPL_H_
#define SCREEN_IMPL_H_
#include "position.h"

class ScreenImpl
{
public:
  ScreenImpl();
  ~ScreenImpl();
  int CheckPosition(const Position &) const;
};

#endif