#ifndef __NEW_GAME_H__
#define __NEW_GAME_H__

#include <string>

#include "SFML\Graphics.hpp"
#include "MainGame.h"

class NewGame
{
private:
	sf::RenderWindow* _renderWindow;
public:
	NewGame(sf::RenderWindow* targetWindow, std::string characterLoc);
	~NewGame();

	//Utilities
	void buildMap();
	void buildLayout();
	void buildPassability();
	void buildIsWater();
	void populateActors();
};

#endif