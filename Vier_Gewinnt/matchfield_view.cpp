#include "matchfield_view.h"
#include "matchfield_model.h"
#include <iostream>

matchfield_view::matchfield_view()
{
}

matchfield_view::~matchfield_view()
{
}

void matchfield_view::show_model()      //Ausgeben des aktuellen Spielfeldes an die Konsole
{
    
    for (int i = 1; i < m_model->get_x(); i++) {
        for (int j = 1; j < m_model->get_y(); j++) {
            if (m_model->get_entry(i * j) == FieldState::FieldState::eEmpty) {
                std::cout << '| ' << '\t';
            }
            if (m_model->get_entry(i * j) == FieldState::FieldState::ePlayer1) {
                std::cout << '| x' << '\t';
            }
            if (m_model->get_entry(i * j) == FieldState::FieldState::ePlayer2) {
                std::cout << '| o' << '\t';
            }
        }
    }
}
