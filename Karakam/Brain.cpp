#include "Brain.h"

Brain::Brain(sf::RenderWindow* targetWindow)
{
	_renderWindow = targetWindow;
}


Brain::~Brain()
{
}

void Brain::setStatus(std::vector<int*>* targetStatus)
{
	_status = targetStatus;
}