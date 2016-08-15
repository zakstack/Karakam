#ifndef __MAP_GEN_H__
#define __MAP_GEN_H__

#include "MetaGet.h"
#include "VeroniMapGen.h"
#include <windows.h>

class MapGen
{
private:
	const int _MAPXSIZE = 250;
	const int _MAPYSIZE = 250;
	const int _MAPZSIZE = 5;
	const int _DENSITY = 300;
	const int _VARIANCE = 5;
	std::string _mapName;
public:
	MapGen(std::string mapName);
	~MapGen();

	void generateTopography();

	void writeToFile(std::string fileName, std::vector<std::vector<int>> targetMap);
};

#endif