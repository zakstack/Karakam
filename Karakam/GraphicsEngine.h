#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "Map.h"
#include "TextureLibrary.h"
#include "SFML\Graphics.hpp"


class GraphicsEngine
{
private:
	sf::RenderWindow* _renderWindow;
	Map* _targetMap;
	TextureLibrary _tileGraphicLibrary;
	TextureLibrary _actorGraphicLibrary;
	TextureLibrary _itemGraphicLibrary;
	sf::Font _gameFont;
	sf::Text _heightText;
	std::vector<std::vector<int>> _matrix;

public:
	GraphicsEngine(sf::RenderWindow* renderWindow, Map* targetMap, std::string tglLoc, std::string aglLoc, std::string iglLoc);
	~GraphicsEngine();

	void drawTile(int x, int y, int z);
	void drawInventory(Inventory * targetInventory);
};

#endif