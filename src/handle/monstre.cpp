#include "monstre.h"
#include <algorithm>
#include <ncurses.h>

Screen &operator<<(Screen &screen, const Monstre &monstre)
{
    mvaddch(monstre.GetPosition().GetY(), monstre.GetPosition().GetX(), 'M');
    return screen;
}

Position Monstre::GetNextPosition(const Position &destinate_position) const
{
    auto positions = _position.GetDirectorPosition();
    std::random_shuffle(positions.begin(), positions.end());
    for (const auto &i : positions)
    {
        if (i.Distance(destinate_position) < _position.Distance(destinate_position))
            return i;
    }
    return _position;
}

Monstre::Monstre(int max_hp, int attack, int defence) : Creature( max_hp,  attack,  defence) {}

