#include "Actor_Ent.h"

Actor_Ent::Actor_Ent(Entity**** gameMap, sf::RenderWindow* renderWindow, int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int zPosition, int brainID) : Entity (gameMap, renderWindow,entityID,xFacing,yFacing,xPosition,yPosition,zPosition)
{
	_entityTypeID = 1;
	_entityID = entityID;
	_location.first = xPosition;
	_location.second = yPosition;
	//Decide what kind of brain the actor has
	switch (brainID)
	{
		//No Brain
		case 0:
			_brain = nullptr;
			break;
		//Player Brain
		case 1:
			_brain = new PlayerBrain(_renderWindow);
			break;
		//Vegitable Brain
		case 2:
			_brain = new VegitableBrain(_renderWindow);
		default:
			break;
	}
	if (_brain != nullptr)
	{
		_exists = 1;
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
	if (_brain != nullptr)
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
		else if (command.at(0) == "tick")
		{
			receiveCommand(getCommand());
		}
		else if (command.at(0) == "moveEntity")
		{
			//Check that there is a proper coordinate provided
			if (command.size() == 3)
			{
				moveEntity(std::stoi(command.at(1)), std::stoi(command.at(2)));
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
		else if (command.at(0) == "getEntityTypeID_f")
		{
			if (_location.first - _xFacing >= 0 && _location.second + _yFacing >0 && _gameMap[_location.first - _xFacing][_location.second + _yFacing][_zPosition] != nullptr)
			{
				std::cout << std::to_string(_gameMap[_location.first - _xFacing][_location.second + _yFacing][_zPosition]->getEntityID());
			}
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
		else if (command.at(0) == "dig")
		{
			if (_location.first - _xFacing >= 0 && _location.second - _yFacing >0 && _gameMap[_location.first - _xFacing][_location.second - _yFacing][_zPosition] != nullptr)
			{
				if (_gameMap[_location.first - _xFacing][_location.second - _yFacing][_zPosition]->getEntityID() == 2)
				{
					_gameMap[_location.first - _xFacing][_location.second - _yFacing][_zPosition]->receiveCommand(command);
				}
			}
		}
		else if (command.at(0) == "wait")
		{
			returnVector.push_back("Waited!");
		}
		else if (command.at(0) == "setBrain")
		{

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

	if (_gameMap[xPos][yPos][_entityTypeID]->getExists() == 1)
	{
		std::vector<std::string> command;
		command.push_back("die");
		_gameMap[_location.first - xMod][_location.second - yMod][_entityTypeID]->receiveCommand(command);
	}
}