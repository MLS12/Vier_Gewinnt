#pragma once
#include "matchfield_model.h"
#include "matchfield_view.h"
#include "player_interface.h"
#include <array>
#include "E_FieldState.h"
#include <iostream>

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

};

