#include "player_computer.h"
#include "player_human.h"
#include <Windows.h>

matchfield_controller::matchfield_controller()
{
    m_player.at(0) = NULL;
    m_player.at(1) = NULL;
    m_y = 4;
    m_x = 4;

}

matchfield_controller::~matchfield_controller()
{
    delete m_player.at(0);
    delete m_player.at(1);
}

bool matchfield_controller::check(int nColumn, FieldState::FieldState state) //kontrolliert übergebe Spaltennummer auf freie Felder/ruft make_entry auf
{
    std::vector <std::vector<int>> numberField;          //Vektor mit Feldnummern
    int nField = 0, i = 0, cnt = 0;
    FieldState::FieldState stateOfField;

    numberField.resize(m_y);                //Festlegen der Spielfeldgröße auf den Feldnummern-Vektor
    for (auto& i : numberField) {
        i.resize(m_x);
    }
    for (int i = 0; i < m_y; i++) {         //Durchnummerieren der Felder im Feldnummern-Vektor
        for (int j = 0; j < m_x; j++) {
            numberField.at(i).at(j) = cnt++;
        }
    }

    if  ( nColumn < m_x){                   //Spalte zu groß
        return false;
    }
    else {
        do {
            stateOfField = m_model.get_entry((nColumn + 1) + (i * m_x));  //Zustand des Feldes abspeichern
            i++;                                                                        //Zeilenzähler
        } while ((stateOfField != FieldState::FieldState::eEmpty) || (i != (m_y + 1)));

        if ((i == 1) && (stateOfField != FieldState::FieldState::eEmpty)) { //erstes Feld der Spalte schon besetzt
            return false;
        }

        m_model.make_entry(numberField[i - 2][nColumn], state); //Abspeichern des Zustandes in Feld mit Feldnummer
        return true;
    }
}

bool matchfield_controller::game()
{
    int nWinner = 0;
 
    if (!setup()) {                                                         // Aufrufen des Setups zum Abfragen der Spielfeldgroesse und der Spieler selbst
        return false;
    };

    std::cout << "Das Spiel kann nun beginnen! Du kannst das Spiel mit der ESC-Taste beenden!" << std::endl;

    Sleep(200);

    system("CLS");

    m_view.show_model();

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) || nWinner != 1 || nWinner != 2) {      // Ausführen der Spielanweisungen, bis ein Gewinner ermittelt wird oder der Spieler mit ESC beendet
        for (int i = 1; i <= 2; i++) {
            if (i == 1) check(m_player.at(0)->make_move(), FieldState::FieldState::ePlayer1);
            else if(i == 2) check(m_player.at(1)->make_move(), FieldState::FieldState::ePlayer2);

            system("CLS");

            m_view.show_model();

            if (m_model.search_winner()) {
                nWinner = i;
                break;
            }
        }
    };

    std::cout << "Herzlichen Glueckwunsch " << m_player.at(nWinner) << "! Du hast gewonnen!" << std::endl;
    std::cout << "Das Spiel wird beendet!" << std::endl;

    m_model.clear_field();
    
    return true;
    
}

bool matchfield_controller::setup()
{
    int nHumanPlayers = 3, DifP1 = 0, DifP2 = 0;
    std::string cPlayer1{}, cPlayer2{};

    // Einlesen der Spielfeldgröße in X- und Y-Richtung
    // X-Richtung
    do {
        std::cout << "Bitte geben Sie die Spielfeldgroesse in x-Richtung ein (4 - 100): " << std::endl;
        std::cin >> m_x;
        system("CLS");
    } while (m_x < 4 && m_x > 100);

    // Y-Richtung
    do {
        std::cout << "Bitte geben Sie die Spielfeldgroesse in xy-Richtung ein (4 - 100): " << std::endl;
        std::cin >> m_y;
        system("CLS");
    } while (m_y < 4 && m_y > 100);

    std::cout << "Ihr Spielfeld hat die Groesse " << m_x << "x" << m_y << " (XxY)" << std::endl;

    m_model.set_size(m_x,m_y);                                                   // Setze x und y Wert im Model
    m_view.set_x(m_x);                                                           // Setze x im View
    m_view.set_y(m_y);                                                          // Setze y im View

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
            m_player.at(0) = new player_computer(cPlayer1, DifP1);
            m_player.at(0)->set_x(m_x);

            std::cout << std::endl;

            std::cout << "Bitte gib einen Namen fuer Computer-Player 2 ein: ";
            std::cin >> cPlayer2;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 2 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP2;
                system("CLS");
            } while (DifP2 != 0 || DifP2 != 1 || DifP2 != 2);
            m_player.at(1) = new player_computer(cPlayer2, DifP2);
            m_player.at(1)->set_x(m_x);

            break;

        case 1:
            std::cout << "Bitte gib deinen Namen ein: ";
            std::cin >> cPlayer1;
            m_player.at(0) = new player_human(cPlayer1);
            m_player.at(0)->set_x(m_x);

            std::cout << std::endl;

            std::cout << "Bitte gib einen Namen fuer Computer-Player 2 ein: ";
            std::cin >> cPlayer2;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 2 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP2;
                system("CLS");
            } while (DifP2 != 0 || DifP2 != 1 || DifP2 != 2);
            m_player.at(1) = new player_computer(cPlayer2, DifP2);
            m_player.at(1)->set_x(m_x);

            break;

        case 2:
            std::cout << "Bitte gib den Namen von Player 1 ein: ";
            std::cin >> cPlayer1;
            m_player.at(0) = new player_human(cPlayer1);
            m_player.at(0)->set_x(m_x);

            std::cout << std::endl;

            std::cout << "Bitte gib den Namen von Player 2 ein: ";
            std::cin >> cPlayer2;
            m_player.at(1) = new player_human(cPlayer2);
            m_player.at(1)->set_x(m_x);

            break;

        default:
            std::cout << "Es ist ein Fehler aufgetreten. Das Spiel wird beendet!" << std::endl;
            return false;
            break;

    }

    return true;
}
