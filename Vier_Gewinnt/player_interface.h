#pragma once
#include <string>

class player_interface
{
protected:
	std::string m_name;

public:
	player_interface();
	player_interface(std::string);
	~player_interface();	

	virtual int make_move() = 0;
	bool set_name(std::string);
};

