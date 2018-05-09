#include "screen.h"
#include "screen_impl.h"

Screen::Screen():screen_impl(new ScreenImpl()){}

Screen::Screen(const Screen&rhs):screen_impl(new ScreenImpl(*rhs.screen_impl)){}

Screen& Screen::operator=(const Screen&rhs)
{
    *screen_impl = *rhs.screen_impl;
    return *this;
}

Screen::~Screen()=default;

int Screen::CheckPosition(const Position& position)const
{
    return screen_impl->CheckPosition(position);
}