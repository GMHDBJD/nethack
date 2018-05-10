#ifndef ROOM_H_
#define ROOM_H_
#include "position.h"
#include "screen.h"
#include <memory>
#include <set>

class RoomImpl;

class Room
{
public:
  Room(const int &index = 0);
  Room(const Room &);
  Room &operator=(const Room &);
  Position GetDoorPosition(const int &index) const;
  ~Room();
  void SaveToMap(std::pair<char, int>[Position::_k_max_height][Position::_k_max_width]) const;
  Position GetPosition() const;
  int GetHeight() const;
  int GetWidth() const;
  void Show(std::pair<char, int>[Position::_k_max_height][Position::_k_max_width]) const;

private:
  std::unique_ptr<RoomImpl> room_impl;
};

#endif