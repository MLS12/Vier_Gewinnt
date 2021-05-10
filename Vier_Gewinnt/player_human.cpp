#include "player_human.h"

player_human::player_human() : player_interface()
{
}

player_human::player_human(std::string s) : player_interface{ s }
{
}

player_human::~player_human()
{
}

int player_human::make_move()
{
	return 0;
}
