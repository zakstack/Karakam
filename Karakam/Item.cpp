#include "Item.h"

Item::Item(Entity**** gameMap, sf::RenderWindow* renderWindow, int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int zPosition, std::vector<std::vector<std::string>> useArray) : Entity(gameMap, renderWindow, entityID, xFacing, yFacing, xPosition, yPosition, zPosition)
{
	_entityTypeID = 2;
	_useArray = useArray;
}


Item::~Item()
{
}

std::vector<std::string> Item::receiveCommand(std::vector<std::string> command)
{
	std::vector<std::string> returnVector;
	if (command.size() != 0 && command.at(0) != "FAIL")
	{
		if (command.at(0) == "moveEntity")
		{
			//Check that there is a proper coordinate provided
			if (command.size() == 3)
			{
				returnVector.push_back(moveEntity(std::stoi(command.at(1)), std::stoi(command.at(2)), std::stoi(command.at(3))));
			}
			else
			{
				//ERROR
				//Don't move the Item
				returnVector.push_back("FAIL: Too Few Arguments Given\n");
			}
		}
		else if (command.at(0) == "use")
		{
			//Check that the cororidnates for the user are provided
			if (command.size() == 4)
			{
				use(std::stoi(command.at(1)), std::stoi(command.at(2)), std::stoi(command.at(3)));
				returnVector.push_back("Used");
			}
		}
		else
		{
			returnVector = Entity::receiveCommand(command);
		}
	}
	else
	{
		returnVector.push_back("INVALID COMMAND FORMAT\n");
	}
	return returnVector;
}

void Item::use(int x, int y, int z)
{
	Entity* targetEntity = _gameMap[x][y][z];
	//Cycle Through all of the commands listed in the array and send them to the user
	for (int i = 0; i < _useArray.size(); i++)
	{
		targetEntity->receiveCommand(_useArray.at(i));
	}
}