#include <string>
#include "TitleScreen.h"
#include "MapGen.h"
#include "Entity.h"
#include "Actor_Ent.h"
#include "PlayerBrain.h"
#include "VegitableBrain.h"

int main()
{
	//Testing new Entity Command Control Scheme
	sf::RenderWindow* mainWindow = new sf::RenderWindow;
	mainWindow->create(sf::VideoMode(800, 800), "Karakam");
	PlayerBrain _targetPlayerBrain(mainWindow);
	std::vector<std::vector<std::vector<Entity*>>>* gameMap;
	gameMap = new std::vector<std::vector<std::vector<Entity*>>>;
	Actor_Ent* _targetPlayer = new Actor_Ent(gameMap, mainWindow,&_targetPlayerBrain);
	sf::Sprite testSprite;
	sf::Texture testTexture;
	testTexture.loadFromFile("Textures/Test/0.png");
	testSprite.setTexture(testTexture);
	std::vector<std::vector<Entity>> padding;

	//Build the tile space
	std::vector<std::vector<Entity*>> tileSpace;
	for (int y = 0; y < 10; y++)
	{
		std::vector<Entity*> xSpace;
		for (int x = 0; x < 10; x++)
		{
			Entity* newEntity = new Entity(gameMap, mainWindow);
			xSpace.push_back(newEntity);
		}
		tileSpace.push_back(xSpace);
	}
	gameMap->push_back(tileSpace);
	//Build the itemSpace
	std::vector<std::vector<Entity*>> itemSpace;
	for (int y = 0; y < 10; y++)
	{
		std::vector<Entity*> xSpace;
		for (int x = 0; x < 10; x++)
		{
			Entity* newEntity = new Entity(gameMap, mainWindow);
			xSpace.push_back(newEntity);
		}
		itemSpace.push_back(xSpace);
	}
	gameMap->push_back(itemSpace);
	//Build the actorSpace
	std::vector<std::vector<Entity*>> actorSpace;
	for (int y = 0; y < 10; y++)
	{
		std::vector<Entity*> xSpace;
		for (int x = 0; x < 10; x++)
		{
			Brain* targetBrain = nullptr;
			if (x == 4 && y == 4)
			{
				targetBrain = new VegitableBrain(mainWindow);
			}
			Actor_Ent* newEntity = new Actor_Ent(gameMap, mainWindow,targetBrain);
			xSpace.push_back(newEntity);
		}
		actorSpace.push_back(xSpace);
	}
	gameMap->push_back(actorSpace);

	while (mainWindow->isOpen())
	{
		sf::Event event;
		while (mainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mainWindow->close();
			}
			//Testing the SelfCommand Structure
			_targetPlayer->receiveCommand(_targetPlayer->getCommand());
			testSprite.setPosition(sf::Vector2f(_targetPlayer->getLocation().first * 50, _targetPlayer->getLocation().second * 50));
		}
		mainWindow->clear();
		mainWindow->draw(testSprite);
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