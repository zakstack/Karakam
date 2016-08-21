#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include <string>
#include "Actor_Ent.h"
#include "Tile.h"
#include "MetaGet.h"
#include <unordered_map>
#include "VeroniMapGen.h"
#include "Item.h"
#include "SFML\Graphics.hpp"

class Map
{
private:
	const int _Z_SIZE = 10;
	const int _X_SIZE = 100;
	const int _Y_SIZE = 100;

	std::vector<std::vector<std::string>> _directorList;
	std::vector<Entity*> _activeActors;

	sf::RenderWindow* _renderWindow;

protected:
	//Libraries for all of the standard Entity Types
	std::unordered_map<int,Actor_Ent*> _actorLibrary;
	std::unordered_map<int,Tile*> _tileLibrary;
	std::unordered_map<int, Item*> _itemLibrary;

	Entity**** _gameMap;
public:
	//Constructor & Destructor
	Map(std::string masterLoc, sf::RenderWindow* renderWindow);
	~Map();

	//Tick Tock Tick Tock
	void tick();

	//Getters
	sf::Vector3i getMapSizeVector();
	std::vector<Entity*>* getActiveActors();
	Entity**** getGameMap();

	//Utility
	void dumpToFile(std::string fileLoc, int zLevel);
};

#endif