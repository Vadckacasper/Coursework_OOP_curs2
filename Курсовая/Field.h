#pragma once
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include "Figure.h"
#include <sstream>

using namespace sf;
class Figure;

class Field
{
private:
	bool check();

public:
	friend Figure;
	const int M = 20;
	const int N = 10;
	bool ower = 0;
	std::string point = {0};
	Texture texture;
	Sprite background;
	int field[20][10] = { 0 };
	void check_lines();
	void Background(std::string str);
	void Key_end(Figure& fig);
	bool check_end(int colorNum);
};

