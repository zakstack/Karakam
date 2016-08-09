#ifndef __MAIN_GAME_H__
#define __MAIN_GAME_H__

#include <SFML\Graphics.hpp>
#include "Map.h"
#include "ActorController.h"

class MainGame
{
private:
	sf::RenderWindow* _renderWindow;
	sf::Sprite _cursor;
	sf::Texture _cursorTexture;
	std::vector<Actor*> _activeActors;
	Map* _testMap;

public:
	MainGame(sf::RenderWindow* targetWindow);
	~MainGame();
};

#endif