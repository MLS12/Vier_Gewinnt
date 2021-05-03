#include "matchfield_model.h"

matchfield_model::matchfield_model()
{
}

matchfield_model::matchfield_model(int x, int y)
{
    m_x = x;                    //Speichern der X-Gr��e des Spielfeldes
    m_y = y;                    //Speichern der Y-Gr��e des Spielfeldes
    m_field.resize(m_y);        //Spielfeld auf Y-Gr��e bringen
    for (auto& i : m_field) {
        i.resize(m_x);          //Spielfeld auf X-Gr��e bringen
    }
}

matchfield_model::~matchfield_model()
{
}

void matchfield_model::clear_field()
{
}

int matchfield_model::get_coordinateX(int field)     //Gibt die X-Koordinate eines �bergebenen Feldes zur�ck
{
    std::vector <std::vector<int>> numberField; //Vektor mit Feld-Nummern
    int cnt = 1;
    int x = 0;

    numberField.resize(m_y);                    //Festlegen der Spielfeldgr��e auf den Feldnummern-Vektor
    for (auto& i : numberField) {
        i.resize(m_x);
    }
    for (int i = 0; i < m_y; i++) {             //Durchnummerieren der Felder im Feldnummern-Vektor
        for (int j = 0; j < m_x; j++) {
            numberField[i][j] = cnt++;
        }
    }

    for (int i = 0; i < m_y; i++) {             //Durchsuchen des Feldnummern-Vektors nach �bergebener Feldnummer
        for (int j = 0; j < m_x; j++) {
            if (numberField[i][j] == field) {
                x = i;                          //Speichern der X-Koordinate
            }
        }
    }
    return x;
}

int matchfield_model::get_coordinateY(int field)     //Gibt die Y-Koordinate eines �bergebenen Feldes zur�ck
{
    std::vector <std::vector<int>> numberField; //Vektor mit Feld-Nummern
    int cnt = 1;
    int y = 0;

    numberField.resize(m_y);                    //Festlegen der Spielfeldgr��e auf den Feldnummern-Vektor
    for (auto& i : numberField) {
        i.resize(m_x);
    }
    for (int i = 0; i < m_y; i++) {             //Durchnummerieren der Felder im Feldnummern-Vektor
        for (int j = 0; j < m_x; j++) {
            numberField[i][j] = cnt++;
        }
    }

    for (int i = 0; i < m_y; i++) {             //Durchsuchen des Feldnummern-Vektors nach �bergebener Feldnummer
        for (int j = 0; j < m_x; j++) {
            if (numberField[i][j] == field) {
                y = j;                          //Speichern der Y-Koordinate
            }
        }
    }
    return y;
}

bool matchfield_model::make_entry(int field, FieldState::FieldState state)  //Eintragen eines Zustandes an das �bergebene Feld
{
    m_field.at(get_coordinateX(field)).at(get_coordinateY(field)) = state;            //Speichern des �bergebenen Zustandes in das Spielfeld
    return true;
}

FieldState::FieldState matchfield_model::get_entry(int field)
{
    return m_field.at(get_coordinateX(field)).at(get_coordinateY(field));             //R�ckgabe des Zustandes in der �bergebenen Feldnummer
}
