#include <SFML/Graphics.hpp>
#include <string.h>
#include <time.h>
#include "Figure.h"

using namespace sf;


int main()
{
	
	RenderWindow window(VideoMode(320, 480), "Tetris");
	Figure fig("images/tiles.png");
	Field ch;

	while (window.isOpen())
	{
		fig.Timer();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			window.close();
			fig.key(event);
		}

		fig.Move(ch);
		fig.Rotate(ch);
		fig.Tick(ch);
		fig.dx = 0;
		fig.rotate = 0;
		ch.check_lines();
		window.clear(Color::White);
		
		for (int i = 0; i < ch.M; i++)
			for (int j = 0; j < ch.N; j++)
			{
				
				if (ch.field[i][j] == 0) continue;
				fig.s.setPosition(j * 18, i * 18);
				window.draw(fig.s);
			}

		for (int i = 0; i < 4; i++)
		{
			fig.paint(i);
			window.draw(fig.s);
		}
		window.display();
	}
	return 0;
}
