#ifndef PROP_IMPL_H_
#define PROP_IMPL_H_

#include "position.h"

class PropImpl
{
private:
  Position _position;
  int _index;

public:
  PropImpl(const int &);
  Position GetPosition() const;
  friend Screen &operator<<(Screen &, const PropImpl &);
  void SetPosition(const Position &);
  int GetIndex() const;
};

#endif