#pragma once
#include "matchfield_model.h"
#include "matchfield_view.h"
#include "player_interface.h"
#include "player_computer.h"
#include "player_human.h"
#include <array>
#include "E_FieldState.h"
#include "E_Difficulty.h"
#include <iostream>
#include <string>

class matchfield_controller
{
private:
	std::array<player_interface*, 2> m_player;		// Erzeugen eines Pointers auf ein zweistelliges Array vom Typ player_interface
	matchfield_model m_model;						// Erzeugen eines Objekts vom matchfield_model
	matchfield_view<int> m_view;					// Erzeugen eines Objekts vom matchfield_view
	int m_y = 0, m_x = 0;

public:
	matchfield_controller();
	~matchfield_controller();

	bool check(int, FieldState::FieldState);
	bool game();
	bool setup();
};

