#include "position.h"

const int Position::_grid_position[5][2] = {{6, 4}, {55, 5}, {30, 10}, {4, 16}, {55, 15}};

Position::Position() : _x(-1), _y(-1) {}

Position::Position(const Position &rhs)
{
    _x = rhs._x;
    _y = rhs._y;
}

Position::Position(const int &index) : _x(_grid_position[index][0]), _y(_grid_position[index][1]) {}

Position::Position(const pos &x, const pos &y) : _x(x), _y(y) {}

Position::pos Position::GetX() const
{
    return _x;
}

Position::pos Position::GetY() const
{
    return _y;
}

std::pair<Position::pos, Position::pos> Position::GetXY() const
{
    return std::make_pair(_x, _y);
}

Position &Position::SetX(const pos &x)
{
    _x = x;
    return *this;
}

Position &Position::SetY(const pos &y)
{
    _y = y;
    return *this;
}

Position &Position::SetXY(const pos &x, const pos &y)
{
    _x = x;
    _y = y;
    return *this;
}

Position &Position::AddX(const pos &x)
{
    _x += x;
    return *this;
}

Position &Position::AddY(const pos &y)
{
    _y += y;
    return *this;
}

Position &Position::AddXY(const pos &x, const pos &y)
{
    _x += x;
    _y += y;
    return *this;
}

Position Position::GetLeftPosition() const
{
    if (_x > 0)
        return Position(_x - 1, _y);
    else
        return Position(-1, -1);
}
Position Position::GetRightPosition() const
{
    if (_x < 99)
        return Position(_x + 1, _y);
    else
        return Position(-1, -1);
}
Position Position::GetUpPosition() const
{
    if (_y > 0)
        return Position(_x, _y - 1);
    else
        return Position(-1, -1);
}

Position Position::GetDownPosition() const
{
    if (_y < 29)
        return Position(_x, _y + 1);
    else
        return Position(-1, -1);
}

bool Position::operator==(const Position &rhs) const
{
    return (_x == rhs._x && _y == rhs._y);
}

bool Position::operator!=(const Position &rhs) const
{
    return !(rhs == *this);
}

Position::operator bool() const
{
    if (GetX() == -1 && GetY() == -1)
        return false;
    else
        return true;
}

Position Position::GetLeftUpPosition() const
{
    if (_x > 0 && _y > 0)
        return Position(_x - 1, _y - 1);
    else
        return Position(-1, -1);
}
Position Position::GetRightUpPosition() const
{
    if (_x < 99 && _y > 0)
        return Position(_x + 1, _y - 1);
    else
        return Position(-1, -1);
}
Position Position::GetLeftDownPosition() const
{
    if (_x > 0 && _y < 29)
        return Position(_x - 1, _y + 1);
    else
        return Position(-1, -1);
}
Position Position::GetRightDownPosition() const
{
    if (_x < 99 && _y < 29)
        return Position(_x + 1, _y + 1);
    else
        return Position(-1, -1);
}
std::vector<Position> Position::GetNearPosition() const
{
    std::vector<Position> temp_vector;
    Position temp_position;
    temp_position = GetDownPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetUpPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetLeftPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetRightPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetLeftUpPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetLeftDownPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetRightDownPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetRightUpPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    return temp_vector;
}

std::vector<Position> Position::GetDirectorPosition() const
{
    std::vector<Position> temp_vector;
    Position temp_position;
    temp_position = GetDownPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetUpPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetLeftPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    temp_position = GetRightPosition();
    if (temp_position)
        temp_vector.push_back(temp_position);
    return temp_vector;
}

int Position::Distance(const Position &rhs) const
{
    return (_x - rhs._x) * (_x - rhs._x) + (_y - rhs._y) * (_y - rhs._y);
}