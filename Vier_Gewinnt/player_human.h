#pragma once
#include "player_interface.h"
class player_human	:	public player_interface
{
public:
	player_human();
	player_human(std::string);
	~player_human();

	int make_move();
};

