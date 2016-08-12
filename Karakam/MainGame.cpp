#include "MainGame.h"


MainGame::MainGame(sf::RenderWindow* targetWindow, std::string mapMasterLoc)
{
	_renderWindow = targetWindow;

	//Load the Map
	_gameMap = new Map(_renderWindow);
	_gameMap->loadMap(mapMasterLoc);

	//Create the Character Controller
	ActorController playerCont(_gameMap,_gameMap->getPlayer(),_renderWindow);

	//Create the Player Panel
	PlayerPanel playerPanel(_renderWindow, _gameMap->getPlayer());

	//Create the Cursor
	_cursorTexture.loadFromFile("Textures/MainGame/Cursor.png");
	_cursor.setTexture(_cursorTexture);

	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_gameMap->saveMap();
				_renderWindow->close();
			}
			if (event.type == sf::Event::MouseMoved)
			{
				_cursor.setPosition(playerCont.getActor()->getXPos() * 50 - 400 + event.mouseMove.x, playerCont.getActor()->getYPos() * 50 - 400 + event.mouseMove.y);
			}
			playerCont.tick();
		}

		//Center the mainView on the Player
		sf::View mainView(sf::FloatRect(playerCont.getActor()->getXPos() * 50 - 400, playerCont.getActor()->getYPos() * 50 - 350, 800, 800));
		//Minimap
		sf::View miniView(sf::FloatRect(playerCont.getActor()->getXPos() * 50 - 400, playerCont.getActor()->getYPos() * 50 - 350, 800, 800));
		miniView.zoom(10);

		_renderWindow->clear();
		//Center the View on the Player
		_renderWindow->setView(mainView);
		//_renderWindow->setView(miniView);

		//Draw the Map
		_gameMap->drawMap(playerCont.getActor()->getXPos(),playerCont.getActor()->getYPos(),5);
		//Draw the Player Panel
		playerPanel.drawPanel();
		//Draw the Cursor
		_renderWindow->draw(_cursor);
		//Draw the MiniMap
		
		_renderWindow->display();
	}
}

MainGame::~MainGame()
{
}