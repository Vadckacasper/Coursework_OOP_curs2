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
	ch.Background("images/background.png");
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
		ch.Key_end(fig);
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();
				

		fig.Move(ch);
		fig.Rotate(ch);
		fig.Tick(ch);
		fig.dx = 0;
		fig.rotate = 0;
		fig.delay = 0.3;
		ch.check_lines();
		window.clear(Color::White);
		window.draw(ch.background);
		
		for (int i = 0; i < ch.M; i++)
			for (int j = 0; j < ch.N; j++)
			{
				
				if (ch.field[i][j] == 0) continue;
				fig.s.setTextureRect(IntRect(ch.field[i][j] * 18, 0, 18, 18));
				fig.s.setPosition(j * 18, i * 18);
				fig.s.move(28, 31);
				window.draw(fig.s);
			}
		
		for (int i = 0; i < 4; i++)
		{
			fig.paint(i);
			fig.s.move(28, 31);
			window.draw(fig.s);
		}
		
		window.display();
	}

	return 0;

}
