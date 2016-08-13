#include "Actor_Ent.h"

Actor_Ent::Actor_Ent(std::vector<std::vector<std::vector<Entity*>>>* gameMap, sf::RenderWindow* targetWindow, Brain* actorBrain) : Entity (gameMap, targetWindow)
{
	_entityTypeID = 2;
	if (actorBrain != nullptr)
	{
		_exists = 1;
		_brain = actorBrain;
	}
	else
	{
		_exists = 0;
	}
	_status.push_back(&_location.first);
	_status.push_back(&_location.second);
	_status.push_back(&_xFacing);
	_status.push_back(&_yFacing);
	//Plug the brain in to the body
	if (actorBrain != nullptr)
	{
		_brain->setStatus(&_status);
	}
}

Actor_Ent::~Actor_Ent()
{
}

//The Command System : Issuing Commands
std::vector<std::string> Actor_Ent::getCommand()
{
	//This is where the actors brain would go
	//Right now all actors get information from the command line unless otherwise specified
	if (_brain != nullptr)
	{
		return _brain->think();
	}
	else
	{
		std::vector<std::string> command;
		command.push_back("FAIL");
		command.push_back(":ACTOR IS DEAD");
		return command;
	}
}

//The Command System : Receiving Commands :: Overwritten from Entity
std::vector<std::string> Actor_Ent::receiveCommand(std::vector<std::string> command)
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
		else if (command.at(0) == "die")
		{
			die();
			returnVector.push_back("KILLED");
		}
		else if (command.at(0) == "kill")
		{
			if (command.size() == 3)
			{
				kill(std::stoi(command.at(1)),std::stoi(command.at(2)));
				returnVector.push_back("Attacked!");
			}
			else
			{
				//ERROR
				//Can't Kill the Actor
				returnVector.push_back("FAIL: Can't Kill this Actor\n");
			}
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

void Actor_Ent::die()
{
	_brain = nullptr;
	_exists = 0;
}

void Actor_Ent::kill(int xMod, int yMod)
{
	int xPos = _location.first - xMod;
	int yPos = _location.second - yMod;
	int xMax = _gameMap->at(0).at(0).size();
	int yMax = _gameMap->at(0).size();

	if (xPos >= 0 && xPos < xMax && yPos >= 0 && yPos < yMax && _gameMap->at(_entityTypeID).at(xPos).at(yPos)->getExists() == 1)
	{
		std::vector<std::string> command;
		command.push_back("die");
		_gameMap->at(_entityTypeID).at(_location.first - xMod).at(_location.second - yMod)->receiveCommand(command);
	}
}