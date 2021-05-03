#include "matchfield_model.h"

matchfield_model::matchfield_model()
{
}

matchfield_model::matchfield_model(int x, int y)
{
    m_x = x;
    m_y = y;
    m_field.resize(m_y);
    for (auto& i : m_field) {
        i.resize(m_x);
    }
}

matchfield_model::~matchfield_model()
{
}

bool matchfield_model::make_entry(int, FieldState::FieldState)
{
    return false;
}

FieldState::FieldState matchfield_model::get_entry(int)
{
    return FieldState::FieldState();
}

void matchfield_model::clear_field()
{
}
