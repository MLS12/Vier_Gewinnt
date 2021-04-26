#pragma once
#include "player_interface.h"
class player_computer	:	public player_interface
{
public:
	player_computer();
	~player_computer();

	int make_move();
};

