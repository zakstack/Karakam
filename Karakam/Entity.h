#ifndef __ENTITY_H__
#define __ENTITY_H__

//DEPENDENCIES
#include "SFML\Graphics.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "TextureLibrary.h"

class Entity
{
private:

protected:
	Entity**** _gameMap;
	
	//Entity Type ID's are as follows
	/*
		0 : Tile
		1 : Item
		2 : Actor
		3 : SFX Layer -> Not Yet implemented
	*/
public:
	//Constructors and Destructor
	Entity(Entity**** gameMap, sf::RenderWindow* targetWindow,int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int zPosition);
	Entity();
	~Entity();

	//Openly Accessable Values
	int _exists;
	std::pair<int, int> _location;
	int _zPosition;
	int _xFacing;
	int _yFacing;
	int _entityTypeID;
	int _entityID;

	//The Command System : Receiving Commands
	virtual std::vector<std::string> receiveCommand(std::vector<std::string> command);

	//Receivable Commands
	int getXFacing();
	int getYFacing();
	virtual std::string moveEntity(int xPos, int yPos, int zPos);
	std::pair<int, int> getLocation();
	int getEntityID();
	int getEntityTypeID();

	//Utilities
	std::vector<std::string> stringToVector(std::string targetString, std::string token);
	int getExists();

	//Decided that all things have inventories for eas of implementation. May move this but it does allow for Tiles and items to have items too which could be useful
	//Inventory* _inventory;

	sf::RenderWindow* _renderWindow;
};
#endif