#include "ActorController.h"

ActorController::ActorController(Map* targetMap, Actor* targetActor, sf::RenderWindow* targetWindow)
{
	_targetMap = targetMap;
	_targetActor = targetActor;
	_renderWindow = targetWindow;
}


ActorController::~ActorController()
{
}

//Getters
Actor* ActorController::getActor()
{
	return _targetActor;
}

void ActorController::tick()
{
	//Check for keyboard action
	sf::Event event;
	while (_renderWindow->pollEvent(event))
	{
		if (sf::Event::KeyReleased)
		{
			//W Pressed
			if (event.key.code == 119)
			{
				//Check if the space up from the actor is free
				if (_targetMap->getTile(_targetActor->getXPos(), _targetActor->getYPos() - 1)->passability == 0)
				{
					//Move the actor up relative to the Map
					_targetMap->moveActor(_targetActor, 0, -1);
				}
			}
			//A Pressed
			if (event.key.code == 97)
			{
				//Check if the space up from the actor is free
				if (_targetMap->getTile(_targetActor->getXPos() - 1, _targetActor->getYPos())->passability == 0)
				{
					//Move the actor up relative to the Map
					_targetMap->moveActor(_targetActor, -1, 0);
				}
			}
			//S Pressed
			if (event.key.code == 115)
			{
				//Check if the space up from the actor is free
				if (_targetMap->getTile(_targetActor->getXPos(), _targetActor->getYPos() + 1)->passability == 0)
				{
					//Move the actor up relative to the Map
					_targetMap->moveActor(_targetActor, 0, 1);
				}
			}
			//D Pressed
			if (event.key.code == 100)
			{
				//Check if the space up from the actor is free
				if (_targetMap->getTile(_targetActor->getXPos() + 1, _targetActor->getYPos())->passability == 0)
				{
					//Move the actor up relative to the Map
					_targetMap->moveActor(_targetActor, 1, 0);
				}
			}
			
			//Used to test what key is being pressed
			//std::cout << std::to_string(event.key.code) + "was pressed";
		}
	}
}