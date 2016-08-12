#include "MapSplitter.h"

MapSplitter::MapSplitter(std::string tileSetLoc)
{
	sf::Image tileSet;
	tileSet.loadFromFile(tileSetLoc);

	for (int y = 0; y < 40; y++)
		for (int x = 0; x < 25; x++)
		{
			sf::Texture newTile;
			newTile.loadFromImage(tileSet, sf::IntRect(sf::Vector2<int>(x * 50, y * 50), sf::Vector2<int>(50, 50)));
			newTile.copyToImage().saveToFile("Textures/Test/" + std::to_string(x)+ "_" + std::to_string(y) + ".png");
		}
}


MapSplitter::~MapSplitter()
{
}
