#ifndef __ENTITY_H__
#define __ENTITY_H__

//DEPENDENCIES
#include "SFML\Graphics.hpp";
#include <vector>
#include <string>
#include <iostream>
#include "TextureLibrary.h"

class Entity
{
private:
	int _entityID;
	int _facing;
	std::vector<std::vector<std::vector<Entity>>>* _gameMap; 

	//Receivable Commands
	int getEntityID();
	int getEntityTypeID();
	int getFacing();
	std::pair<int, int> getLocation();

protected:
	virtual std::string moveEntity(int xPos, int yPos);
	sf::RenderWindow* _renderWindow;
	std::pair<int, int> _location;
	int _entityTypeID;
	//Entity Type ID's are as follows
	/*
		0 : Tile
		1 : Item
		2 : Actor
		3 : SFX Layer -> Not Yet implemented
	*/

	int _exists;

public:
	Entity(std::vector<std::vector<std::vector<Entity>>>* gameMap,sf::RenderWindow* targetWindow);
	~Entity();

	//The Command System : Receiving Commands
	virtual std::vector<std::string> receiveCommand(std::vector<std::string> command);

	//Utilities
	std::vector<std::string> stringToVector(std::string targetString, std::string token);
	int getExists();

	//TESTING
	void visualTest();
	std::string _TESTLIBRARYLOC = "Textures/Test/Load.txt";
	TextureLibrary _testLibrary;
	sf::Sprite _entityGraphic;

};
#endif