#pragma once
#include <vector>
#include "E_FieldState.h"

class matchfield_model
{
private:
	
	int m_y = 0, m_x = 0;
	std::vector <std::vector<FieldState::FieldState>> m_field;	// Erzeugen eines zweidimensionalen Vectors, welcher das Spielfeld vom Typ FieldState aufbaut

public:

	matchfield_model();
	~matchfield_model();

	bool make_entry(int, FieldState::FieldState);
	FieldState::FieldState get_entry(int);
	void clear_field();
	int get_coordinateX(int);
	int get_coordinateY(int);
	void set_size(int, int);
	bool search_winner();
	bool search_draw();

};