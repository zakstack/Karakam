#ifndef __MAP_GEN_H__
#define __MAP_GEN_H__

#include "MetaGet.h"
#include "VeroniMapGen.h"
#include <windows.h>

class MapGen
{
private:
	std::vector<std::vector<std::vector<int>>> _map;
		//The Layers contained in this structure are as follows
		/*Z)The First layer is the z layer it defines movement orthoginally from the 2d plane of the X & Y layers. This contains combinations of the above variables as one Layer
			z.0)The Zeroith value is the X-Y matrix for tileID
			z.1)The First value is the X-Y matrix for detailID
			z.2)The Second value is the X-Y matrix for itemID
			z.3)The Third value is the X-Y matrix for actorID
			z.4)The Fourth value is the X-Y matrix for actionID
			z.5)The Fifth value is the X-Y matrix for sfxID
			z.6)The Sixth value is the X-Y matrix for passability
			z.7)The Seveneth value is the X-Y matrix for isWater
		  X)The Second layer is the X layer it defines movement to the right of the point.
		  Y)The Third layer is the Y layer it defines movement down from the point.
		*/

	std::string _mapName;

	const int _MAPXSIZE = 100;
	const int _MAPYSIZE = 100;
public:
	MapGen(std::string mapName);
	~MapGen();

	//Getters
	int pointStat(int z, int x, int y);
	std::vector<std::vector<int>> defaultMatrix(int target);

	//Utilities
	void genTileMap();
	void genDetailMap();
	void genItemMap();
	void genActorMap();
	void genActionMap();
	void genSfxMap();
	void genPassabilityMap();
	void genIsWaterMap();

	void writeToFile(std::string fileName, std::vector<std::vector<int>> targetMap);
};

#endif