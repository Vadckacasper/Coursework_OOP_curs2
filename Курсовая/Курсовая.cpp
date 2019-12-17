#include <SFML/Graphics.hpp>
#include <string.h>
#include <time.h>
#include "Figure.h"

using namespace sf;


int main()
{
	RenderWindow window(VideoMode(320, 480), "Tetris");
	Figure fig;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		fig.sprint();
		window.clear(Color::White);
		window.draw(fig.s);
		window.display();
	}
	return 0;
}
