#include "player_human.h"
#include "matchfield_model.h"

player_human::player_human() : player_interface()
{
}

player_human::player_human(std::string s) : player_interface(s)
{
}

player_human::~player_human()
{
}

int player_human::make_move()
{
	int nUInp{};

	std::cout << m_name << ", du bist an der Reihe! Gib die Spalte an (4 - " << matchfield_model::get_y << "), in die du setzen moechtest!" << std::endl;
	std::cin >> nUInp;
	return nUInp;
}
