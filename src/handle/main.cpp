#include "game.h"
#include "screen.h"
#include <ncurses.h>
#include <random>

Screen screen;

int main()
{
    srand(time(0));
    Game game;
    game.gameLoop();
    return 0;
}