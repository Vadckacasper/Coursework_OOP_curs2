#include <SFML/Graphics.hpp>
#include <string.h>
#include <time.h>
#include "Figure.h"

using namespace sf;


int main()
{
	RenderWindow window(VideoMode(320, 480), "Tetris");
	Figure fig("images/tiles.png");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		
		fig.Coordinate();
		window.clear(Color::White);
		for (int i = 0; i < 4; i++)
		{
			fig.paint(i);
			window.draw(fig.s);
		}
		
		window.display();
	}
	return 0;
}
