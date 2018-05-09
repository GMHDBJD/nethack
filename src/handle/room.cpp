#include "room.h"
#include "room_impl.h"

Room::Room(const int &index) : room_impl(new RoomImpl(index)) {}

Room::Room(const Room &rhs) : room_impl(new RoomImpl(*rhs.room_impl)) {}

Room &Room::operator=(const Room &rhs)
{
    *room_impl = *rhs.room_impl;
    return *this;
}

Position Room::GetPosition() const
{
    return room_impl->GetPosition();
}

Room::~Room() = default;

Position Room::GetDoorPosition(const int &index) const
{
    return room_impl->GetDoorPosition(index);
}

void Room::SaveToMap(std::pair<char, int> map[Position::_k_max_height][Position::_k_max_width]) const
{
    room_impl->SaveToMap(map);
}

void Room::Show(std::pair<char, int> map[Position::_k_max_height][Position::_k_max_width]) const
{
    return room_impl->Show(map);
}

int Room::GetHeight() const
{
    return room_impl->GetHeight();
}
int Room::GetWidth() const
{
    return room_impl->GetWidth();
}