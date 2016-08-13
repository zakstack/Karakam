#include "VegitableBrain.h"

VegitableBrain::VegitableBrain(sf::RenderWindow* targetWindow):Brain(targetWindow)
{
}


VegitableBrain::~VegitableBrain()
{
}

std::vector<std::string> VegitableBrain::think()
{
	std::vector<std::string> command;
	command.push_back("wait,");
	return command;
}