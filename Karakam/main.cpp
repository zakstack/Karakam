#include <string>
#include "TitleScreen.h"
#include "MapGen.h"
#include "Entity.h"
#include "Actor_Ent.h"
#include "PlayerBrain.h"

int main()
{
	//Testing new Entity Command Control Scheme
	sf::RenderWindow* mainWindow = new sf::RenderWindow;
	mainWindow->create(sf::VideoMode(800, 800), "Karakam");
	Actor_Ent* _targetPlayer;
	PlayerBrain _targetPlayerBrain(mainWindow);
	std::vector<std::vector<std::vector<Entity>>>* gameMap;
	gameMap = new std::vector<std::vector<std::vector<Entity>>>;
	_targetPlayer = new Actor_Ent(gameMap, mainWindow,&_targetPlayerBrain);
	std::vector<std::vector<Entity>> xySpace;
	for (int y = 0; y < 10; y++)
	{
		std::vector<Entity> xSpace;
		for (int x = 0; x < 10; x++)
		{
			Entity newEntity(gameMap,mainWindow);
			if (x == 1 && y == 1)
			{
				newEntity = *_targetPlayer;
			}
			xSpace.push_back(newEntity);
		}
		xySpace.push_back(xSpace);
	}
	std::vector<std::vector<Entity>> padding;
	//Padding is for the tile and item layers respectivly
	gameMap->push_back(padding);
	gameMap->push_back(padding);
	gameMap->push_back(xySpace);
	while (mainWindow->isOpen())
	{
		sf::Event event;
		while (mainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mainWindow->close();
			}
			_targetPlayer->receiveCommand(_targetPlayer->getCommand());
		}
		mainWindow->clear();
		//_renderWindow->draw(this->_entityGraphic);
		mainWindow->display();
	}
	


	//_targetPlayer->receiveCommand(_targetPlayer->getCommand());
	//_targetPlayer->visualTest();







	//MAIN GAME RUNNING HERE
	////Load the Title Screen
	//sf::RenderWindow* mainWindow = new sf::RenderWindow;
	//mainWindow->create(sf::VideoMode(800, 800), "Karakam");
	//while (mainWindow->isOpen())
	//{
	//	//START THE GAME
	//	TitleScreen Karakam(mainWindow, "Textures/Test/Test.txt");

	//}
	//MapSplitter newSplitter("Textures/Test/tileset.png");
	return 1;
}