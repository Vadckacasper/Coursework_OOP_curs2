#include "Field.h"

bool Field::check()
{
	for (int i = 0; i < 4; i++)
	
		if ((a[i].x < 0) || (a[i].x >= N) || (a[i].y >= M)) return 0;
		else if (field[a[i].y][a[i].x]) return 0;
			return 1;
}

bool Field::check_end(int colorNum)
{
	for (int i = 0; i < 4; i++)
	{
		if (field[a[i].y][a[i].x] != colorNum && field[a[i].y][a[i].x] != 0 && a[i].y < 4) {
			return 1;
		}
		return 0;

	}
}

void Field::check_lines()
{
	int k = M - 1;
	for (int i = M - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}
		if (count < N) k--;
		else
			point += 1;
	}
}

void Field::Background(std::string str)
{
	texture.loadFromFile(str);
	background.setTexture(texture);
}



void  Field::Key_end (Figure& fig)
{
	if (Keyboard::isKeyPressed(Keyboard::Down)) fig.delay = 0.05;
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		system("pause");
	}
}

