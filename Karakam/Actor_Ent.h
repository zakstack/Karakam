#ifndef __ACTOR_ENT_H__
#define __ACTOR_ENT_H__

#include "Entity.h"
#include "Brain.h"

class Actor_Ent :
	public Entity
{
private:
	Brain* _brain;
	std::vector<int*> _status;
public:
	Actor_Ent(std::vector<std::vector<std::vector<Entity>>>* gameMap,sf::RenderWindow* targetWindow, Brain* actorBrain);
	~Actor_Ent();

	//The Command System : Issuing Commands
	virtual std::vector<std::string> getCommand();
};

#endif 