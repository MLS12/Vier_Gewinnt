#include "player_computer.h"
#include <random>

player_computer::player_computer() : player_interface()
{
}

player_computer::player_computer(std::string s, int dif) : player_interface()
{

	set_name(s);

	switch (dif) {
		case 0:
			m_dif = Difficulty::Difficulty::eEasy;
			break;

		case 1:
			std::cout << "Der Advanced-Mode ist noch nicht verfügbar! Der Computer spielt in der Schwierigkeitsstufe 'Easy'!" << std::endl;
			m_dif = Difficulty::Difficulty::eEasy;
			break;

		case 2:
			std::cout << "Der Hard-Mode ist noch nicht verfügbar! Der Computer spielt in der Schwierigkeitsstufe 'Easy'!" << std::endl;
			m_dif = Difficulty::Difficulty::eEasy;
			break;

		default:
			std::cout << "Die Eingabe war nicht korrekt! Der Computer spielt in der Schwierigkeitsstufe 'Easy'!" << std::endl;
			m_dif = Difficulty::Difficulty::eEasy;
			break;
	}
}

player_computer::~player_computer()
{
}

int player_computer::make_move()
{
	constexpr int nMin = 4;
	int nMax = m_x;		// Stöcker fragen, ob das so funktioniert
	

	switch (m_dif) {
	case Difficulty::Difficulty::eEasy:

		std::cout << get_name() << " ist an der Reihe und wird seinen Zug ausfuehren!" << std::endl;

		// Erzeugen einer Zufallszahl im Bereich 4 - X-Wert
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<int> distr(nMin, nMax);

		return distr(eng);

			break;

	case Difficulty::Difficulty::eAdvanced:

			// Code wird noch geschrieben

			break;

	case Difficulty::Difficulty::eHard:

			// Code wird noch geschrieben

			break;


	}
}
