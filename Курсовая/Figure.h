#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
struct Point { int x, y; };

class Figure
{
public:
	Figure(std::string str);
	Texture texture;
	Sprite s;
	int n = 3;
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
	void Coordinate();
	void paint(int i);

};



