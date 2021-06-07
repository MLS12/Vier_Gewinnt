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

	std::cout << get_name() << ", du bist an der Reihe! Gib die Spalte an (1 - " << m_x << "), in die du setzen moechtest!" << std::endl;
	std::cin >> nUInp;

	// Fehler bei Buchstabeneingabe
	while (nUInp < 1 || nUInp > m_x) {
		std::cout << "Deine Eingabe ist ungueltig! Gib eine Spalte zwischen 1 und " << m_x << " an!" << std::endl;
		std::cin >> nUInp;
	}

	return nUInp;
}
