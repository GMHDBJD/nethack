#include "prop_impl.h"
#include <ncurses.h>
#include <cstdio>
#include <cstring>

PropImpl::PropImpl(const int &index) : _index(index) {}

int PropImpl::GetIndex() const
{
    return _index;
}

Position PropImpl::GetPosition() const
{
    return _position;
}


Screen &operator<<(Screen &screen, const PropImpl &prop_impl)
{
    switch (prop_impl._index)
    {
    case 0:
        mvaddch(prop_impl._position.GetY(), prop_impl._position.GetX(), 'B');
        break;
    case 1:
        mvaddch(prop_impl._position.GetY(), prop_impl._position.GetX(), 'A');
        break;
    case 2:
        mvaddch(prop_impl._position.GetY(), prop_impl._position.GetX(), 'S');
        break;
    }
    return screen;
}

void PropImpl::SetPosition(const Position &__position)
{
    _position = __position;
}
