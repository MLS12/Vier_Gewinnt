#include "matchfield_model.h"

matchfield_model::matchfield_model()
{
    clear_field();
}

matchfield_model::~matchfield_model()
{
}

void matchfield_model::clear_field() // Leert jedes Feld
{
    for (int i = 0; i < m_y; i++) {
        for (int j = 0; j < m_x; j++) {
            m_field.at(i).at(j) = FieldState::FieldState::eEmpty;
        }
    }
}

int matchfield_model::get_coordinateX(int field)     //Gibt die X-Koordinate eines übergebenen Feldes zurück
{
    std::vector <std::vector<int>> numberField; //Vektor mit Feld-Nummern
    int cnt = 1;
    int x = 0;

    numberField.resize(m_y);                    //Festlegen der Spielfeldgröße auf den Feldnummern-Vektor
    for (auto& i : numberField) {
        i.resize(m_x);
    }
    for (int i = 0; i < m_y; i++) {             //Durchnummerieren der Felder im Feldnummern-Vektor
        for (int j = 0; j < m_x; j++) {
            numberField.at(i).at(j) = cnt++;
        }
    }

    for (int i = 0; i < m_y; i++) {             //Durchsuchen des Feldnummern-Vektors nach übergebener Feldnummer
        for (int j = 0; j < m_x; j++) {
            if (numberField.at(i).at(j) == field) {
                x = i;                       //Speichern der X-Koordinate
            }
        }
    }
    return x;
}

int matchfield_model::get_coordinateY(int field)     //Gibt die Y-Koordinate eines übergebenen Feldes zurück
{
    std::vector <std::vector<int>> numberField{}; //Vektor mit Feld-Nummern
    int cnt = 1;
    int y = 0;

    numberField.resize(m_y);                    //Festlegen der Spielfeldgröße auf den Feldnummern-Vektor FEHLER
    for (auto& i : numberField) {
        i.resize(m_x);
    }
    for (int i = 0; i < m_y; i++) {             //Durchnummerieren der Felder im Feldnummern-Vektor
        for (int j = 0; j < m_x; j++) {
            numberField.at(i).at(j) = cnt++;
        }
    }

    for (int i = 0; i < m_y; i++) {             //Durchsuchen des Feldnummern-Vektors nach übergebener Feldnummer
        for (int j = 0; j < m_x; j++) {
            if (numberField.at(i).at(j) == field) {
                y = j;                          //Speichern der Y-Koordinate
            }
        }
    }
    return y;
}

void matchfield_model::set_size(int x, int y)
{
    m_x = x;
    m_y = y;

    m_field.resize(y);        //Spielfeld auf Y-Größe bringen
    for (auto& i : m_field) {
        i.resize(x);          //Spielfeld auf X-Größe bringen
    }
}

bool matchfield_model::search_winner() //Überprüft auf waagerechte, senkrechte oder diagonale 4er-Paare
{
    // Waagerecht:
    for (int i = 0; i < m_y; i++) {
        for (int j = 0; j < m_x-3; j++) {
            if (m_field.at(i).at(j) == m_field.at(i).at(j + 1) &&
                m_field.at(i).at(j) == m_field.at(i).at(j + 2) &&
                m_field.at(i).at(j) == m_field.at(i).at(j + 3) &&
                m_field.at(i).at(j) != FieldState::FieldState::eEmpty)
            {
                return true;
            }
        }
    }

    // Senkrecht:
    for (int i = 0; i < m_y-3; i++) {
        for (int j = 0; j < m_x; j++) {
            if (m_field.at(i).at(j) == m_field.at(i + 1).at(j) &&
                m_field.at(i).at(j) == m_field.at(i + 2).at(j) &&
                m_field.at(i).at(j) == m_field.at(i + 3).at(j) &&
                m_field.at(i).at(j) != FieldState::FieldState::eEmpty)
            {
                return true;
            }
        }
    }

    // Diagonal 1:
    for (int i = 0; i < m_y-3; i++) {
        for (int j = 0; j < m_x-3; j++) {
            if (m_field.at(i).at(j) == m_field.at(i + 1).at(j + 1) &&
                m_field.at(i).at(j) == m_field.at(i + 2).at(j + 2) &&
                m_field.at(i).at(j) == m_field.at(i + 3).at(j + 3) &&
                m_field.at(i).at(j) != FieldState::FieldState::eEmpty)
            {
                return true;
            }
        }
    }

    // Diagonal 2:
    for (int i = m_y+3; i < m_y; i++) {
        for (int j = 0; j < m_x-3; j++) {
            if (m_field.at(i).at(j) == m_field.at(i + 1).at(j - 1) &&
                m_field.at(i).at(j) == m_field.at(i + 2).at(j - 2) &&
                m_field.at(i).at(j) == m_field.at(i + 3).at(j - 3) &&
                m_field.at(i).at(j) != FieldState::FieldState::eEmpty)
            {
                return true;
            }
        }
    }
    return false;

}

bool matchfield_model::make_entry(int field, FieldState::FieldState state)  //Eintragen eines Zustandes an das übergebene Feld
{
    m_field.at(get_coordinateX(field)).at(get_coordinateY(field)) = state;            //Speichern des übergebenen Zustandes in das Spielfeld
    return true;
}

FieldState::FieldState matchfield_model::get_entry(int field)
{
    return m_field.at(get_coordinateX(field)).at(get_coordinateY(field));             //Rückgabe des Zustandes in der übergebenen Feldnummer
}
