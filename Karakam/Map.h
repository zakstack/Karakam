#ifndef __MAP_H__
#define __MAP_H__

#include "MetaGet.h"
#include "TextureLibrary.h"

struct Tile
{
	sf::Sprite graphic;
	int passability;
	bool isWater;
};

class Map
{
private:
	sf::RenderWindow* _targetWindow;
	TextureLibrary _tileLibrary;
	TextureLibrary _actorLibrary;
	TextureLibrary _itemLibrary;
	std::vector<std::vector<Tile>> _tileMap;
	std::vector<std::vector<int>> _itemMap;
	std::vector<std::vector<int>> _actorMap;
	std::string _mapLoc;
	std::vector<std::pair<int, int>> _exitLocs;

public:
	Map(sf::RenderWindow* targetWindow);
	~Map();

	//Getters
	int getItem(int x, int y);
	Tile* getTile(int x, int y);
	int getActor(int x, int y);
	sf::Texture getTextureMap();

	//Setters
	void setTile(int x, int y, Tile newTile);
	void setItem(int x, int y);
	void setActor(int x, int y);

	//Utility
	void drawMap();
	void loadMap(std::string mapLoc);
	void saveMap();
	void newMap(std::string mapLoc);
};

#endif