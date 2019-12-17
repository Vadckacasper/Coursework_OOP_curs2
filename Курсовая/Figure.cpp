#include "Figure.h"

void Figure::sprint()
{
	texture.loadFromFile("images/tiles.png");
	 s.setTexture(texture);
	 s.setTextureRect(IntRect(0, 0, 18, 18));
}