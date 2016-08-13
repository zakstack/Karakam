#include "Actor_Ent.h"

Actor_Ent::Actor_Ent(std::vector<std::vector<std::vector<Entity>>>* gameMap, sf::RenderWindow* targetWindow, Brain* actorBrain) : Entity (gameMap, targetWindow)
{
	_exists = 1;
	_entityTypeID = 2;
	_brain = actorBrain;
	_status.push_back(&_location.first);
	_status.push_back(&_location.second);
	//Plug the brain in to the body
	_brain->setStatus(&_status);
}

Actor_Ent::~Actor_Ent()
{
}

//The Command System : Issuing Commands
std::vector<std::string> Actor_Ent::getCommand()
{
	//This is where the actors brain would go
	//Right now all actors get information from the command line unless otherwise specified
	return _brain->think();
}