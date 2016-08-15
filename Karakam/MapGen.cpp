#include "MapGen.h"

MapGen::MapGen(std::string mapName)
{
	_mapName = mapName;
}


MapGen::~MapGen()
{
}

void MapGen::generateTopography()
{
}

//TESTING
void MapGen::writeToFile(std::string fileName, std::vector<std::vector<int>> targetMap)
{
	std::ofstream myfile(fileName, std::ios::ate);
	if (myfile.is_open())
	{
		for (int y = 0; y < _MAPYSIZE; y++)
		{
			for (int x = 0; x < _MAPXSIZE; x++)
			{
				myfile << targetMap.at(x).at(y);
				myfile << ",";
			}
			myfile << "\n";
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}