#ifndef POSITION_H_
#define POSITION_H_

#include <utility>
#include <vector>

class Screen;

class Position
{
public:
  static const int _k_max_height=33;
  static const int _k_max_width=100;
  typedef int pos;
  Position();
  Position(const Position &);
  bool operator==(const Position &) const;

  Position(const int &index);
  Position(const pos &x, const pos &y);

  pos GetX() const;
  pos GetY() const;

  std::pair<pos, pos> GetXY() const;
  Position& SetX(const pos &);
  Position& SetY(const pos &);
  Position& SetXY(const pos &x, const pos &y);
  Position& AddX(const pos &);
  Position& AddY(const pos &);
  Position& AddXY(const pos &, const pos &);
  Position GetLeftPosition() const;
  Position GetRightPosition() const;
  Position GetUpPosition() const;
  Position GetDownPosition() const;
  Position GetLeftUpPosition() const;
  Position GetRightUpPosition() const;
  Position GetLeftDownPosition() const;
  Position GetRightDownPosition() const;
  pos Distance(const Position &)const;
  std::vector<Position> GetNearPosition() const;
  std::vector<Position> GetDirectorPosition() const;

  bool operator!=(const Position &) const;
  operator bool() const;

private:
  pos _x;
  pos _y;
  const static int _grid_position[5][2];
};

#endif