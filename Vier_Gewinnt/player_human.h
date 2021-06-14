#pragma once
#include "player_interface.h"

class player_human	:	public player_interface     // Klasse, die von dem player_interface abgeleitet ist
{
public:
	player_human();
	player_human(std::string);
	~player_human();

	int make_move();
};

