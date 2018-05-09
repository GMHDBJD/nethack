#include "map_impl.h"
#include <algorithm>
#include <cstring>
#include <ncurses.h>

extern Screen screen;

MapImpl::MapImpl()
{
    for (int i = 0; i < Position::_k_max_height; ++i)
        for (int j = 0; j < Position::_k_max_width; ++j)
            _map_save[i][j] = std::make_pair(' ', 1);
    for (int i = 0; i < 5; ++i)
    {
        _rooms[i] = Room(i);
        _rooms[i].SaveToMap(_map_save);
    }
    std::random_shuffle(std::begin(_rooms), std::end(_rooms));
    for (int i = 0; i < 5; ++i)
    {
        int index = rand() % 4;
        while (_room_door.find(std::make_pair(i, index)) != _room_door.end())
            index = rand() % 4;
        _room_door.insert(std::make_pair(i, index));
        Position begin = _rooms[i].GetDoorPosition(index);
        while (_room_door.find(std::make_pair((i + 1) % 5, index)) != _room_door.end())
            index = rand() % 4;
        _room_door.insert(std::make_pair((i + 1) % 5, index));
        Position end = _rooms[(i + 1) % 5].GetDoorPosition(index);
        Corridor(begin, end);
    }
    for (int i = 0; i < 5; ++i)
        SaveRoom(_rooms[i]);
    _first_room = rand() % 5;
    _rooms[_first_room].Show(_map_save);
}

void MapImpl::Corridor(const Position &begin, const Position &end)
{
    Position current_position = begin;
    std::set<std::pair<int, int>> temp_set;
    temp_set.insert(current_position.GetXY());
    std::vector<std::pair<Position, int>> temp_vector;
    temp_vector.push_back(std::make_pair(begin, -1));
    int index = 0;
    bool find = false;
    while (!find)
    {
        current_position = temp_vector[index].first;
        auto near_positions = current_position.GetDirectorPosition();
        std::random_shuffle(near_positions.begin(), near_positions.end());
        for (const auto &i : near_positions)
        {
            if (!strchr("|.-+", _map_save[i.GetY()][i.GetX()].first) && !(_map_save[i.GetY()][i.GetX()].second == -1) && temp_set.find(i.GetXY()) == temp_set.end())
            {
                temp_vector.push_back(std::make_pair(i, index));
                temp_set.insert(i.GetXY());
            }
            if (i == end)
            {
                find = true;
                break;
            }
        }
        ++index;
    }
    --index;
    while (index != -1)
    {
        _map_save[temp_vector[index].first.GetY()][temp_vector[index].first.GetX()].second = 1;
        _map_save[temp_vector[index].first.GetY()][temp_vector[index].first.GetX()].first = '#';
        index = temp_vector[index].second;
    }
}

Position MapImpl::GetRoomInitPosition() const
{
    return _rooms[_first_room].GetPosition().AddXY(rand() % (_rooms[_first_room].GetWidth() - 3) + 1, rand() % (_rooms[_first_room].GetHeight() - 3) + 1);
}

Position MapImpl::GetRandomPosition() const
{
    int index = rand() % 5;
    return _rooms[index].GetPosition().AddXY(rand() % (_rooms[index].GetWidth() - 3) + 1, rand() % (_rooms[index].GetHeight() - 3) + 1);
}

Screen &operator<<(Screen &screen, const MapImpl &map_impl)
{
    for (int i = 0; i < Position::_k_max_height; ++i)
        for (int j = 0; j < Position::_k_max_width; ++j)
            if (map_impl._map_save[i][j].second == 0)
                mvaddch(i, j, map_impl._map_save[i][j].first);
    return screen;
}

void MapImpl::Update(const Position &position)
{
    if (_map_save[position.GetY()][position.GetX()].second && !strchr("|-+", _map_save[position.GetY()][position.GetX()].first))
    {
        _map_save[position.GetY()][position.GetX()].second = 0;
    }
    if (_map_save[position.GetY()][position.GetX()].first == '+')
    {
        for (const auto &i : _room_door)
        {
            Position temp_position = _rooms[i.first].GetDoorPosition(i.second);
            if (position == temp_position)
            {
                _rooms[i.first].Show(_map_save);
                if (_map_save[temp_position.GetY()][temp_position.GetX() - 1].first == '-')
                    _map_save[temp_position.GetY()][temp_position.GetX()].first = '|';
                else
                    _map_save[temp_position.GetY()][temp_position.GetX()].first = '-';
            }
        }
    }
}

void MapImpl::SaveRoom(const Room &room)
{
    room.SaveToMap(_map_save);
}
