#ifndef __ACTOR_CONTROLLER_H__
#define __ACTOR_CONTROLLER_H__

#include "Actor.h";
#include "Map.h"

class ActorController
{
private:
	Map* _targetMap;
	Actor* _targetActor;
	sf::RenderWindow* _renderWindow;

public:
	ActorController(Map* targetMap, Actor* targetActor, sf::RenderWindow* targetWindow);
	~ActorController();

	//Utilities
	void moveActor(int x, int y);

	void tick();
};

#endif