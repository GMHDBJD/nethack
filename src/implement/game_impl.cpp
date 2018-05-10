#include "game_impl.h"
#include "ncurses.h"
#include "position.h"
#include <cstring>
#include <menu.h>

extern Screen screen;

GameImpl::GameImpl()
{
    for (int i = 0; i < 5; ++i)
    {
        _levels[i].SetIndex(i);
    }
}

void GameImpl::GameLoop()
{
    char ch;
    Position level_player_position;
    int temp_level = _current_level;
    level_player_position = _levels[_current_level].GetLevelPlayerPosition();
    _player.SetPosition(Position(level_player_position.GetX(), level_player_position.GetY()));
    screen << _levels[_current_level] << _player;
    mvprintw(0, 0, "Enjoy the game('t' to quit)");
    while (_player.GetHp() > 0 && (ch = getch()) != 't')
    {
        mvprintw(0, 0, "\n");
        temp_level = _current_level;
        if (HandleInput(ch))
        {
            clear();
            mvprintw(10, 30, "You Win!");
            refresh();
            getch();
            break;
        }
        if (_player.GetHp() <= 0)
        {
            clear();
            mvprintw(10, 30, "You Lose!");
            refresh();
            getch();
            break;
        }
        if (temp_level == _current_level)
            _levels[_current_level].SetLevelPlayerPosition(_player.GetPosition());
        level_player_position = _levels[_current_level].GetLevelPlayerPosition();
        _player.SetPosition(Position(level_player_position.GetX(), level_player_position.GetY()));
        screen << _levels[_current_level] << _player;
    }
    clear();
    mvprintw(10, 30, "See You!");
    refresh();
    getch();
    clear();
}

bool GameImpl::HandleInput(const char &input)
{
    extern Screen screen;
    _levels[_current_level].MoveMonstres(_player.GetPosition());
    if (strchr("12346789", input))
    {
        Position next_position = _player.GetNextPosition(input);
        if (screen.CheckPosition(next_position) == 1)
        {
            _levels[_current_level].UpdateMap(next_position);
            _player.SetPosition(next_position);
        }
    }
    else if (strchr("qweadzxc", input))
    {
        Position next_position = _player.GetNextPosition(input);
        _levels[_current_level].AttackMonstre(next_position, &_player);
    }
    else if (strchr("uj", input))
    {
        if (input == 'u' && _player.GetPosition() == _levels[_current_level].GetUpstairPosition())
        {
            ++_current_level;
            clear();
        }
        else if (input == 'j' && _player.GetPosition() == _levels[_current_level].GetDownstairPosition())
        {
            --_current_level;
            clear();
        }
    }
    else if (input == ',')
    {
        _levels[_current_level].Pick(&_player);
    }
    else if (input == 'm')
    {
        clear();
        _player.Menu();
        clear();
    }
    else if (input == 'y')
    {
        if (_levels[_current_level].GetWinPosition() == _player.GetPosition() && _current_level == 4)
        {
            return true;
        }
    }
    _levels[_current_level].AttackPlayer(&_player);
    return false;
}
