#ifndef __MAP_SPLITTER_H__
#define __MAP_SPLITTER_H__

#include <SFML\Graphics.hpp>
#include <stdio.h>
#include <ostream>
#include <fstream>

class MapSplitter
{
public:
	MapSplitter(std::string tileSetLoc);
	~MapSplitter();
};

#endif