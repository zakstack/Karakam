#include "Map.h"

Map::Map(sf::RenderWindow* targetWindow)
{
	_targetWindow = targetWindow;
}

Map::~Map()
{
}

//Getters
//TO DO
int Map::getItem(int x, int y)
{
	return 0;
}

Tile* Map::getTile(int x, int y)
{
	return &_tileMap.at(x).at(y);
}

//TO DO
int Map::getActor(int x, int y)
{
	return 0;
}

sf::Texture Map::getTextureMap()
{
	sf::RenderTexture cat;
	cat.create(100, 100);
	return cat.getTexture();
}

//Setters
void Map::setTile(int x, int y, Tile newTile)
{
	_tileMap.at(x).at(y) = newTile;
}

// TO DO
void Map::setItem(int x, int y)
{

}

// TO DO
void Map::setActor(int x, int y)
{

}

//Utility
void Map::drawMap()
{
	for (int y = 0; y < _tileMap.size(); y++)
	{
		for (int x = 0; x < _tileMap.at(0).size(); x++)
		{
			_targetWindow->draw(_tileMap.at(y).at(x).graphic);
		}
	}
}

void Map::loadMap(std::string mapLoc)
{
	MetaGet mapGetter;
	std::vector<std::vector<std::string>> mapData = mapGetter.getArray(mapLoc);
	//First element is the tile graphic library location
	_tileLibrary.LoadLibrary(mapData.at(0).at(0));
	//Second element is the map layout location (these are values associated with the graphics library)
	std::vector<std::vector<std::string>> mapLayout = mapGetter.getArray(mapData.at(1).at(0));
	//Third element is the passability location
	std::vector<std::vector<std::string>> passability = mapGetter.getArray(mapData.at(2).at(0));
	//Fourth element is the isWater location
	std::vector<std::vector<std::string>> isWater = mapGetter.getArray(mapData.at(3).at(0));
	//Once all of these have been found and loaded we can load up the tile map
	for (int y = 0; y < mapLayout.at(0).size(); y++)
	{
		std::vector<Tile> newXLine;
		for (int x = 0; x < mapLayout.size(); x++)
		{
			Tile newTile;
			newTile.graphic.setTexture(_tileLibrary.getTexture(std::stoi(mapLayout.at(x).at(y))));
			newTile.graphic.setPosition(x * 50, y * 50);
			newTile.passability = (std::stoi(passability.at(x).at(y)));
			newTile.isWater = (std::stoi(isWater.at(x).at(y)));
			newXLine.push_back(newTile);
		}
		_tileMap.push_back(newXLine);
	}
}

//TO DO
void Map::saveMap()
{

}

//TO DO
void Map::newMap(std::string mapLoc)
{

}