#include "Entity.h"

Entity::Entity(Entity**** gameMap,sf::RenderWindow* renderWindow,int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int zPosition)
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
	_zPosition = zPosition;
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
				returnVector.push_back(moveEntity(std::stoi(command.at(1)), std::stoi(command.at(2)), std::stoi(command.at(3))));
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
		else if (command.at(0) == "getLocation")
		{
			returnVector.push_back(std::to_string(getLocation().first));
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

std::string Entity::moveEntity(int xPos, int yPos, int zPos)
{
	_yFacing = (_location.second - yPos);
	_xFacing = (_location.first - xPos);
	//The space in front of the actor is free
	if (xPos >= 0 && yPos >= 0 && zPos >= 0 && _gameMap[xPos][yPos][zPos] == nullptr)
	{
		//The space below the desired move location is occupied
		if (zPos - 1 >= 0 && _gameMap[xPos][yPos][zPos - 1] != nullptr)
		{
			//Move the actor in to the space
			//Set the actors facing direction
			_yFacing = (_location.second - yPos);
			_xFacing = (_location.first - xPos);
			//Move the Actor on the map
			_gameMap[xPos][yPos][zPos] = _gameMap[getLocation().first][getLocation().second][_zPosition];
			_gameMap[getLocation().first][getLocation().second][_zPosition] = nullptr;
			//Set the actors position in its head
			_location.first = xPos;
			_location.second = yPos;
			_zPosition = zPos;
			//Return it was a success
			std::cout << std::to_string(getLocation().first) + " " + std::to_string(getLocation().second) + "\n";
			return "SUCCESS,";
		}
		//The space below the desired move location is not occupied
		else
		{
			//Fall to the next available space
			moveEntity(xPos, yPos, zPos - 1);
			return "FELL,";
		}
	}
	//There space in front of the actor is not free
	else
	{
		//There actor climbs up a space
		if (xPos >= 0 && yPos >= 0 && zPos >= 0 && _gameMap[xPos][yPos][zPos + 1] != nullptr && _gameMap[getLocation().first][getLocation().second][zPos + 1] == nullptr)
		{
			//Move the actor in to the space
			//Set the actors facing direction
			_yFacing = (_location.second - yPos);
			_xFacing = (_location.first - xPos);
			//Move the Actor on the map
			_gameMap[getLocation().first][getLocation().second][zPos + 1] = _gameMap[getLocation().first][getLocation().second][_zPosition];
			_gameMap[getLocation().first][getLocation().second][_zPosition] = nullptr;
			//Set the actors position in its head
			_location.first = getLocation().first;
			_location.second = getLocation().second;
			_zPosition = zPos + 1;
			//Return it was a success
			std::cout << std::to_string(getLocation().first) + " " + std::to_string(getLocation().second) + "\n";
			return "CLIMBED UP,";
		}
		else if (xPos >= 0 && yPos >= 0 && zPos >= 0 && _gameMap[getLocation().first][getLocation().second][zPos + 1] == nullptr)
		{
			//Move the actor in to the space
			//Set the actors facing direction
			_yFacing = (_location.second - yPos);
			_xFacing = (_location.first - xPos);
			//Move the Actor on the map
			_gameMap[xPos][yPos][zPos + 1] = _gameMap[getLocation().first][getLocation().second][_zPosition];
			_gameMap[getLocation().first][getLocation().second][_zPosition] = nullptr;
			//Set the actors position in its head
			_location.first = xPos;
			_location.second = yPos;
			_zPosition = zPos + 1;
			//Return it was a success
			std::cout << std::to_string(getLocation().first) + " " + std::to_string(getLocation().second) + "\n";
			return "CLIMBED,";
		}
		else
		{
			return "FAIL,";
		}
	}
}
