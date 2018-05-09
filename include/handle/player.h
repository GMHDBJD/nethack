#ifndef PLAYER_IMPL_H_
#define PLAYER_IMPL_H_

#include "creature.h"
#include "screen.h"
#include "prop.h"
#include <menu.h>

class Player : public Creature
{
private:
  int _experience;
  int _gold;
  std::vector<Prop> _prop_vector;

public:
  Player();
  int GetExperience() const;
  Position GetNextPosition(const char &input) const;
  int GetGold() const;
  Player &SetGold(const int& );
  Player &SetExperience( const int&);
  friend Screen &operator<<(Screen &, const Player &);
  void PickProp(const Prop &);
  void Menu();
  void UseProp(int index);
  void Attack();
};

#endif