#include "Game.h"

Game::Game()
{
	//Create the game window
	mainWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "Karakram");
	//mainWindow->setKeyRepeatEnabled(false);

	//Load the Map
	gameMap = new Map("Bin/Maps/SaveSlot1/Master.txt",mainWindow);

	//Create the Graphic Engine
	GraphicsEngine graphics(mainWindow,gameMap,"Textures/Maps/TestMap/Load.txt","Textures/Actors/Load.txt", "Textures/Items/Load.txt");

	//Begin the game loop
	// run the program as long as the window is open
	while (mainWindow->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (mainWindow->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				mainWindow->close();
			gameMap->tick();
		}


		mainWindow->clear(sf::Color::Black);
		//Center the mainView on the Player
		sf::View mainView(sf::FloatRect(gameMap->getActiveActors()->at(0)->getLocation().first * 50 - 400, gameMap->getActiveActors()->at(0)->getLocation().second * 50 - 350, 800, 800));
		mainWindow->setView(mainView);

		int yMin;
		if (gameMap->getActiveActors()->at(0)->getLocation().second - 5 >= 0)
		{
			yMin = gameMap->getActiveActors()->at(0)->getLocation().second - 5;
		}
		else
		{
			yMin = 0;
		}
		int xMin;
		if (gameMap->getActiveActors()->at(0)->getLocation().first - 5 >= 0)
		{
			xMin = gameMap->getActiveActors()->at(0)->getLocation().first - 5;
		}
		else
		{
			xMin = 0;
		}
		//Defines the Players view range
		for (int y = yMin; y < gameMap->getActiveActors()->at(0)->getLocation().second + _X_VIEW; y++)
		{
			for (int x = xMin; x < gameMap->getActiveActors()->at(0)->getLocation().first + _Y_VIEW; x++)
			{
				for (int z = 0; z <= gameMap->getActiveActors()->at(0)->_zPosition; z++)
				{
					//REQUIREMENTS to be a valid draw point
					if (x >= 0 && x < gameMap->getMapSizeVector().x && y >= 0 & y < gameMap->getMapSizeVector().y && z >= 0 && z < gameMap->getMapSizeVector().z)
					{
						//This is where the meat happens you can decide how to draw here
						if (gameMap->getGameMap()[x][y][z] != nullptr)
						{
							graphics.drawTile(x, y, z);
						}
					}
				}
			}
		}
		//THIS IS TEST CODE
		//=======================================
		//Draw the players inventory
		if (((Actor_Ent *)gameMap->getActiveActors()->at(0))->_inventory->getOpen() == true)
		{
			//Draw the inventory window
			graphics.drawInventory(((Actor_Ent *)gameMap->getActiveActors()->at(0))->_inventory);
		}
		//=======================================
		mainWindow->display();
	}
}


Game::~Game()
{
}
