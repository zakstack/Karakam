#ifndef __VEGITABLE_BRAIN_H__
#define __VEGITABLE_BRAIN_H__

#include "Brain.h"
class VegitableBrain :
	public Brain
{
public:
	VegitableBrain(sf::RenderWindow* targetWindow);
	~VegitableBrain();

	std::vector<std::string> think();
};

#endif