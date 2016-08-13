#ifndef __PLAYER_BRAIN_H__
#define __PLAYER_BRAIN_H__

#include "Brain.h"
#include "SFML\Graphics.hpp"
#include <iostream>

class PlayerBrain :
	public Brain
{
public:
	PlayerBrain(sf::RenderWindow* targetWindow);
	~PlayerBrain();

	std::vector<std::string> think();
};

#endif