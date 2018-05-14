#ifndef LEVEL_H_
#define LEVEL_H_

#include "map.h"
#include "player.h"
#include "screen.h"
#include <memory>

class LevelImpl;

class Level
{
public:
  Level();
  Level(const Level &);
  Level &operator=(const Level &);
  friend Screen &operator<<(Screen &, const Level &);
  void SetTotalLevel(const int &);
  Position GetInitPosition() const;
  Position GetRandomPosition() const;
    Position GetAnotherPosition() const;
  void SetIndex(const int &);
  Map GetMap() const;
  bool UpdateMap(const Position &position);
  Position GetLevelPlayerPosition() const;
  void SetLevelPlayerPosition(const Position &);
  Position GetUpstairPosition() const;
  Position GetWinPosition() const;
  Position GetDownstairPosition() const;
  void MoveMonstres(const Position &);
  void AttackMonstre(const Position &, Player *);
  void AttackPlayer(Player *);
  void Pick(Player *);
  ~Level();

private:
  std::unique_ptr<LevelImpl> level_impl;
};

#endif