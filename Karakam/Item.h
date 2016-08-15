#ifndef __ITEM_H__
#define __ITEM_H__

#include "Entity.h"
class Item :
	public Entity
{
private:
	std::vector<std::vector<std::string>> _useArray;

public:
	//Constructor & Destructor
	Item(Entity**** gameMap, sf::RenderWindow* targetWindow, int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int zPosition, std::vector<std::vector<std::string>> useArray);
	~Item();

	//The Command System : Receiving Commands
	virtual std::vector<std::string> receiveCommand(std::vector<std::string> command);

	//Receivable Commands
	virtual void use(int x, int y, int z);

};

#endif