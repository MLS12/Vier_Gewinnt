#include "matchfield_view.h"
#include <iostream>

matchfield_view::~matchfield_view()
{
}

void matchfield_view::show_model()      //Ausgeben des aktuellen Spielfeldes an die Konsole
{
    int k = 1;
    
    for (int i = 1; i < m_x+1; i++) {
        for (int j = 1; j < m_y+1; j++) {
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
}

void matchfield_view::set_x(int x)
{
    m_x = x;
}

void matchfield_view::set_y(int y)
{
    m_y = y;
}
