#include "Entity.h"

Entity::Entity(Entity**** gameMap,sf::RenderWindow* renderWindow,int entityID, int xFacing, int yFacing, int xPosition, int yPosition)
{
	_entityID = entityID;
	//Entity type Defines what layer of the game map the tile is on
	/*
		The Layers are as follows:
		0 : Tile Layer
		1 : Item Layer
		2 : Actor Layer
		3 : SFX Layer -> Not Yet implemented
	*/
	_entityTypeID = 0;
	_xFacing = xFacing;
	_yFacing = yFacing;
	_location.first = xPosition;
	_location.second = yPosition;
	_gameMap = gameMap;
	_renderWindow = renderWindow;
	_exists = 0;
}
Entity::Entity()
{
	_entityTypeID = 0;
	_xFacing = 0;
	_yFacing = 0;
	_location.first = 0;
	_location.second = 0;
	_gameMap = 0;
	_renderWindow = nullptr;
	_exists = 0;
}

Entity::~Entity()
{
}

std::vector<std::string> Entity::receiveCommand(std::vector<std::string> command)
{
	std::vector<std::string> returnVector;
	if (command.size() != 0 && command.at(0) != "FAIL")
	{
		if (command.at(0) == "getFacing")
		{
			returnVector.push_back(std::to_string(getXFacing()));
			returnVector.push_back(std::to_string(getYFacing()));
		}
		else if (command.at(0) == "moveEntity")
		{
			//Check that there is a proper coordinate provided
			if (command.size() == 3)
			{
				returnVector.push_back(moveEntity(std::stoi(command.at(1)), std::stoi(command.at(2))));
			}
			else
			{
				//ERROR
				//Don't move the Actor
				returnVector.push_back("FAIL: Too Few Arguments Given\n");
			}
		}
		else if (command.at(0) == "getEntityID")
		{
			returnVector.push_back(std::to_string(getEntityID()));
		}
		else if (command.at(0) == "getEntityTypeID")
		{
			returnVector.push_back(std::to_string(getEntityTypeID()));
		}
		else if (command.at(0) == "getLocation")
		{
			returnVector.push_back(std::to_string(getLocation().first));
			returnVector.push_back(std::to_string(getLocation().second));
			std::cout << "Current Location:\n";
		}
		else
		{
			returnVector.push_back("FAIL");
			returnVector.push_back(": Unable to determine command type\n");
		}
		for (int i = 0; i < returnVector.size(); i++)
		{
			std::cout << "Value " + std::to_string(i) + " : " + returnVector.at(i) + "\n";
		}
		std::cout << "\n";
	}
	else
	{
		returnVector.push_back("INVALID COMMAND FORMAT\n");
	}
	return returnVector;
}


//Utilities
std::vector<std::string> Entity::stringToVector(std::string targetString, std::string token)
{
	std::vector<std::string> result;
	size_t pos = 0;
	while ((pos = targetString.find(token)) != std::string::npos)
	{
		result.push_back(targetString.substr(0, pos));
		targetString.erase(0, pos + 1);
	}
	return result;
}
int Entity::getExists()
{
	return _exists;
}

//Receivable Commands
int Entity::getEntityID()
{
	return _entityID;
}
int Entity::getEntityTypeID()
{
	return _entityTypeID;
}
int Entity::getXFacing()
{
	return _xFacing;
}
int Entity::getYFacing()
{
	return _yFacing;
}
std::pair<int, int> Entity::getLocation()
{
	return _location;
}

std::string Entity::moveEntity(int xPos, int yPos)
{
	//IDEA: Can turn this in to a check against the other entity if they can be moved (may want to change this later)
	if (xPos >= 0 && yPos >= 0 && _gameMap[xPos][yPos][_entityTypeID] != nullptr && _gameMap[xPos][yPos][_entityTypeID]->getExists() == 0)
	{
		std::vector<std::string> command;
		command.push_back("getPassability");
		bool passable;
		std::string response = _gameMap[xPos][yPos][0]->receiveCommand(command).at(0);
		if (response != "FAIL" && std::stoi(response) == 0)
		{
			passable = true;
		}
		else
		{
			passable = false;
		}
		if (passable == true)
		{
			//Set the actors facing direction
			_yFacing = (_location.second - yPos);
			_xFacing = (_location.first - xPos);
			//Move the Actor on the map
			_gameMap[xPos][yPos][_entityTypeID] = _gameMap[getLocation().first][getLocation().second][_entityTypeID];
			_gameMap[getLocation().first][getLocation().second][_entityTypeID] = new Entity();
			//Set the actors position in its head
			_location.first = xPos;
			_location.second = yPos;
			//Return it was a success
			std::cout << getLocation().first + " " + getLocation().second;
			return "SUCCESS,";
		}
		else
		{
			return "FAIL,";
		}
	}
	else
	{
		return "FAIL,";
	}
}

//TESTING
void Entity::visualTest()
{
	//TESTING CODE GOES HERE
	_testLibrary.LoadLibrary("Textures/Test/Load.txt");
	_entityGraphic.setTexture(_testLibrary.getTexture(0));
	_entityGraphic.setPosition(sf::Vector2f(_location.first, _location.second));

	sf::RenderWindow* _renderWindow;
	_renderWindow = new sf::RenderWindow();
	_renderWindow->create(sf::VideoMode(800, 800), "Karakam");
	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_renderWindow->close();
			}
			std::string command;
			std::cin >> command;
			receiveCommand(stringToVector(command, ","));
		}
		_renderWindow->clear();
		//_renderWindow->draw(this->_entityGraphic);
		_renderWindow->display();
	}
}
