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
	virtual std::string moveEntity(int xPos, int yPos);
	sf::RenderWindow* _renderWindow;
	int _entityTypeID;
	int _entityID;
	int _xFacing;
	int _yFacing;
	
	//Entity Type ID's are as follows
	/*
		0 : Tile
		1 : Item
		2 : Actor
		3 : SFX Layer -> Not Yet implemented
	*/

	//Receivable Commands
	int getXFacing();
	int getYFacing();

public:
	Entity(Entity**** gameMap, sf::RenderWindow* targetWindow,int entityID, int xFacing, int yFacing, int xPosition, int yPosition, int zPosition);
	Entity();
	~Entity();

	int _exists;

	//The Command System : Receiving Commands
	virtual std::vector<std::string> receiveCommand(std::vector<std::string> command);

	//Utilities
	std::vector<std::string> stringToVector(std::string targetString, std::string token);
	int getExists();
	//Receivable Command
	std::pair<int, int> getLocation();
	int getEntityID();
	int getEntityTypeID();

	//TESTING
	void visualTest();
	std::string _TESTLIBRARYLOC = "Textures/Test/Load.txt";
	TextureLibrary _testLibrary;
	sf::Sprite _entityGraphic;
	std::pair<int, int> _location;
	int _zPosition;

};
#endif