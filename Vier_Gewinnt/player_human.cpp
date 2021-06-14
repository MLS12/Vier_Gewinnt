#include "player_human.h"

player_human::player_human() : player_interface()
{
}

player_human::player_human(std::string s)
{
	while (!set_name(s) || !std::cin.good()) {		// Überprüfen, ob der Name nicht zu lang ist und ggf. neue Abfrage
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Der Name ist zu lang! Gib bitte einen kuerzeren Namen ein: " << std::endl;
		std::cin >> s;
	}
}

player_human::~player_human()
{
}

// Virtuelle Funktion aus dem play_interface wird hier implementiert, aber anders, als beim player_computer
int player_human::make_move()
{
	int nUInp{};

	std::cout << get_name() << ", du bist an der Reihe! Gib die Spalte an (1 - " << m_x << "), in die du setzen moechtest!" << std::endl;
	std::cin >> nUInp;

	while (!std::cin.good() || nUInp > m_x || nUInp < 1) { //Erneute Eingabe bei zu großer/zu kleiner Zahl oder bei Buchstabeneingabe
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Deine Eingabe ist ungueltig! Gib eine Spalte zwischen 1 und " << m_x << " an!" << std::endl;
		std::cin >> nUInp;
	}

	return nUInp;
}
