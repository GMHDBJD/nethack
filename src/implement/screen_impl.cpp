#include "screen_impl.h"
#include <cstring>
#include <ncurses.h>

int ScreenImpl::CheckPosition(const Position &position) const
{
    auto c = mvinch(position.GetY(), position.GetX());
    auto lc = mvinch(position.GetY(), position.GetX() - 1);
    auto uc = mvinch(position.GetY() - 1, position.GetX());
    auto dc = mvinch(position.GetY() + 1, position.GetX());
    bool open_door = ((c == '|' && lc == '-') || (c == '-' && ((uc == '|' && dc == '|') || (uc == '-' && dc == '|') || (uc == '|' && dc == '-'))));
    if (strchr("#.<>", c) || open_door)
        return 1;
    return 0;
}

ScreenImpl::ScreenImpl()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
}

ScreenImpl::~ScreenImpl()
{
    endwin();
}