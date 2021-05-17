#include "player_human.h"

player_human::player_human() : player_interface()
{
}

player_human::player_human(std::string s) : player_interface()
{
	set_name(s);
}

player_human::~player_human()
{
}

int player_human::make_move()
{
	int nUInp{};

	std::cout << get_name() << ", du bist an der Reihe! Gib die Spalte an (4 - " << m_x << "), in die du setzen moechtest!" << std::endl;
	std::cin >> nUInp;
	return nUInp;
}
