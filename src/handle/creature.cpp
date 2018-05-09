#include "creature.h"

Creature::Creature(int max_hp, int attack, int defence) : _max_hp(max_hp), _attack(attack), _hp(max_hp), _defence(defence) {}

Position Creature::GetPosition() const
{
    return _position;
}

int Creature::GetMaxHp() const
{
    return _max_hp;
}

int Creature::GetAttack() const
{
    return _attack;
}

int Creature::GetHp() const
{
    return _hp;
}

void Creature::SetMaxHp(const int &max_hp)
{
    _max_hp = max_hp;
}
void Creature::SetAttack(const int &attack)
{
    _attack = attack;
}
void Creature::SetHp(const int &hp)
{
    _hp = hp;
}

void Creature::SetDefence(const int &defence)
{
    _defence = defence;
}

void Creature::SetPosition(const Position &position)
{
    _position = position;
}

Creature &Creature::operator-=(const Creature &rhs)
{
    if (rhs._attack > _defence)
        _hp -= (rhs._attack - _defence);
    return *this;
}
