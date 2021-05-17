#pragma once
#include <vector>
#include "E_FieldState.h"

class matchfield_model
{
private:
	
	int m_y = 0, m_x = 0;
	std::vector <std::vector<FieldState::FieldState>> m_field;	//Spielfeld-Vektor vom Typ FieldState

public:

	matchfield_model();
	~matchfield_model();

	bool make_entry(int, FieldState::FieldState);
	FieldState::FieldState get_entry(int);
	void clear_field();
	int get_coordinateX(int);
	int get_coordinateY(int);
	void set_size(int, int);
};