#include "Map.h"

Map::Map(std::string masterLoc,sf::RenderWindow* renderWindow)
{
	_renderWindow = renderWindow;

	//Load the Master Location File in to the DirectoryList
	MetaGet getter;
	_directorList = getter.getArray(masterLoc);

	_tileGraphicLibrary.LoadLibrary(_directorList.at(3).at(0));
	_actorGraphicLibrary.LoadLibrary(_directorList.at(4).at(0));

	//Create the default map
	_gameMap = new Entity***[_X_SIZE];
	for (int x = 0; x < _X_SIZE; x++)
	{
		_gameMap[x] = new Entity**[_Y_SIZE];
		for (int y = 0; y < _Y_SIZE; y++)
		{
			_gameMap[x][y] = new Entity*[_Z_SIZE];
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
		newHash.second = new Tile(_gameMap,_renderWindow, std::stoi(tileStats.at(0).at(0)), std::stoi(tileStats.at(0).at(1)), std::stoi(tileStats.at(0).at(2)), std::stoi(tileStats.at(0).at(3)), std::stoi(tileStats.at(0).at(4)), std::stoi(tileStats.at(0).at(5)), std::stoi(tileStats.at(0).at(6)), std::stoi(tileStats.at(0).at(7)));
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
		newHash.second = new Actor_Ent(_gameMap,_renderWindow, std::stoi(actorStats.at(0).at(0)), std::stoi(actorStats.at(0).at(1)), std::stoi(actorStats.at(0).at(2)), std::stoi(actorStats.at(0).at(3)), std::stoi(actorStats.at(0).at(4)), std::stoi(actorStats.at(0).at(5)), std::stoi(actorStats.at(0).at(6)));
		_actorLibrary.insert(newHash);
	}

	//Make a clean cube
	for (int z = 0; z < 2; z++)
	{
		for (int y = 0; y < 100; y++)
		{
			for (int x = 0; x < 100; x++)
			{
				_gameMap[x][y][z] = nullptr;
			}
		}
	}

	
	VeroniMapGen newGen(_X_SIZE, _Y_SIZE, _Z_SIZE, 200, 5);
	//Generate the maps Veroni Cube
	//std::vector<std::vector<std::vector<int>>> targetMap = newGen.generateWorkingMap(1);
	//newGen.writeCubeToFile("Bin/Maps/SaveSlot1/Maps/Test", 5);
	//Load the maps Veroni Cube
	std::vector<std::vector<std::vector<int>>> targetMap = newGen.loadCubeFromFile("Bin/Maps/SaveSlot1/Maps/Test",5);

	//Load the Tile Map
	for (int z = 0; z < _Z_SIZE; z++)
	{
		for (int y = 0; y < _Y_SIZE; y++)
		{
			for (int x = 0; x < _X_SIZE; x++)
			{
				//If it is not a 0 in the map set it to the designated tile
				if (targetMap.at(z).at(x).at(y) != 0)
				{
					_gameMap[x][y][z] = new Tile(*_tileLibrary.at(targetMap.at(z).at(x).at(y)));
					_gameMap[x][y][z]->_location.first = x;
					_gameMap[x][y][z]->_location.second = y;
					_gameMap[x][y][z]->_zPosition = z;
				}
				else
				{
					_gameMap[x][y][z] = nullptr;
				}
			}
		}
	}

	//Load the Player Actor
	std::vector<std::vector<std::string>> actorLayout = getter.getArray("Bin/Maps/SaveSlot1/Maps/ActorMap.txt");
	_gameMap[1][1][1] = _actorLibrary.at(std::stoi(actorLayout.at(1).at(1)));
	_activeActors.push_back(_gameMap[1][1][1]);
	_activeActors.back()->_zPosition = 1;

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
		//Center the mainView on the Player
		sf::View mainView(sf::FloatRect(_activeActors.at(0)->getLocation().first * 50 - 400, _activeActors.at(0)->getLocation().second * 50 - 350, 800, 800));
		_renderWindow->setView(mainView);
	
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
	

		sf::Sprite drawSprite;
		for (int y = yMin; y < _activeActors.at(0)->getLocation().second + 6; y++)
		{
			for (int x = xMin; x < _activeActors.at(0)->getLocation().first + 6; x++)
			{
				for (int z = 0; z < _Z_SIZE; z++)
				{
					if (x >= 0 && x < _X_SIZE && y >= 0 & y < _Y_SIZE && z >= 0 && z < _Z_SIZE && _gameMap[x][y][z] != nullptr)
					{
						switch (_gameMap[x][y][z]->getEntityTypeID())
						{
							//Tiles
							case 0:
								drawSprite.setTexture(_tileGraphicLibrary.getTexture(_gameMap[x][y][z]->getEntityID()));
								break;
							//Actor
							case 1:
								drawSprite.setTexture(_actorGraphicLibrary.getTexture(_gameMap[x][y][z]->getEntityID()));
								break;
							//Other
							case 2:
								break;
							default:
								break;
						}

						drawSprite.setPosition(x * 50, y * 50);
						//Determine where the sprite is in accordance to where the player is and draw accordingly
						if (z > _activeActors.at(0)->_zPosition)
						{
							//Draw a black square
							//drawSprite.setColor(sf::Color(1, 1, 1, 255));
							//_renderWindow->draw(drawSprite);
						}
						else if (z < _activeActors.at(0)->_zPosition - 1)
						{
							drawSprite.setColor(sf::Color(122/(_activeActors.at(0)->_zPosition - z), 122/(_activeActors.at(0)->_zPosition - z), 122/(_activeActors.at(0)->_zPosition - z), 255));
							_renderWindow->draw(drawSprite);
						}
						else if (z == _activeActors.at(0)->_zPosition - 1)
						{
							drawSprite.setColor(sf::Color(255, 255, 255, 255));
							_renderWindow->draw(drawSprite);
						}
						else
						{
							drawSprite.setColor(sf::Color(255, 1, 1, 255));
							//Draw what the sprite looks like
							_renderWindow->draw(drawSprite);
						}
					}
				}
			}
		}
		_renderWindow->display();
	}
}

void Map::dumpToFile(std::string fileLoc, int zLevel)
{
	std::ofstream myfile(fileLoc);
	if (myfile.is_open())
	{
		for (int y = 0; y < _Y_SIZE; y++)
		{
			for (int x = 0; x < _X_SIZE; x++)
			{
				if (_gameMap[x][y][zLevel] != nullptr)
				{
					myfile << std::to_string(_gameMap[x][y][zLevel]->getEntityID());
					myfile << ",";
				}
				else
				{
					myfile << "-";
					myfile << ",";
				}
			}
			myfile << "\n";
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}