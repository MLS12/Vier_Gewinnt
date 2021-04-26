#include "matchfield_model.h"

matchfield_model::matchfield_model()
{
}

matchfield_model::matchfield_model(int, int)
{
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
