#include "Figure.h"
Point a[4], b[4];
Figure::Figure(std::string str)
{
	texture.loadFromFile(str);
	 s.setTexture(texture);
	 s.setTextureRect(IntRect(0, 0, 18, 18));
}


void Figure::Coordinate()
{
	for (int i = 0; i < 4; i++)
	{
		a[i].x = figures[n][i] % 2;
		a[i].y = figures[n][i] / 2;
	}
}

void Figure::paint(int i)
{
	s.setPosition(a[i].x * 18, a[i].y * 18);
}
