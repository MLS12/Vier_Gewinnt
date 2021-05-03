#pragma once
#include <vector>
#include "E_FieldState.h"

class matchfield_model
{
private:
	
	int m_x, m_y;
	std::vector <std::vector<FieldState::FieldState>> m_field;

public:
	matchfield_model();
	matchfield_model(int, int);
	~matchfield_model();

	bool make_entry(int, FieldState::FieldState);
	FieldState::FieldState get_entry(int);
	void clear_field();

};

