#ifndef __GAME_H__
#define __GAME_H__

#include "SFML\Graphics.hpp"
#include "GraphicsEngine.h"
#include "Map.h"

class Game
{
private:
	sf::RenderWindow* mainWindow;
	Map* gameMap;


	const int _X_VIEW = 6;
	const int _Y_VIEW = 6;
public:
	Game();
	~Game();

	void getEvents();
};

#endif