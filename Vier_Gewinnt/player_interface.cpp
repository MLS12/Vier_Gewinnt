#include "player_interface.h"

player_interface::player_interface()
{
}

player_interface::player_interface(std::string s)
{
	if (!set_name(s))
		m_name = "unknown";
}

player_interface::~player_interface()
{
}

int player_interface::make_move()
{
	return 0;
}

bool player_interface::set_name(std::string s)
{
	if (s.length() <= 15) {
		m_name = s;
		return true;
	}
	return false;
}
