#include "player_computer.h"
#include <random>

player_computer::player_computer() : player_interface()
{
}

player_computer::player_computer(std::string s, int dif) 
{
	while (!set_name(s) || !std::cin.good()) {			// Überprüfen, ob der Name nicht zu lang ist und ggf. neue Abfrage
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Der Computer-Name ist zu lang! Gib bitte einen kuerzeren Namen ein: " << std::endl;
		std::cin >> s;
	}

	switch (dif) {		// Zuweisen der Schwierigkeit in Abhängigkeit der ausgewaehlten Schwierigkeitsstufe
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

// Virtuelle Funktion aus dem play_interface wird hier implementiert, aber ander als beim player_human
int player_computer::make_move()
{
	constexpr int nMin = 1;
	int nMax = m_x;		
	
	// Erzeugen einer Zufallszahl im Bereich 1 - X-Wert
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(nMin, nMax);

	// In Abhägigkeit der eingegebenen Schweirigkeit wird eine entsprechende "Intielligenz" bei den Spielzügen angewandt
	switch (m_dif) {
	case Difficulty::Difficulty::eEasy:

		std::cout << get_name() << " ist an der Reihe und wird seinen Zug ausfuehren!" << std::endl;

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
