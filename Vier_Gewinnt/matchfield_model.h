#pragma once
#include <vector>
#include "E_FieldState.h"

class matchfield_model
{
private:
	
	int m_x, m_y;												//Größe des Spielfeldes
	std::vector <std::vector<FieldState::FieldState>> m_field;	//Spielfeld-Vektor vom Typ FieldState

public:


	matchfield_model();
	matchfield_model(int, int);
	~matchfield_model();

	bool make_entry(int, FieldState::FieldState);
	FieldState::FieldState get_entry(int);
	void clear_field();
	int get_coordinateX(int);
	int get_coordinateY(int);
	int get_x() {
		return m_x;
	}
	int get_y() {
		return m_y;
	}
};