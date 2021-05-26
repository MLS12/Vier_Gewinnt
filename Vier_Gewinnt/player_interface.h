#pragma once
#include <string>
#include <iostream>
//#include "matchfield_controller.h"

class player_interface
{
private:
	std::string m_name;

protected:
	bool set_name(std::string s) {
		if (s.length() <= 15) {
			m_name = s;
			return true;
		}
		return false;
	};
	int m_x = 0;

public:
	virtual int make_move() = 0;
	void set_x(int x) { m_x = x; };
	std::string get_name() { return m_name; };
};

