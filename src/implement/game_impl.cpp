#include "game_impl.h"
#include "position.h"
#include <cstring>
#include <menu.h>
#include <ncurses.h>

extern Screen screen;

GameImpl::GameImpl(const int &choice) : _current_level(0), _top_level(0)
{
    if (choice == 3)
        _total_level = 1000;
    else
        _total_level = (choice + 1) * 5;
    Level new_level;
    new_level.SetIndex(_current_level);
    new_level.SetTotalLevel(_total_level);
    _level_vecotr.push_back(new_level);
}

void GameImpl::MainGame()
{
    clear();
    char ch;
    Position level_player_position;
    int temp_level = _current_level;
    level_player_position = _level_vecotr[_current_level].GetLevelPlayerPosition();
    _player.SetPosition(Position(level_player_position.GetX(), level_player_position.GetY()));
    screen << _level_vecotr[_current_level] << _player;
    mvprintw(0, 0, "Enjoy the game('t' to quit)");
    while (_player.GetHp() > 0 && (ch = getch()) != 't')
    {
        mvprintw(0, 0, "\n");
        temp_level = _current_level;
        if (SwitchChoice(ch))
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
            _level_vecotr[_current_level].SetLevelPlayerPosition(_player.GetPosition());
        level_player_position = _level_vecotr[_current_level].GetLevelPlayerPosition();
        _player.SetPosition(Position(level_player_position.GetX(), level_player_position.GetY()));
        screen << _level_vecotr[_current_level] << _player;
    }
    clear();
}

bool GameImpl::SwitchChoice(const char &input)
{
    extern Screen screen;
    _level_vecotr[_current_level].MoveMonstres(_player.GetPosition());
    if (strchr("12346789", input))
    {
        Position next_position = _player.GetNextPosition(input);
        if (screen.CheckPosition(next_position) == 1)
        {
            _level_vecotr[_current_level].UpdateMap(next_position);
            _player.SetPosition(next_position);
        }
    }
    else if (strchr("qweadzxc", input))
    {
        Position next_position = _player.GetNextPosition(input);
        _level_vecotr[_current_level].AttackMonstre(next_position, &_player);
    }
    else if (strchr("uj", input))
    {
        if (input == 'u' && _player.GetPosition() == _level_vecotr[_current_level].GetUpstairPosition()&&_current_level!=_total_level)
        {
            if (_current_level == _top_level)
            {
                Level new_level;
                new_level.SetIndex(_current_level + 1);
                new_level.SetTotalLevel(_total_level);
                _level_vecotr.push_back(new_level);
                ++_top_level;
            }
            ++_current_level;
            clear();
        }
        else if (input == 'j' && _player.GetPosition() == _level_vecotr[_current_level].GetDownstairPosition()&&_current_level!=0)
        {
            --_current_level;
            clear();
        }
    }
    else if (input == ',')
    {
        _level_vecotr[_current_level].Pick(&_player);
    }
    else if (input == 'm')
    {
        clear();
        _player.Menu();
        clear();
    }
    else if (input == 'y')
    {
        if (_level_vecotr[_current_level].GetWinPosition() == _player.GetPosition() && _current_level == _total_level - 1)
        {
            return true;
        }
    }
    _level_vecotr[_current_level].AttackPlayer(&_player);
    return false;
}
