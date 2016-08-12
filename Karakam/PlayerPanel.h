#ifndef __PLAYER_PANEL_H__
#define __PLAYER_PANEL_H__

#include "Actor.h"
#include <SFML\Graphics.hpp>
#include <algorithm>

class PlayerPanel
{
private:
	sf::RenderWindow* _renderWindow;
	Actor* _targetActor;
	sf::Font _panelTitle_f;
	sf::Font _panelText_f;
	sf::Text _statusBar_t;
	sf::Text _skillBar_t;
	sf::RectangleShape _statusBar_b;
	sf::RectangleShape _skillBar_b;

public:
	PlayerPanel(sf::RenderWindow* renderWindow, Actor* targetActor);
	~PlayerPanel();

	//Utilities
	void drawPanel();
};

#endif