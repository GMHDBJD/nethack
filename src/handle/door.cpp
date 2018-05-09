#include "door.h"
#include "door_impl.h"

Door::Door() : door_impl(new DoorImpl()) {}

Door::Door(const Door &rhs) : door_impl(new DoorImpl(*rhs.door_impl)) {}

Door &Door::operator=(const Door &rhs)
{
    *door_impl = *rhs.door_impl;
    return *this;
}

Door::~Door() = default;

void Door::SetPosition(const int &x, const int &y)
{
    door_impl->SetPosition(x, y);
}

Position Door::GetPosition() const
{
    return door_impl->GetPosition();
}
void Door::SaveToMap(std::pair<char, int> map[Position::_k_max_height][Position::_k_max_width]) const
{
    door_impl->SaveToMap(map);
}