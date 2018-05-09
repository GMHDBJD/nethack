#include "room_impl.h"
#include <ncurses.h>
#include <random>

RoomImpl::RoomImpl(const int& index) : _position(index)
{
    if (rand() % 2 == 0)
    {
        _width = rand() % 4 + 8;
        _height = rand() % 3 + 5;
    }
    else
    {
        _width = rand() % 5 + 15;
        _height = rand() % 3 + 4;
    }

    doors[0].SetPosition(rand() % (_width - 2) + _position.GetX() + 1, _position.GetY());
    doors[1].SetPosition(_position.GetX(), rand() % (_height - 2) + _position.GetY() + 1);
    doors[2].SetPosition(rand() % (_width - 2) + _position.GetX() + 1, _position.GetY() + _height - 1);
    doors[3].SetPosition(_position.GetX() + _width - 1, rand() % (_height - 2) + _position.GetY() + 1);
}

Position RoomImpl::GetDoorPosition(const int &index) const
{
    return doors[index].GetPosition();
}

void RoomImpl::SaveToMap(std::pair<char, int> map[Position::_k_max_height][Position::_k_max_width]) const
{
    int x = _position.GetX();
    int y = _position.GetY();
    for (int i = x; i < x + _width; ++i)
    {
        map[y][i] = std::make_pair('-', 1);
        map[y + _height - 1][i] = std::make_pair('-', 1);
    }
    for (int i = y + 1; i < y + _height - 1; ++i)
    {
        map[i][x] = std::make_pair('|', 1);
        map[i][x + _width - 1] = std::make_pair('|', 1);
        for (int j = x + 1; j < x + _width - 1; j++)
        {
            map[i][j] = std::make_pair('.', 1);
        }
    }
    if (x - 1 > 0 && y - 1 > 0&&x+1<99&&y+1<29)
    {
        for (int i = x - 1; i < x + _width + 1; ++i)
        {
            map[y - 1][i].second = -1;
            map[y + _height][i].second = -1;
        }
        for (int i = y; i < y + _height; ++i)
        {
            map[i][x - 1].second = -1;
            map[i][x + _width].second = -1;
        }
    }
    for (int i = 0; i < 4; ++i)
        doors[i].SaveToMap(map);
}

void RoomImpl::Show(std::pair<char, int> map[Position::_k_max_height][Position::_k_max_width]) const
{
    int x = _position.GetX();
    int y = _position.GetY();
    for (int i = x; i < x + _width; ++i)
        for (int j = y; j < y + _height; ++j)
            map[j][i].second = 0;
}

Position RoomImpl::GetPosition() const
{
    return _position;
}


int RoomImpl::GetHeight()const
{
    return _height;
}

int RoomImpl::GetWidth()const
{
    return _width;
}