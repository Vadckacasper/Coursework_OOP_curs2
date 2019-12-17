#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Field.h"

using namespace sf;
class Field;

class Figure
{
public:
	friend Field;
	Figure(std::string str);
	Texture texture;
	Sprite s;

	int dx = 0, colorNum = 1;
	bool rotate = 0;
	float timer = 0, delay = 0.3;
	Clock clock;
	int figures[7][4] =
	{
		1,3,5,7,
		2,4,5,7,
		3,5,4,6,
		3,5,4,7,
		2,3,5,7,
		3,5,7,6,
		2,3,4,5,
	};
	void Coordinate(int n);
	void paint(int i);
	void key(Event event);
	void Rotate(Field& ch);
	void Move(Field& ch);
	void Timer();
	void Tick(Field& ch);


};



struct Point { int x, y; };
extern Point a[4], b[4];