#include "Map.h"

Map::Map(std::string masterLoc,sf::RenderWindow* renderWindow)
{
	_renderWindow = renderWindow;

	//Load the Master Location File in to the DirectoryList
	MetaGet getter;
	_directorList = getter.getArray(masterLoc);

	//Create the default map
	_gameMap = new Entity***[_X_SIZE];
	for (int x = 0; x < _X_SIZE; x++)
	{
		_gameMap[x] = new Entity**[_Y_SIZE];
		for (int y = 0; y < _Y_SIZE; y++)
		{
			_gameMap[x][y] = new Entity*[_NUM_OF_LAYERS];
			std::cout << std::to_string(x) + " " + std::to_string(y) + "\n";
		}
	}

	//Load in the Tile Library
	std::vector<std::vector<std::string>> tileHashList;
	tileHashList = getter.getArray(_directorList.at(0).at(0));
	for (int i = 0; i < tileHashList.size(); i++)
	{
		std::pair<int, Tile*> newHash;
		newHash.first = std::stoi(tileHashList.at(i).at(0));
		std::vector<std::vector<std::string>> tileStats;
		tileStats = getter.getArray(tileHashList.at(i).at(1));
		newHash.second = new Tile(_gameMap,_renderWindow, std::stoi(tileStats.at(0).at(0)), std::stoi(tileStats.at(0).at(1)), std::stoi(tileStats.at(0).at(2)), std::stoi(tileStats.at(0).at(3)), std::stoi(tileStats.at(0).at(4)), std::stoi(tileStats.at(0).at(5)), std::stoi(tileStats.at(0).at(6)));
		_tileLibrary.insert(newHash);
	}
	//Load in the Actor Library
	std::vector<std::vector<std::string>> actorHashList;
	actorHashList = getter.getArray(_directorList.at(1).at(0));
	for (int i = 0; i < actorHashList.size(); i++)
	{
		std::pair<int, Actor_Ent*> newHash;
		newHash.first = std::stoi(actorHashList.at(i).at(0));
		std::vector<std::vector<std::string>> actorStats;
		actorStats = getter.getArray(actorHashList.at(i).at(1));
		newHash.second = new Actor_Ent(_gameMap,_renderWindow, std::stoi(actorStats.at(0).at(0)), std::stoi(actorStats.at(0).at(1)), std::stoi(actorStats.at(0).at(2)), std::stoi(actorStats.at(0).at(3)), std::stoi(actorStats.at(0).at(4)), std::stoi(actorStats.at(0).at(5)));
		_actorLibrary.insert(newHash);
	}

	//Load the Tile Map
	std::vector<std::vector<std::string>> tileLayout = getter.getArray("Bin/Maps/SaveSlot1/Maps/Layout.txt");
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			_gameMap[x][y][0] = _tileLibrary.at(std::stoi(tileLayout.at(y).at(x)));
		}
	}
	//Load the Actor Map
	std::vector<std::vector<std::string>> actorLayout = getter.getArray("Bin/Maps/SaveSlot1/Maps/ActorMap.txt");
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			_gameMap[x][y][1] = _actorLibrary.at(std::stoi(actorLayout.at(y).at(x)));
			if (std::stoi(actorLayout.at(x).at(y)) != 0)
			{
				_activeActors.push_back(_gameMap[x][y][1]);
			}
		}
	}
	test();
}

Map::~Map()
{
}

void Map::tick()
{
	//Goes through the ActiveActors and applies their movement
	for (int i = 0; i < _activeActors.size(); i++)
	{
		std::vector<std::string> command;
		command.push_back("tick");
		_activeActors.at(i)->receiveCommand(command);
	}
}

void Map::test()
{
	std::cout << "cats";
	//These are test sprites until the new graphic system is installed
	sf::Sprite test1;
	sf::Sprite test2;
	sf::Sprite test3;
	sf::Sprite test4;
	sf::Texture test1t;
	test1t.loadFromFile("Textures/Maps/TestMap/0.png");
	sf::Texture test2t;
	test2t.loadFromFile("Textures/Maps/TestMap/1.png");
	sf::Texture test3t;
	test3t.loadFromFile("Textures/Maps/TestMap/2.png");
	sf::Texture test4t;
	test4t.loadFromFile("Textures/Maps/TestMap/3.png");
	test1.setTexture(test1t);
	test2.setTexture(test2t);
	test3.setTexture(test3t);
	test4.setTexture(test4t);

	//Begin the game loop
	// run the program as long as the window is open
	while (_renderWindow->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
			tick();
		}
		_renderWindow->clear(sf::Color::Black);
		int yMin;
		if (_activeActors.at(0)->getLocation().second - 5 >= 0)
		{
			yMin = _activeActors.at(0)->getLocation().second - 5;
		}
		else
		{
			yMin = 0;
		}
		int xMin;
		if (_activeActors.at(0)->getLocation().first - 5 >= 0)
		{
			xMin = _activeActors.at(0)->getLocation().first - 5;
		}
		else
		{
			xMin = 0;
		}
		// clear the window with black color
		for (int y = yMin; y < _activeActors.at(0)->getLocation().second + 6; y++)
		{
			for (int x = xMin; x < _activeActors.at(0)->getLocation().first + 6; x++)
			{
				switch (_gameMap[x][y][0]->getEntityID())
				{
				case 0:
					test1.setPosition(x * 50, y * 50);
					_renderWindow->draw(test1);
					break;
				case 1:
					test2.setPosition(x * 50, y * 50);
					_renderWindow->draw(test2);
					break;
				case 2:
					test3.setPosition(x * 50, y * 50);
					_renderWindow->draw(test3);
					break;
				default:
					break;
				}
				if (_gameMap[x][y][1] != nullptr && _gameMap[x][y][1]->getEntityID() == 1)
				{
					test4.setPosition(x * 50, y * 50);
					//Center the mainView on the Player
					sf::View mainView(sf::FloatRect(_gameMap[x][y][1]->getLocation().first * 50 - 400, _gameMap[x][y][1]->getLocation().second * 50 - 350, 800, 800));
					_renderWindow->setView(mainView);
					_renderWindow->draw(test4);
				}
			}
		}

		_renderWindow->display();
	}
}