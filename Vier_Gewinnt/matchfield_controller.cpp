#include "matchfield_controller.h"

matchfield_controller::matchfield_controller()
{
}

matchfield_controller::~matchfield_controller()
{
}

bool matchfield_controller::check(int, FieldState::FieldState)
{
    return false;
}

bool matchfield_controller::game()
{
    return false;
}

bool matchfield_controller::search_winner()
{
    return false;
}

bool matchfield_controller::setup()
{
    return false;
}
