#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <vector>
#include <string>
#include "SFML\Graphics.hpp"

class Brain
{
private:

protected:
	//A brain can pull the status of the body of the creature that its attached to according to how that type of brain pulls information. (Some brains may not work in other bodies)
	std::vector<int*>* _status;
	//Standard Practice will have the following first 4 stats
	/*
		0 : xPos
		1 : yPos
		2 : xFacing
		3 : yFacing
	*/
	sf::RenderWindow * _renderWindow;
public:
	Brain(sf::RenderWindow* targetWindow);
	~Brain();
	virtual std::vector<std::string> think() = 0;

	void setStatus(std::vector<int*>* targetStatus);
};

#endif 