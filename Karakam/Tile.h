#ifndef __TILE_H__
#define __TILE_H__

#include "Entity.h"
class Tile :
	public Entity
{
private:
protected:
	int _passability;
	int _hardness;
public:
	Tile(Entity**** mainMap,sf::RenderWindow* renderWindow, int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int passability, int hardness);
	~Tile();

	//The Command System : Receiving Commands :: Overwritten from Entity. Copied from Actor_Ent currently
	std::vector<std::string> receiveCommand(std::vector<std::string> command);
};

#endif