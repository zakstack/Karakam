#ifndef __MAIN_GAME_H__
#define __MAIN_GAME_H__

#include <SFML\Graphics.hpp>
#include "Map.h"

class MainGame
{
private:
	sf::RenderWindow* _renderWindow;

public:
	MainGame(sf::RenderWindow* targetWindow);
	~MainGame();
};

#endif