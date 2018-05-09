#include "map.h"
#include "map_impl.h"

Map::Map() : map_impl(new MapImpl()) {}

Map::Map(const Map &rhs) : map_impl(new MapImpl(*rhs.map_impl)) {}

Map &Map::operator=(const Map &rhs)
{
    *map_impl = *rhs.map_impl;
    return *this;
}

Position Map::GetRoomInitPosition() const
{
    return map_impl->GetRoomInitPosition();
}

Position Map::GetRandomPosition() const
{
    return map_impl->GetRandomPosition();
}

Map::~Map() = default;

Screen &operator<<(Screen &screen, const Map &map)
{
    screen << *map.map_impl;
    return screen;
}

void Map::SaveRoom(const Room &room)
{
    map_impl->SaveRoom(room);
}

void Map::Update(const Position &position)
{
    map_impl->Update(position);
}