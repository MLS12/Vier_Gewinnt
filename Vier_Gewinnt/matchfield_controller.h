#pragma once
#include "matchfield_model.h"
#include "matchfield_view.h"
#include "player_interface.h"
#include <array>
#include "E_FieldState.h"
#include "E_Difficulty.h"
#include <iostream>
#include <string>

class matchfield_controller
{
private:
	std::array<player_interface*, 2> m_player;
	matchfield_model* m_model;
	matchfield_view* m_view;

public:
	matchfield_controller();
	~matchfield_controller();

	bool check(int, FieldState::FieldState);
	bool game();
	bool search_winner();
	bool setup();
	int get_matchfieldModelX() { return m_model->get_x(); };
	int get_matchfieldModelY() { return m_model->get_y(); };
};

