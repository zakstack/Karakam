#include "PlayerBrain.h"

PlayerBrain::PlayerBrain(sf::RenderWindow* targetWindow) : Brain(targetWindow)
{

}


PlayerBrain::~PlayerBrain()
{
}

std::vector<std::string> PlayerBrain::think()
{
	//Player Control Goes Here
	sf::Event event;
	std::string commandString;
	std::vector<std::string> command;
	size_t pos = 0;
	_renderWindow->pollEvent(event);
	int eventType = event.type;

	//W Pressed : Move Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		commandString = "moveEntity," + std::to_string(*this->_status->at(0)) + "," + std::to_string(*this->_status->at(1) - 1) + "," + std::to_string(*this->_status->at(2)) + ",";
		while ((pos = commandString.find(",")) != std::string::npos)
		{
			command.push_back(commandString.substr(0, pos));
			commandString.erase(0, pos + 1);
		}
		return command;
	}
	//A Pressed: Move Left
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		commandString = "moveEntity," + std::to_string(*this->_status->at(0) - 1) + "," + std::to_string(*this->_status->at(1)) + "," + std::to_string(*this->_status->at(2)) + ",";
		while ((pos = commandString.find(",")) != std::string::npos)
		{
			command.push_back(commandString.substr(0, pos));
			commandString.erase(0, pos + 1);
		}
		return command;
	}
	//S Pressed: Move Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		commandString = "moveEntity," + std::to_string(*this->_status->at(0)) + "," + std::to_string(*this->_status->at(1) + 1) + "," + std::to_string(*this->_status->at(2)) + ",";
		while ((pos = commandString.find(",")) != std::string::npos)
		{
			command.push_back(commandString.substr(0, pos));
			commandString.erase(0, pos + 1);
		}
		return command;
	}
	//D Pressed: Move Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		commandString = "moveEntity," + std::to_string(*this->_status->at(0) + 1) + "," + std::to_string(*this->_status->at(1)) + "," + std::to_string(*this->_status->at(2)) + ",";
		while ((pos = commandString.find(",")) != std::string::npos)
		{
			command.push_back(commandString.substr(0, pos));
			commandString.erase(0, pos + 1);
		}
		return command;
	}
	//E Pressed **TESTING COMMAND** : Open Inventory
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		command.push_back("openInventory");
		return command;
	}
	//R Pressed : Dig
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		command.push_back("dig");
		return command;
	}
	//F Pressed : Dig Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		command.push_back("digDown");
		return command;
	}
	else
	{
		commandString = "FAIL,:Keycode #" + std::to_string(event.key.code) + " is not a valid actions.,";
		command.push_back("");
		return command;
	}
}