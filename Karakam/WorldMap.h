#ifndef __WORLD_MAP_H__
#define __WORLD_MAP_H__

#include "Map.h";
#include "MetaGet.h";
#include <vector>

class WorldMap
{
private:
	std::vector<std::vector<Map*>> _WorldMap;

public:
	WorldMap();
	~WorldMap();
};

#endif