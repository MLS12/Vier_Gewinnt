#pragma once
#include "player_interface.h"
#include "E_Difficulty.h"

class player_computer	:	public player_interface
{
public:
	player_computer();
	player_computer(std::string, int);
	~player_computer();

	int make_move(Difficulty::Difficulty);
};

