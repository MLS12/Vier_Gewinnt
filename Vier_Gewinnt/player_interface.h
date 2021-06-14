#pragma once
#include <string>
#include <iostream>

class player_interface
{
private:
	std::string m_name;

protected:

	// Der eingegebene Name soll nicht größer als 15 Buchstaben sein, sonst muss eine neue Eingabe erfolgen
	bool set_name(std::string s) {
		if (s.length() <= 15) {
			m_name = s;
			return true;
		}
		return false;
	};
	int m_x = 0;

public:
	virtual int make_move() = 0;					// Klasse wird durch die virtuelle Methode mit der entsprechenden Zuweisung zu einer abstrakten Klasse, wodurch kein Objekt dieser Klasse erzeugt werden kann
													// In den abgeleiteten Klassen muss diese Methode implementiert werden
	void set_x(int x) { m_x = x; };
	std::string get_name() { return m_name; };
};

