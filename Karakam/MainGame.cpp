#include "MainGame.h"
//NOTE THIS IS JUST A TEST BUILD THIS WILL NEED TO BE HEAVILY EDITED FOR WORK FLOW
MainGame::MainGame(sf::RenderWindow* targetWindow)
{
	_renderWindow = targetWindow;
	//Create the Map
	_testMap = new Map(_renderWindow);
	_testMap->loadMap("Bin/Maps/TestMap/Master.txt");

	//Create the Character Controller
	ActorController playerCont(_testMap,_testMap->getActor(1,1),_renderWindow);

	//Attach the Character Controller to the Player Actor

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
				_cursor.setPosition(event.mouseMove.x, event.mouseMove.y);
			playerCont.tick();
		}

		_renderWindow->clear();
		//Draw the Map
		_testMap->drawMap();
		//Draw the Cursor
		_renderWindow->draw(_cursor);
		_renderWindow->display();
	}
}

MainGame::~MainGame()
{
}