#pragma once
#include "player_interface.h"
#include "E_Difficulty.h"

class player_computer	:	public player_interface
{
private:
	Difficulty::Difficulty m_dif;

public:
	player_computer();
	player_computer(std::string, int);
	~player_computer();

	int make_move();
};

