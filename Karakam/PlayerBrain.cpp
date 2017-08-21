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
	//Check for action until the player makes an action
	while (_renderWindow->pollEvent(event) || 1 == 1)
	{
		if (sf::Event::KeyPressed)
		{
			//W Pressed : Move Up
			if (event.key.code == 119)
			{
				commandString = "moveEntity," + std::to_string(*this->_status->at(0)) + "," + std::to_string(*this->_status->at(1) - 1) + "," + std::to_string(*this->_status->at(2)) + ",";
				std::vector<std::string> command;
				size_t pos = 0;
				while ((pos = commandString.find(",")) != std::string::npos)
				{
					command.push_back(commandString.substr(0, pos));
					commandString.erase(0, pos + 1);
				}
				return command;
			}
			//A Pressed: Move Left
			if (event.key.code == 97)
			{
				commandString = "moveEntity," + std::to_string(*this->_status->at(0) - 1) + "," + std::to_string(*this->_status->at(1)) + "," + std::to_string(*this->_status->at(2)) + ",";
				std::vector<std::string> command;
				size_t pos = 0;
				while ((pos = commandString.find(",")) != std::string::npos)
				{
					command.push_back(commandString.substr(0, pos));
					commandString.erase(0, pos + 1);
				}
				return command;
			}
			//S Pressed: Move Down
			if (event.key.code == 115)
			{
				commandString = "moveEntity," + std::to_string(*this->_status->at(0)) + "," + std::to_string(*this->_status->at(1) + 1) + "," + std::to_string(*this->_status->at(2)) + ",";
				std::vector<std::string> command;
				size_t pos = 0;
				while ((pos = commandString.find(",")) != std::string::npos)
				{
					command.push_back(commandString.substr(0, pos));
					commandString.erase(0, pos + 1);
				}
				return command;
			}
			//D Pressed: Move Right
			if (event.key.code == 100)
			{
				commandString = "moveEntity," + std::to_string(*this->_status->at(0) + 1) + "," + std::to_string(*this->_status->at(1)) + "," + std::to_string(*this->_status->at(2)) + ",";
				std::vector<std::string> command;
				size_t pos = 0;
				while ((pos = commandString.find(",")) != std::string::npos)
				{
					command.push_back(commandString.substr(0, pos));
					commandString.erase(0, pos + 1);
				}
				return command;
			}
			//E Pressed **TESTING COMMAND** : Open Inventory
			if (event.key.code == 4)
			{
				std::vector<std::string> command;
				command.push_back("openInventory");
				return command;
			}
			//R Pressed : Dig
			if (event.key.code == 17)
			{
				std::vector<std::string> command;
				command.push_back("dig");
				return command;
			}
			//F Pressed : Dig Down
			if (event.key.code == 5)
			{
				std::vector<std::string> command;
				command.push_back("digDown");
				return command;
			}
			else
			{
				commandString = "FAIL,:Keycode was not found.,";
			}
			//Used to test what key is being pressed
			//
		}
	}
}