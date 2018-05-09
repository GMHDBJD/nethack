#ifndef DOOR_H_
#define DOOR_H_

#include "position.h"
#include "screen.h"
#include <memory>

class DoorImpl;

class Door
{
public:
  Door();
  Door(const Door &);
  Door &operator=(const Door &);
  void SetPosition(const int &x, const int &y);
  Position GetPosition() const;
  void SaveToMap(std::pair<char, int>[Position::_k_max_height][Position::_k_max_width]) const;
  ~Door();

private:
  std::unique_ptr<DoorImpl> door_impl;
};

#endif