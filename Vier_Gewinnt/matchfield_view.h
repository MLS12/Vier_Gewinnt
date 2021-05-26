#pragma once
#include "matchfield_model.h"
//#include "matchfield_controller.h"

class matchfield_view
{
private:
	matchfield_model* m_model;
	int m_x = 0, m_y = 0;

public:
	matchfield_view();
	~matchfield_view();

	void show_model();
	void set_x(int);
	void set_y(int);

};

