#pragma once
#include <string>
#include <iostream>

class player_interface
{
protected:
	std::string m_name;

public:
	player_interface();
	player_interface(std::string);
	~player_interface();	

	virtual int make_move();
	bool set_name(std::string);
};

