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

    // Einlesen der Spielfeldgröße in X- und Y-Richtung
    do {
        std::cout << "Bitte geben Sie die Spielfeldgroesse in x-Richtung ein (4 - 100): " << std::endl;
        std::cin >> nFieldX;
        system("CLS");
    } while (nFieldX < 4 && nFieldX > 100);

    do {
        std::cout << "Bitte geben Sie die Spielfeldgroesse in xy-Richtung ein (4 - 100): " << std::endl;
        std::cin >> nFieldY;
        system("CLS");
    } while (nFieldY < 4 && nFieldY > 100);

    std::cout << "Ihr Spielfeld hat die Groesse " << nFieldX << "*" << nFieldY << " (X*Y)" << std::endl;

    matchfield_model::matchfield_model(nFieldX, nFieldY);


    // Abfragen der Spieler-Namen

    // Abfragen des Schwierigkeitsgrades bei Computer-Spieler

    return false;
}
