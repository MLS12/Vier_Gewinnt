#include "matchfield_controller.h"

matchfield_controller::matchfield_controller()
{
    m_player.at(0) = NULL;
    m_player.at(1) = NULL;
    m_model = NULL;
    m_view = NULL;

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
    int nFieldX = 0, nFieldY = 0;

    std::cout << "Bitte geben Sie die Spielfeldgroesse in x-Richtung ein: " << std::endl;
    std::cin >> nFieldX;

    std::cout << "Bitte geben Sie die Spielfeldgroesse in y-Richtung ein: " << std::endl;
    std::cin >> nFieldY;

    matchfield_model(nFieldX, nFieldY);

    return false;
}
