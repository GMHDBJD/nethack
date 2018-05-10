#ifndef LEVEL_IMPL_H_
#define LEVEL_IMPL_H_

#include "map.h"
#include "monstre.h"
#include "player.h"
#include "prop.h"
#include "screen.h"

class LevelImpl
{
public:
  LevelImpl();
  friend Screen &operator<<(Screen &, const LevelImpl &);
  Position GetInitPosition() const;
  Position GetRandomPosition() const;
  Map GetMap() const;
  bool UpdateMap(const Position &position);
  void SetIndex(const int &index);
  void SetTotalLevel(const int &);
  Position GetLevelPlayerPosition() const;
  void SetLevelPlayerPosition(const Position &position);
  Position GetUpstairPosition() const;
  Position GetDownstairPosition() const;
  Position GetWinPosition() const;
  void MoveMonstres(const Position &);
  void AttackMonstre(const Position &, Player *);
  void AttackPlayer(Player *);
  void Pick(Player *);
  std::vector<Prop> _prop_vector;

private:
  Map _map;
  int _total_level;
  Position _upstair;
  Position _downstair;
  Position _player_position;
  std::vector<Monstre> _monstre_vector;
  Position _win;
  int _monstre_num;
  int _index;
};

#endif