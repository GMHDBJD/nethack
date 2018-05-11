#include "level_impl.h"
#include <algorithm>
#include <cstring>
#include <ncurses.h>

extern Screen screen;

Screen &operator<<(Screen &screen, const LevelImpl &level_impl)
{
    screen << level_impl._map;
    if (mvinch(level_impl._downstair.GetY(), level_impl._downstair.GetX()) == '.' && level_impl._index != 0)
        mvaddch(level_impl._downstair.GetY(), level_impl._downstair.GetX(), '<');
    if (mvinch(level_impl._upstair.GetY(), level_impl._upstair.GetX()) == '.' && level_impl._index != level_impl._total_level - 1)
    {
        mvaddch(level_impl._upstair.GetY(), level_impl._upstair.GetX(), '>');
    }
    if (level_impl._index == level_impl._total_level - 1 && mvinch(level_impl._win.GetY(), level_impl._win.GetX()) == '.')
    {
        mvaddch(level_impl._win.GetY(), level_impl._win.GetX(), 'Y');
    }
    for (const auto &i : level_impl._prop_vector)
    {
        int x = i.GetPosition().GetX();
        int y = i.GetPosition().GetY();
        if (mvinch(y, x) == '.')
            screen << i;
    }
    for (const auto &i : level_impl._monstre_vector)
    {
        int x = i.GetPosition().GetX();
        int y = i.GetPosition().GetY();
        if (mvinch(y, x) != ' ' && mvinch(y, x) != '@')
            screen << i;
    }
    int defence = int(3 * level_impl._index);
    int num = int(level_impl._monstre_vector.size());
    if (level_impl._total_level != 1000)
        mvprintw(26, 2, "Level: %d(%d)", level_impl._index + 1, level_impl._total_level);
    else
        mvprintw(26, 2, "Level: %d(endless)", level_impl._index + 1);
    mvprintw(27, 2, "Monstre:  Hp: %d  Attack: %d  Defence %d Num:%d(%d)\n", int(3 * level_impl._index + 2), int(2 * level_impl._index) + 5, defence, num, level_impl._monstre_num);
    return screen;
}

LevelImpl::LevelImpl()
{
    _downstair = GetInitPosition();
    _player_position = _downstair;
    _upstair = GetRandomPosition();
    while (_upstair == _downstair)
    {
        _upstair = GetRandomPosition();
    }
    _win = GetRandomPosition();
    while (_win == _upstair || _win == _downstair)
    {
        _win = GetRandomPosition();
    }
    int n = rand() % 3 + 2;
    for (int i = 0; i < n; ++i)
    {
        Prop new_prop(rand() % 3);
        new_prop.SetPosition(GetRandomPosition());
        _prop_vector.push_back(new_prop);
    }
}

void LevelImpl::SetIndex(const int &index)
{
    _index = index;
    _monstre_num = index * 2 + 5;
    for (int i = 0; i < _monstre_num; ++i)
    {
        Monstre new_monster(int(3 * _index) + 2, int(2 * _index) + 5, int(2 * _index));
        new_monster.SetPosition(_map.GetRandomPosition());
        _monstre_vector.push_back(new_monster);
    }
}

Position LevelImpl::GetInitPosition() const
{
    return _map.GetRoomInitPosition();
}

Position LevelImpl::GetRandomPosition() const
{
    Position temp_position(_map.GetRandomPosition());
    while (temp_position == _downstair)
        temp_position = _map.GetRandomPosition();
    return temp_position;
}

Map LevelImpl::GetMap() const
{
    return _map;
}

bool LevelImpl::UpdateMap(const Position &position)
{
    for (const auto &i : position.GetNearPosition())
    {
        _map.Update(i);
    }
    return true;
}

Position LevelImpl::GetLevelPlayerPosition() const
{
    return _player_position;
}

void LevelImpl::SetLevelPlayerPosition(const Position &_position)
{
    _player_position = _position;
}

Position LevelImpl::GetUpstairPosition() const
{
    return _upstair;
}

Position LevelImpl::GetWinPosition() const
{
    return _win;
}

Position LevelImpl::GetDownstairPosition() const
{
    return _downstair;
}

void LevelImpl::MoveMonstres(const Position &destinate_position)
{
    screen << _map;
    for (auto &i : _monstre_vector)
    {
        auto positions = i.GetPosition().GetDirectorPosition();
        std::random_shuffle(positions.begin(), positions.end());
        positions.insert(positions.begin(), i.GetNextPosition(destinate_position));
        for (const auto &next_position : positions)
        {
            auto c = mvinch(next_position.GetY(), next_position.GetX());
            if (strchr(".><@", c))
            {
                i.SetPosition(next_position);
                break;
            }
        }
    }
}

void LevelImpl::AttackMonstre(const Position &position, Player *player)
{
    auto i = _monstre_vector.begin();
    while (i != _monstre_vector.end())
    {
        if (i->GetPosition() == position)
        {
            if (i->GetHp() > player->GetAttack())
            {
                mvprintw(0, 0, "You attack the monstre.\n");
                *i -= *player;
                ++i;
            }
            else
            {
                mvprintw(0, 0, "You kill the monstre.\n");
                i = _monstre_vector.erase(i);
                player->SetGold(player->GetGold() + i->GetMaxHp());
                player->SetExperience(player->GetExperience() + i->GetAttack());
            }
        }
        else
            ++i;
    }
}

void LevelImpl::AttackPlayer(Player *player_ptr)
{
    auto i = _monstre_vector.begin();
    while (i != _monstre_vector.end())
    {
        if (i->GetPosition() == player_ptr->GetPosition())
        {
            mvprintw(0, 0, "You are attacked by monstre.\n");
            *player_ptr -= *i;
            i = _monstre_vector.erase(i);
        }
        else
            ++i;
    }
}

void LevelImpl::Pick(Player *player)
{
    auto prop = _prop_vector.begin();
    while (prop != _prop_vector.end())
    {
        if (prop->GetPosition() == player->GetPosition())
        {
            mvprintw(0, 0, "You pick up the prop.\n");
            player->PickProp(*prop);
            prop = _prop_vector.erase(prop);
        }
        else
        {
            ++prop;
        }
    }
}

void LevelImpl::SetTotalLevel(const int &total_level)
{
    _total_level = total_level;
}