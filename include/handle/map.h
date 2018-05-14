#ifndef MAP_H_
#define MAP_H_

#include "room.h"
#include "screen.h"
#include <memory>

class MapImpl;

class Map
{
private:
  std::unique_ptr<MapImpl> map_impl;

public:
  Map();
  Map(const Map &);
  Map &operator=(const Map &);
  void SaveRoom(const Room &room);
  void Update(const Position &);
  ~Map();
  friend Screen &operator<<(Screen &, const Map &);
  Position GetRoomInitPosition() const;
  Position GetRandomPosition() const;
  Position GetAnotherPosition() const;
  void Corridor();
};

#endif