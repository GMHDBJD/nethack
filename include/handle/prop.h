#ifndef ITEM_H_
#define ITEM_H_

#include "screen.h"
#include <memory>

class PropImpl;

class Prop
{
public:
  Prop(const int &);
  Prop(const Prop &);
  Prop &operator=(const Prop &);
  Position GetPosition() const;
  friend Screen &operator<<(Screen &, const Prop &);
  void SetPosition(const Position &);
  int GetIndex() const;
  ~Prop();

private:
  std::unique_ptr<PropImpl> prop_impl;
};

#endif