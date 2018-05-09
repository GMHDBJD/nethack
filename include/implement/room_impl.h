#ifndef ROOM_IMPL_H_
#define ROOM_IMPL_H_
#include "door.h"
#include "position.h"
#include "screen.h"
#include <set>

class RoomImpl
{
public:
  RoomImpl(const int &);
  Position GetDoorPosition(const int &index) const;
  void SaveToMap(std::pair<char, int>[Position::_k_max_height][Position::_k_max_width]) const;
  void Show(std::pair<char, int>[Position::_k_max_height][Position::_k_max_width]) const;
  int GetHeight()const;
  int GetWidth() const;
  Position GetPosition() const;

private:
  Position _position;
  int _height;
  int _width;
  Door doors[4];
};

#endif