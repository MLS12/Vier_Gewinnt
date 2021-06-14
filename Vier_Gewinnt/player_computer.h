#pragma once
#include "player_interface.h"
#include "E_Difficulty.h"

class player_computer	:	public player_interface    // Klasse, die von dem player_interface abgeleitet ist
{
private:
	Difficulty::Difficulty m_dif;

public:
	player_computer();
	player_computer(std::string, int);
	~player_computer();

	int make_move();
};

