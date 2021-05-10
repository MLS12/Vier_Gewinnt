#include "player_computer.h"
#include "matchfield_model.h"

player_computer::player_computer() : player_interface()
{
}

player_computer::player_computer(std::string s, int dif) : player_interface(s)
{

	switch (dif) {
		case 0:
			make_move(Difficulty::Difficulty::eEasy);
			break;

		case 1:
			std::cout << "Der Advanced-Mode ist noch nicht verfügbar! Der Computer spielt in der Schwierigkeitsstufe 'Easy'!" << std::endl;
			make_move(Difficulty::Difficulty::eEasy);
			break;

		case 2:
			std::cout << "Der Hard-Mode ist noch nicht verfügbar! Der Computer spielt in der Schwierigkeitsstufe 'Easy'!" << std::endl;
			make_move(Difficulty::Difficulty::eEasy);
			break;

		default:
			std::cout << "Die Eingabe war nicht korrekt! er Computer spielt in der Schwierigkeitsstufe 'Easy'!" << std::endl;
			make_move(Difficulty::Difficulty::eEasy);
			break;
	}
}

player_computer::~player_computer()
{
}

int player_computer::make_move(Difficulty::Difficulty dif)
{
	switch (dif) {
	eEasy:

		std::cout << m_name << "ist an der Reihe und wird seinen Zug ausfuehren!" << std::endl;

			break;

		eAdvanced:

			// Code wird noch geschrieben

			break;

		eHard:

			// Code wird noch geschrieben

			break;


	}
}
