#include "MainGame.h"

MainGame::MainGame(sf::RenderWindow* targetWindow)
{
	_renderWindow = targetWindow;

	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
		}

		_renderWindow->clear();
		_renderWindow->display();
	}
}

MainGame::~MainGame()
{
}
