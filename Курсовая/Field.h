#pragma once
#include "Figure.h"


class Field
{

public:
	const int M = 20;
	const int N = 10;
	int field[20][10] = { 0 };
	bool check();
	void check_lines();
};

