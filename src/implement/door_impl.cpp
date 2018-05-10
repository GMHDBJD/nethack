#include "door_impl.h"

void DoorImpl::SetPosition(const int &x, const int &y)
{
    _position.SetXY(x, y);
}

Position DoorImpl::GetPosition() const
{
    return _position;
}

void DoorImpl::SaveToMap(std::pair<char, int> map[Position::_k_max_height][Position::_k_max_width]) const
{
    map[_position.GetY()][_position.GetX()] = std::make_pair('+', 1);
    for (const auto &i : _position.GetDirectorPosition())
    {
        if (map[i.GetY()][i.GetX()].second == -1)
            map[i.GetY()][i.GetX()].second = 1;
    }
}