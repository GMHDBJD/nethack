#include "level.h"
#include "level_impl.h"

Level::Level() : level_impl(new LevelImpl()) {}

Level::Level(const Level &rhs) : level_impl(new LevelImpl(*rhs.level_impl)) {}
Level &Level::operator=(const Level &rhs)
{
    *level_impl = *rhs.level_impl;
    return *this;
}

Level::~Level() = default;

bool Level::UpdateMap(const Position &position)
{
    return level_impl->UpdateMap(position);
}

Screen &operator<<(Screen &screen, const Level &level)
{
    screen << *(level.level_impl);
    return screen;
}

Map Level::GetMap() const
{
    return level_impl->GetMap();
}

Position Level::GetInitPosition() const
{
    return level_impl->GetInitPosition();
}

Position Level::GetRandomPosition() const
{
    return level_impl->GetRandomPosition();
}

void Level::SetIndex(const int &index)
{
    return level_impl->SetIndex(index);
}

void Level::SetLevelPlayerPosition(const Position &position)
{
    level_impl->SetLevelPlayerPosition(position);
}

Position Level::GetLevelPlayerPosition() const
{
    return level_impl->GetLevelPlayerPosition();
}

Position Level::GetUpstairPosition() const
{
    return level_impl->GetUpstairPosition();
}

Position Level::GetWinPosition() const
{
    return level_impl->GetWinPosition();
}
Position Level::GetDownstairPosition() const
{
    return level_impl->GetDownstairPosition();
}

void Level::MoveMonstres(const Position &destinate_position)
{
    return level_impl->MoveMonstres(destinate_position);
}

void Level::AttackMonstre(const Position &position, Player *player)
{
    level_impl->AttackMonstre(position, player);
}

void Level::AttackPlayer(Player *player)
{
    level_impl->AttackPlayer(player);
}

void Level::Pick(Player *_player)
{
    level_impl->Pick(_player);
}

void Level::SetTotalLevel(const int &total_level)
{
    level_impl->SetTotalLevel(total_level);
}