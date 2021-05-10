#pragma once
#include <string>
#include <iostream>
#include "matchfield_controller.h"

class player_interface
{
protected:
	std::string m_name;

	matchfield_controller* m_controller;	// Funktionell?!

public:
	player_interface();
	player_interface(std::string);
	~player_interface();	

	virtual int make_move();
	bool set_name(std::string);
};

