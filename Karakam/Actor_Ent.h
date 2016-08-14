#ifndef __ACTOR_ENT_H__
#define __ACTOR_ENT_H__

#include "Entity.h"
#include "Brain.h"
#include "VegitableBrain.h"
#include "PlayerBrain.h"

class Actor_Ent :
	public Entity
{
private:
	Brain* _brain;
	std::vector<int*> _status;
public:
	Actor_Ent(Entity**** gameMap, sf::RenderWindow* renderWindow, int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int zPosition, int brainID);
	~Actor_Ent();

	//The Command System : Issuing Commands
	virtual std::vector<std::string> getCommand();

	//The Command System : Receiving Commands :: Overwritten from Entity
	std::vector<std::string> receiveCommand(std::vector<std::string> command);

	virtual void die();
	virtual void kill(int xMod, int yMod);
	void loadBrain();
};

#endif 