#include "matchfield_controller.h"
#include <Windows.h>

matchfield_controller::matchfield_controller()
{
    m_model = matchfield_model();
    m_view = matchfield_view<int>(&m_model);      
    m_player = {NULL, NULL};
    m_y = 4;
    m_x = 4;

}

matchfield_controller::~matchfield_controller()
{
    delete m_player.at(0);
    delete m_player.at(1);
}

bool matchfield_controller::check(int nColumn, FieldState::FieldState state) //kontrolliert ?bergebe Spaltennummer auf freie Felder/ruft make_entry auf
{
    std::vector <std::vector<int>> numberField;          //Vektor mit Feldnummern
    int nField = 0, i = 0, cnt = 1;
    FieldState::FieldState stateOfField;

    numberField.resize(m_y);                //Festlegen der Spielfeldgr??e auf den Feldnummern-Vektor
    for (auto& i : numberField) {
        i.resize(m_x);
    }
    for (int i = 0; i < m_y; i++) {         //Durchnummerieren der Felder im Feldnummern-Vektor
        for (int j = 0; j < m_x; j++) {
            numberField.at(i).at(j) = cnt++;
        }
    }

    if  ( nColumn > m_x){                   //Spalte zu gro?
        return false;
    }
    else {
        do {                                                            //Durchlaufen der Felder in der gew?nschten Spalte
            stateOfField = m_model.get_entry((nColumn) + (i * m_x));    //Zustand des Feldes abspeichern (Zeile f?r Zeile in der gew?nschten Spalte)
            i++;                                                                        //Zeilenz?hler
        } while ((stateOfField == FieldState::FieldState::eEmpty) && (i <= (m_y)));       //Solange abgesp. Feld leer ist und max. Zeilenzahl nicht ?berschritten 

        if ((i == 1) && (stateOfField != FieldState::FieldState::eEmpty)) { //erstes Feld der Spalte schon besetzt
            return false;
        }
        m_model.make_entry(numberField.at(i - 2).at(nColumn - 1), state); //Abspeichern des Zustandes in Feld mit Feldnummer
        return true;
    }
}

bool matchfield_controller::game()
{
    int nWinner = 3;
    bool bDraw = false;
 
    if (!setup()) {                                                         // Aufrufen des Setups zum Abfragen der Spielfeldgroesse und der Spieler selbst
        return false;
    };

    std::cout << "Das Spiel kann nun beginnen! Du kannst das Spiel mit der ESC-Taste beenden!" << std::endl;

    Sleep(2000);

    system("CLS");

    m_view.show_model();

    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && nWinner != 0 && nWinner != 1 && !bDraw) {      // Ausf?hren der Spielanweisungen, bis ein Gewinner ermittelt wird oder der Spieler mit ESC beendet
        for (int i = 0; i <= 1; i++) {
            while (!check(m_player.at(i)->make_move(), currentPlayer(i))) {     // Solange keine freie Spalte mittels Check gefunden wird, wird der Spieler im Player-Array 0 aufgefordert eine Spalte auszuwaehlen
                std::cout << std::endl << "Die Spalte ist voll! Bitte waehle eine andere Spalte aus!" << std::endl << std::endl;
            }

            system("CLS");

            m_view.show_model();

            if (m_model.search_winner()) {      // Kontrolliert, nachdem beide Spieler gespielt haben, ob ein Gewinner vorliegt
                nWinner = i;
                break;
            }

            if (m_model.search_draw()) {        // Kontroliiert, ob ein Unentschieden vorliegt, wenn keine Spalte mehr frei ist
                bDraw = true;
                break;
            }
        }
    }

    if (bDraw) {
        std::cout << "Unentschieden! Es sind keine weiteren Zuege moeglich." << std::endl;
    }
    else {
        std::cout << "Herzlichen Glueckwunsch " << m_player.at(nWinner)->get_name() << "! Du hast gewonnen!" << std::endl;  // Ausgabe des Spielernamens
    }
    
    std::cout << "Das Spiel wird beendet!" << std::endl;

    m_model.clear_field();
    
    return true;
    
}

bool matchfield_controller::setup()
{
    int nHumanPlayers = 3, DifP1 = 0, DifP2 = 0;
    std::string cPlayer1{}, cPlayer2{};

    // Einlesen der Spielfeldgr??e in X- und Y-Richtung
    // X-Richtung
    std::cout << "Bitte geben Sie die Spielfeldgroesse in x-Richtung ein (4 - 100): " << std::endl;
    std::cin >> m_x;
    while (m_x < 4 || m_x > 100) {
        std::cout << "Die Eingabe war Fehlerhaft! Bitte gib eine Zahl zwischen 4 - 100 ein: " << std::endl;
        std::cin >> m_x;
        system("CLS");
    }

    // Y-Richtung
    std::cout << "Bitte geben Sie die Spielfeldgroesse in y-Richtung ein (4 - 100): " << std::endl;
    std::cin >> m_y;
    while (m_y < 4 || m_y > 100) {
        std::cout << "Die Eingabe war Fehlerhaft! Bitte gib eine Zahl zwischen 4 - 100 ein: " << std::endl;
        std::cin >> m_y;
        system("CLS");
    }

    std::cout << "Ihr Spielfeld hat die Groesse " << m_x << "x" << m_y << " (XxY)" << std::endl << std::endl;

    m_model.set_size(m_x,m_y);                                                   // Setze x und y Wert im Model
    m_view.set_x(m_x);                                                           // Setze x im View
    m_view.set_y(m_y);                                                          // Setze y im View

    // Abfragen der Spieler
    std::cout << "Wie viele menschliche Spieler spielen das Spiel(0, 1, 2): ";
    std::cin >> nHumanPlayers;
    while (nHumanPlayers != 0 && nHumanPlayers != 1 && nHumanPlayers != 2) {
        std::cout << "Ihre Eingabe ist fehlerhaft! Bitte gib die Anzahl der menschlichen Spieler ein (0, 1, 2): " << std::endl;
        std::cin >> nHumanPlayers;
    }
    std::cout << std::endl;

    // Je nach Spielertyp wird der entsprechende Fall aufgerufen und Objekte in dem Spieler-Array erzeugt
    switch (nHumanPlayers) {
        case 0: 
            std::cout << "Bitte gib einen Namen fuer Computer-Player 1 ein: ";
            std::cin >> cPlayer1;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 1 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP1;
                system("CLS");
            } while (DifP1 != 0 && DifP1 != 1 && DifP1 != 2);
            m_player.at(0) = new player_computer(cPlayer1, DifP1);      // Erzeugen des Computer-Spielers im Player-Array an der Stelle 0
            m_player.at(0)->set_x(m_x);                                 // ?bergeben des x-Wertes an das erzeugte Objekt im Player-Array

            std::cout << std::endl;

            std::cout << "Bitte gib einen Namen fuer Computer-Player 2 ein: ";
            std::cin >> cPlayer2;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 2 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP2;
                system("CLS");
            } while (DifP2 != 0 && DifP2 != 1 && DifP2 != 2);
            m_player.at(1) = new player_computer(cPlayer2, DifP2);      // Erzeugen des Computer-Spielers im Player-Array an der Stelle 1
            m_player.at(1)->set_x(m_x);                                 // ?bergeben des x-Wertes an das erzeugte Objekt im Player-Array

            break;

        case 1:
            std::cout << "Bitte gib deinen Namen ein: ";
            std::cin >> cPlayer1;
            m_player.at(0) = new player_human(cPlayer1);            // Erzeugen des Mensch-Spielers im Player-Array an der Stelle 0
            m_player.at(0)->set_x(m_x);                             // ?bergeben des x-Wertes an das erzeugte Objekt im Player-Array

            std::cout << std::endl;

            std::cout << "Bitte gib einen Namen fuer Computer-Player 2 ein: ";
            std::cin >> cPlayer2;
            do {
                std::cout << "Bitte gib die Schwierigkeitsstufe von Computer-Player 2 ein (Easy = 0, Advanced = 1, Hard = 2): ";
                std::cin >> DifP2;
                system("CLS");
            } while (DifP2 != 0 && DifP2 != 1 && DifP2 != 2);
            m_player.at(1) = new player_computer(cPlayer2, DifP2);      // Erzeugen des Computer-Spielers im Player-Array an der Stelle 1
            m_player.at(1)->set_x(m_x);                                 // ?bergeben des x-Wertes an das erzeugte Objekt im Player-Array

            break;

        case 2:
            std::cout << "Bitte gib den Namen von Player 1 ein: ";
            std::cin >> cPlayer1;
            m_player.at(0) = new player_human(cPlayer1);            // Erzeugen des Mensch-Spielers im Player-Array an der Stelle 0
            m_player.at(0)->set_x(m_x);                             // ?bergeben des x-Wertes an das erzeugte Objekt im Player-Array

            std::cout << std::endl;

            std::cout << "Bitte gib den Namen von Player 2 ein: ";
            std::cin >> cPlayer2;
            m_player.at(1) = new player_human(cPlayer2);            // Erzeugen des Mensch-Spielers im Player-Array an der Stelle 0
            m_player.at(1)->set_x(m_x);                             // ?bergeben des x-Wertes an das erzeugte Objekt im Player-Array

            break;

        default:
            std::cout << "Es ist ein Fehler aufgetreten. Das Spiel wird beendet!" << std::endl;
            return false;
            break;

    }

    return true;
}

FieldState::FieldState matchfield_controller::currentPlayer(int z)      // Methode, um den aktuellen Spieler in Abh?ngigkeit eines int-Wertes zur?ck zu geben
{
    if (z == 0) return FieldState::FieldState::ePlayer1;
    else if (z == 1) return FieldState::FieldState::ePlayer2;
}
