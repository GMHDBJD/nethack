#ifndef CREATURE_H_
#define CREATURE_H_

#include "position.h"

class Creature
{
protected:
  Position _position;
  int _max_hp;
  int _attack;
  int _hp;
  int _defence;

public:
  Creature(int max_hp, int attack, int defence);
  Position GetPosition() const;
  int GetMaxHp() const;
  int GetAttack() const;
  int GetHp() const;
  int GetDefence() const;
  void SetMaxHp(const int &);
  void SetAttack(const int &);
  void SetHp(const int &);
  void SetDefence(const int &);
  void SetPosition(const Position &);
  Creature &operator-=(const Creature &);
};

#endif