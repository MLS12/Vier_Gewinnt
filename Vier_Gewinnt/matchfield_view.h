#pragma once
#include "matchfield_model.h"
#include <iostream>

template <typename coordinates> class matchfield_view       // Erzeugen einer Template-Klasse, damit Datentyp unabhängig ein Spielfeld erzeugt werden könnte (Bei uns natürlich trotzdem nur Ganzzahlig)
{
private:
	matchfield_model* m_model = nullptr;
	coordinates m_x, m_y;

public:
	matchfield_view() { m_model = nullptr; };
	matchfield_view(matchfield_model* m) : m_model(m) {};
    ~matchfield_view() {};

	void show_model() {
        int k = 1;

        for (int i = 1; i < m_y + 1; i++) {
            for (int j = 1; j < m_x + 1; j++) {
                if (m_model->get_entry(k) == FieldState::FieldState::eEmpty) {
                    std::cout << "| " << "\t";
                }
                if (m_model->get_entry(k) == FieldState::FieldState::ePlayer1) {
                    std::cout << "| x" << "\t";
                }
                if (m_model->get_entry(k) == FieldState::FieldState::ePlayer2) {
                    std::cout << "| o" << "\t";
                }
                k++;
            }
            std::cout << "| \n";
        }
    };
	void set_x(coordinates x) { m_x = x; };
	void set_y(coordinates y) { m_y = y; };

};

