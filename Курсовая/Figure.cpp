#include "Figure.h"
Point a[4], b[4];


Figure::Figure(std::string str)
{
	texture.loadFromFile(str);
	 s.setTexture(texture);
	 s.setTextureRect(IntRect(0, 0, 18, 18));
}

void Figure::paint(int i)
{
	s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
	s.setPosition(a[i].x * 18, a[i].y * 18);
}

void Figure::key(Event event)
{
	if (event.type == Event::KeyPressed)
		if (event.key.code == Keyboard::Up) rotate = true;
		else if (event.key.code == Keyboard::Left) dx = -1;
		else if (event.key.code == Keyboard::Right) dx = 1;
}

void Figure::Rotate(Field& ch)
{
	if (rotate)
	{
		
		Point p = a[1];
		for (int i = 0; i < 4; i++)
		{
			int x = a[i].y - p.y;
			int y = a[i].x - p.x;
			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}
		if (!(ch.check()))
			for (int i = 0; i < 4; i++)
			{
				a[i] = b[i];
			}
	}
}

void Figure::Move(Field& ch)
{
	
	for (int i = 0; i < 4; i++)
	{
		b[i] = a[i];
		a[i].x += dx;
	}
	if (!(ch.check()))
		for (int i = 0; i < 4; i++)
		{
			a[i] = b[i];
		}
}

void Figure::Timer()
{
	float time = clock.getElapsedTime().asSeconds();
	float q = time;
	clock.restart();
	timer += time;

}

void Figure::Tick(Field& ch)
{
	srand(time(NULL));
	if (!(ch.check_end(colorNum)))
	{
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++)
			{
				b[i] = a[i];
				a[i].y += 1;
			}
			if (!(ch.check()))
			{
				for (int i = 0; i < 4; i++)
					ch.field[b[i].y][b[i].x] = colorNum;
				int rand_x = rand() % 9;
				colorNum = 1 + rand() % 7;
				int n = rand() % 7;
				for (int i = 0; i < 4; i++)
				{
					a[i].x =rand_x + figures[n][i] % 2;
					a[i].y = figures[n][i] / 2;
				}
			}
			timer = 0;

		}
	}
	else
		for (int i = 0; i < ch.M; i++)
			for (int j = 0; j < ch.N; j++)
				ch.field[i][j] = 0;
}

