#ifndef MAP_IMPL_H_
#define MAP_IMPL_H_

#include "room.h"
#include "screen.h"
#include <utility>

class MapImpl
{
private:
  Room _rooms[5];
  std::pair<char, int> _map_save[Position::_k_max_height][Position::_k_max_width];
  std::set<std::pair<int, int>> _room_door;
  int _first_room;

public:
  MapImpl();
  friend Screen &operator<<(Screen &, const MapImpl &);
  void Update(const Position &);

  void SaveRoom(const Room &room);
  Position GetRoomInitPosition() const;
  Position GetRandomPosition() const;
  void Corridor(const Position &, const Position &);
};

#endif