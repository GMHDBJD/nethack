#ifndef MONSTRE_H_
#define MONSTRE_H_

#include "creature.h"
#include "screen.h"

class Monstre : public Creature
{
public:
  Monstre(int max_hp, int attack, int defenc);
  friend Screen &operator<<(Screen &, const Monstre &);
  void Attack();
  Position GetNextPosition(const Position &) const;
};

#endif