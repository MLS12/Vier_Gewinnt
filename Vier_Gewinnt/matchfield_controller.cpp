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
    //Testkommentar im check
    return false;
}

bool matchfield_controller::game()
{
    // Test

    return false;
}

bool matchfield_controller::search_winner()
{
    return false;
}

bool matchfield_controller::setup()
{
    int nFieldX = 0, nFieldY = 0, nHumanPlayers = 3, DifP1 = 0, DifP2 = 0;
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

    std::cout << "Ihr Spielfeld hat die Groesse " << nFieldX << "x" << nFieldY << " (XxY)" << std::endl;

    matchfield_model::matchfield_model(nFieldX, nFieldY);                                                   // Konstruktor - Aufruf Model


    // Abfragen der Spieler

    do {
        std::cout << "Wie viele menschliche Spieler spielen das Spiel(0, 1, 2): ";
        std::cin >> nHumanPlayers;
        system("CLS");
    } while (nHumanPlayers != 0 || nHumanPlayers != 1 || nHumanPlayers != 2);

    // Je nach Spielertyp geschieht die Eingabe und der entsprechende Konstruktor-Aufruf
    switch (nHumanPlayers) {
        case 0: 
            std::cout << "Bitte gib einen Namen fuer Computer-Player 1 ein: ";
            std::cin >> cPlayer1;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 1 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP1;
                system("CLS");
            } while (DifP1 != 0 || DifP1 != 1 || DifP1 != 2);
            m_player.at(0) = &player_computer(cPlayer1, DifP1);

            std::cout << std::endl;

            std::cout << "Bitte gib einen Namen fuer Computer-Player 2 ein: ";
            std::cin >> cPlayer2;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 2 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP2;
                system("CLS");
            } while (DifP2 != 0 || DifP2 != 1 || DifP2 != 2);
            m_player.at(1) = &player_computer(cPlayer2, DifP2);

            break;

        case 1:
            std::cout << "Bitte gib deinen Namen ein: ";
            std::cin >> cPlayer1;
            m_player.at(0) = &player_human(cPlayer1);

            std::cout << std::endl;

            std::cout << "Bitte gib einen Namen fuer Computer-Player 2 ein: ";
            std::cin >> cPlayer2;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 2 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP2;
                system("CLS");
            } while (DifP2 != 0 || DifP2 != 1 || DifP2 != 2);
            m_player.at(1) = &player_computer(cPlayer2, DifP2);

            break;

        case 2:
            std::cout << "Bitte gib den Namen von Player 1 ein: ";
            std::cin >> cPlayer1;
            m_player.at(0) = &player_human(cPlayer1);

            std::cout << std::endl;

            std::cout << "Bitte gib den Namen von Player 2 ein: ";
            std::cin >> cPlayer2;
            m_player.at(1) = &player_human(cPlayer2);

            break;

        default:
            std::cout << "Es ist ein Fehler aufgetreten. Das Spiel wird beendet!" << std::endl;
            return false;
            break;

    }

    return true;
}
