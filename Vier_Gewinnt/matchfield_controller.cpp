#include "matchfield_controller.h"
#include "player_computer.h"
#include "player_human.h"

matchfield_controller::matchfield_controller()
{
    m_player.at(0) = NULL;
    m_player.at(1) = NULL;
    m_model = NULL;
    m_view = NULL;

}

matchfield_controller::~matchfield_controller()
{
    delete m_player.at(0);
    delete m_player.at(1);
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
    int nFieldX = 0, nFieldY = 0, nHumanPlayers = 3;
    std::string cPlayer1{}, cPlayer2{};

    // Einlesen der Spielfeldgröße in X- und Y-Richtung
    // X-Richtung
    do {
        std::cout << "Bitte geben Sie die Spielfeldgroesse in x-Richtung ein (4 - 100): " << std::endl;
        std::cin >> nFieldX;
        system("CLS");
    } while (nFieldX < 4 && nFieldX > 100);

    // Y-Richtung
    do {
        std::cout << "Bitte geben Sie die Spielfeldgroesse in xy-Richtung ein (4 - 100): " << std::endl;
        std::cin >> nFieldY;
        system("CLS");
    } while (nFieldY < 4 && nFieldY > 100);

    std::cout << "Ihr Spielfeld hat die Groesse " << nFieldX << "*" << nFieldY << " (X*Y)" << std::endl;

    matchfield_model::matchfield_model(nFieldX, nFieldY);                                                   // Konstruktor - Aufruf Model


    // Abfragen der Spieler

    do {
        std::cout << "Wie viele menschliche Spieler spielen das Spiel(0, 1, 2): ";
        std::cin >> nHumanPlayers;
        system("CLS");
    } while (nHumanPlayers < 0 && nHumanPlayers > 2);

    // Je nach Spielertyp geschieht die Eingabe und der entsprechende Konstruktor-Aufruf
    switch (nHumanPlayers) {
        case 0: 
            std::cout << "Bitte gib einen Namen fuer Computer-Player 1 ein: ";
            std::cin >> cPlayer1;
            m_player.at(0) = &player_computer(cPlayer1);

    }







    // Abfragen des Schwierigkeitsgrades bei Computer-Spieler

    return false;
}
