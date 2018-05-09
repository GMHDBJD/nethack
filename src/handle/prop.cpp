#include "prop.h"
#include "prop_impl.h"

Position Prop::GetPosition() const
{
    return prop_impl->GetPosition();
}

int Prop::GetIndex() const
{
    return prop_impl->GetIndex();
}

Screen &operator<<(Screen &screen, const Prop &prop)
{
    return screen << *prop.prop_impl;
}

Prop::Prop(const int &index) : prop_impl(new PropImpl(index)) {}

Prop::Prop(const Prop &rhs) : prop_impl(new PropImpl(*rhs.prop_impl)) {}

Prop &Prop::operator=(const Prop &rhs)
{
    *prop_impl = *rhs.prop_impl;
    return *this;
}

void Prop::SetPosition(const Position &_position)
{
    prop_impl->SetPosition(_position);
}

Prop::~Prop() = default;