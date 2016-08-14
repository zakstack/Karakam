#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include <string>
#include "Actor_Ent.h"
#include "Tile.h"
#include "MetaGet.h"
#include <unordered_map>
#include "VeroniMapGen.h"

class Map
{
private:
	const int _NUM_OF_LAYERS = 2;
	const int _X_SIZE = 100;
	const int _Y_SIZE = 100;
	std::vector<std::vector<std::string>> _directorList;
	std::vector<Entity*> _activeActors;
	sf::RenderWindow* _renderWindow;

protected:
	//Libraries for all of the standard Entity Types
	std::unordered_map<int,Actor_Ent*> _actorLibrary;
	std::unordered_map<int,Tile*> _tileLibrary;

	Entity**** _gameMap;
public:
	Map(std::string masterLoc,sf::RenderWindow* renderWindow);
	~Map();

	void tick();

	void test();
};

#endif