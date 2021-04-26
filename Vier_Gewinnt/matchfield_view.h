#pragma once
#include "matchfield_model.h"

class matchfield_view
{
private:
	matchfield_model* m_model;

public:
	matchfield_view();
	~matchfield_view();

	void show_model();

};

