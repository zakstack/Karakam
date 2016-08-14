#include "Tile.h"

Tile::Tile(Entity**** mainMap, sf::RenderWindow* renderWindow,int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int passability, int hardness) : Entity(mainMap,renderWindow,entityID,xFacing,yFacing,xPosition,yPosition)
{
	_entityID = entityID;
	_passability = passability;
	_hardness = hardness;
	_exists = true;
}

Tile::~Tile()
{
}

std::vector<std::string> Tile::receiveCommand(std::vector<std::string> command)
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
		else if (command.at(0) == "getPassability")
		{
			returnVector.push_back(std::to_string(_passability));
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
		else if (command.at(0) == "wait")
		{
			returnVector.push_back("Waited!");
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