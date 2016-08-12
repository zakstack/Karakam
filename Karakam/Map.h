#ifndef __MAP_H__
#define __MAP_H__

#include "MetaGet.h"
#include "TextureLibrary.h"
#include "Actor.h"

struct Tile
{
	sf::Sprite graphic;
	int tileId;
	int passability;
	bool isWater;
	int animFrame;
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
	Actor*** _actorMap;
	Actor* _mainPlayer;
	std::string _mapLoc;
	std::vector<std::pair<int, int>> _exitLocs;

public:
	Map(sf::RenderWindow* targetWindow);
	~Map();

	//Getters
	int getItem(int x, int y);
	Tile* getTile(int x, int y);
	Actor* getActor(int x, int y);
	sf::Texture getTextureMap();
	Actor* getPlayer();

	//Setters
	void setTile(int x, int y, Tile newTile);
	void setItem(int x, int y);
	void moveActor(Actor* targetActor, int newX, int newY);

	//Utility
	void drawMap(int xDrawCenter, int yDrawCenter, int drawDistance);
	void loadMap(std::string mapLoc);
	void saveMap();
	void newMap(std::string mapLoc);
};

#endif