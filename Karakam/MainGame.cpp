#include "MainGame.h"


MainGame::MainGame(sf::RenderWindow* targetWindow, std::string mapMasterLoc)
{
	_renderWindow = targetWindow;

	//Load the Map
	_gameMap = new Map(_renderWindow);
	_gameMap->loadMap(mapMasterLoc);

	//Create the Character Controller
	ActorController playerCont(_gameMap,_gameMap->getActor(1,1),_renderWindow);

	//Create the Cursor
	_cursorTexture.loadFromFile("Textures/MainGame/Cursor.png");
	_cursor.setTexture(_cursorTexture);

	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
			if (event.type == sf::Event::MouseMoved)
				_cursor.setPosition(playerCont.getActor()->getXPos() * 50 - 400 + event.mouseMove.x, playerCont.getActor()->getYPos() * 50 - 400 + event.mouseMove.y);
			playerCont.tick();
		}

		//Center the View on the Player
		_renderWindow->setView(sf::View(sf::FloatRect(playerCont.getActor()->getXPos() * 50 - 400, playerCont.getActor()->getYPos() * 50 - 350, 800, 800)));

		_renderWindow->clear();
		//Draw the Map
		_gameMap->drawMap();
		//Draw the Cursor
		_renderWindow->draw(_cursor);
		_renderWindow->display();
	}
}

MainGame::~MainGame()
{
}