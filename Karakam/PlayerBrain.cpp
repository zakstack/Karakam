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
		if (sf::Event::KeyReleased)
		{
			//W Pressed
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
			//A Pressed
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
			//S Pressed
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
			//D Pressed
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
			//E Pressed
			if (event.key.code == 4)
			{
				std::vector<std::string> command;
				command.push_back("getEntityTypeID_f");
				return command;
			}
			//R Pressed
			if (event.key.code == 17)
			{
				std::vector<std::string> command;
				command.push_back("dig");
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