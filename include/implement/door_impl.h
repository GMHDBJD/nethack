#ifndef DOOR_IMPL_H_
#define DOOR_IMPL_H_
#include "position.h"
#include "screen.h"
#include <utility>

class DoorImpl
{
private:
  Position _position;

public:
  DoorImpl() = default;
  void SetPosition(const int &x, const int &y);
  Position GetPosition() const;
  void SaveToMap(std::pair<char, int>[Position::_k_max_height][Position::_k_max_width]) const;
};

#endif