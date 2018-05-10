#include "player.h"
#include "ncurses.h"
#include <algorithm>

Player::Player() : Creature(20, 5, 2), _experience(0), _gold(0) {}

int Player::GetExperience() const
{
    return _experience;
}
int Player::GetGold() const
{
    return _gold;
}

Screen &operator<<(Screen &screen, const Player &play)
{
    mvprintw(28, 2, "You:     Hp: %d(%d)", play._hp, play._max_hp);
    printw("    Attack: %d", play._attack);
    printw("    Defence: %d", play._defence);
    printw("    Gold: %d", play._gold);
    printw("    Exp: %d", play._experience);
    mvaddch(play.GetPosition().GetY(), play.GetPosition().GetX(), '@');
    return screen;
}

Position Player::GetNextPosition(const char &input) const
{
    Position new_position = GetPosition();
    switch (input)
    {
    case '4':
    case 'a':
        new_position = new_position.GetLeftPosition();
        break;
    case '6':
    case 'd':
        new_position = new_position.GetRightPosition();
        break;
    case '8':
    case 'w':
        new_position = new_position.GetUpPosition();
        break;
    case '2':
    case 'x':
        new_position = new_position.GetDownPosition();
        break;
    case '1':
    case 'z':
        new_position = new_position.GetLeftDownPosition();
        break;
    case '3':
    case 'c':
        new_position = new_position.GetRightDownPosition();
        break;
    case '7':
    case 'q':
        new_position = new_position.GetLeftUpPosition();
        break;
    case '9':
    case 'e':
        new_position = new_position.GetRightUpPosition();
        break;
    default:
        break;
    }
    return new_position;
}

Player &Player::SetGold(const int &gold)
{
    _gold = gold;
    return *this;
}
Player &Player::SetExperience(const int &experience)
{
    _experience = experience;
    return *this;
}

void Player::PickProp(const Prop &prop)
{
    _prop_vector.push_back(prop);
}

void Player::Menu()
{
    int medicine_num;
    int armor_num;
    int spinach_num;
    medicine_num = std::count_if(_prop_vector.begin(), _prop_vector.end(), [](const Prop &i) { return i.GetIndex() == 0; });
    armor_num = std::count_if(_prop_vector.begin(), _prop_vector.end(), [](const Prop &i) { return i.GetIndex() == 1; });
    spinach_num = std::count_if(_prop_vector.begin(), _prop_vector.end(), [](const Prop &i) { return i.GetIndex() == 2; });
    mvprintw(4, 0, "'m' to quit");
    mvprintw(2, 0, "You now have %d blood, %d armor and %d spinach.", medicine_num, armor_num, spinach_num);
    char choices[3][30] = {
        "Drink Blood (hp+5,max_hp+2)",
        "Wear Armor (defence+2)",
        "Eat Spinach (attack+2)",
    };
    int c;
    ITEM *props[4];
    MENU *menu;
    for (int i = 0; i < 3; ++i)
        props[i] = new_item(choices[i], "");
    props[3] = nullptr;
    menu = new_menu(props);
    set_menu_sub(menu, derwin(stdscr, 0, 0, 5, 0));
    post_menu(menu);
    refresh();
    bool enter = false;
    while (!enter && (c = getch()) != 'm')
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(menu, REQ_UP_ITEM);
            break;
        case 10:
            UseProp(item_index(current_item(menu)));
            enter = true;
            break;
        }
    }
    unpost_menu(menu);
    free_menu(menu);
    for (int i = 0; i < 3; ++i)
        free_item(props[i]);
}

void Player::UseProp(int index)
{
    auto i = _prop_vector.begin();
    while (i != _prop_vector.end())
    {
        if (i->GetIndex() == index)
        {
            _prop_vector.erase(i);
            switch (index)
            {
            case 0:
                _max_hp += 2;
                _hp = (_hp + 5 > _max_hp ? _max_hp : _hp + 5);
                break;
            case 1:
                _defence += 2;
                break;
            case 2:
                _attack += 2;
                break;
            }
            break;
        }
        ++i;
    }
}