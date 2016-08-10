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

Tile* Map::getTile(int y, int x)
{
	return &_tileMap.at(y).at(x);
}

//TO DO
Actor* Map::getActor(int y, int x)
{
	return _actorMap[y][x];
}

sf::Texture Map::getTextureMap()
{
	sf::RenderTexture cat;
	cat.create(100, 100);
	return cat.getTexture();
}

//Setters
void Map::setTile(int y, int x, Tile newTile)
{
	_tileMap.at(y).at(x) = newTile;
}

// TO DO
void Map::setItem(int x, int y)
{

}

void Map::moveActor(Actor* targetActor, int yMove, int xMove)
{
	if (_actorMap[targetActor->getYPos() + yMove][targetActor->getXPos() + xMove] == nullptr && getTile(targetActor->getYPos() + yMove, targetActor->getXPos() + xMove)->passability == 0);
	{
		_actorMap[targetActor->getYPos() + yMove][targetActor->getXPos() + xMove] = targetActor;
		_actorMap[targetActor->getYPos()][targetActor->getXPos()] = nullptr;
		targetActor->setPosition(targetActor->getXPos() + xMove, targetActor->getYPos() + yMove);
	}
}

//Utility
void Map::drawMap()
{
	for (int y = 0; y < _tileMap.size(); y++)
	{
		for (int x = 0; x < _tileMap.at(0).size(); x++)
		{
			_targetWindow->draw(_tileMap.at(y).at(x).graphic);
			if (_actorMap[y][x] != nullptr)
			{
				_targetWindow->draw(_actorMap[y][x]->getGraphic());
			}
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
	for (int y = 0; y < mapLayout.size(); y++)
	{
		std::vector<Tile> newXLine;
		for (int x = 0; x < mapLayout.at(0).size(); x++)
		{
			Tile newTile;
			newTile.graphic.setTexture(_tileLibrary.getTexture(std::stoi(mapLayout.at(y).at(x))));
			newTile.graphic.setPosition(x * 50, y * 50);
			newTile.passability = (std::stoi(passability.at(y).at(x)));
			newTile.isWater = (std::stoi(isWater.at(y).at(x)));
			newXLine.push_back(newTile);
		}
		_tileMap.push_back(newXLine);
	}
	//Build the Actor Map
	_actorMap = new Actor**[mapLayout.size()];
	for (int i = 0; i < mapLayout.size(); ++i)
	{
		_actorMap[i] = new Actor*[mapLayout.at(0).size()];
	}
	for (int y = 0; y < mapLayout.size(); y++)
	{
		for (int x = 0; x < mapLayout.at(0).size(); x++)
		{
			_actorMap[y][x] = nullptr;
		}
	}
	//Fifth Element is the Actor Graphic List
	_actorLibrary.LoadLibrary(mapData.at(4).at(0));

	//Sixth Element is the Actor Master Load List
	std::vector<std::vector<std::string>> actorLoadList = mapGetter.getArray(mapData.at(5).at(0));

	//Load all of the actors present in the load List
	for (int y = 0; y < actorLoadList.size(); y++)
	{
		Actor* newActor;
		newActor = new Actor();
		newActor->loadActor(actorLoadList.at(y).at(0));
		newActor->setGraphic(&_actorLibrary.getTexture(newActor->getGraphicID()));
		_actorMap[newActor->getYPos()][newActor->getXPos()] = newActor;
	}
	std::cout << "cats";
}

//TO DO
void Map::saveMap()
{

}

//TO DO
void Map::newMap(std::string mapLoc)
{

}