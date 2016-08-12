#include "MapGen.h"

MapGen::MapGen(std::string mapName)
{
	_mapName = mapName;
}


MapGen::~MapGen()
{
}

//Getters
int MapGen::pointStat(int z, int x, int y)
{
	return _map.at(z).at(x).at(y);
}

std::vector<std::vector<int>> MapGen::defaultMatrix(int target)
{
	//Create the default matrix
	std::vector<std::vector<int>> matrix;
	for (int y = 0; y < _MAPYSIZE; y++)
	{
		std::vector<int> row;
		for (int x = 0; x < _MAPXSIZE; x++)
		{
			row.push_back(target);
		}
		matrix.push_back(row);
	}
	return matrix;
}

//Utilities
void MapGen::genTileMap()
{
	//Create a Veroni Map as the base of the TileMap
	VeroniMapGen generator(_MAPXSIZE,_MAPYSIZE,100,5);
	_map.push_back(generator.getIntMatrix());
	writeToFile("Bin/Maps/" + _mapName + "/Layout.txt",_map.back());

}

void MapGen::genDetailMap()
{
	std::vector<std::vector<int>> matrix = defaultMatrix(0);
	writeToFile("Bin/Maps/" + _mapName + "/Detail.txt", matrix);
}

void MapGen::genItemMap()
{
	std::vector<std::vector<int>> matrix = defaultMatrix(0);
	writeToFile("Bin/Maps/" + _mapName + "/Item.txt", matrix);
}

void MapGen::genActorMap()
{
	std::vector<std::vector<int>> matrix = defaultMatrix(0);
	writeToFile("Bin/Maps/" + _mapName + "/ActorMap.txt", matrix);
}

void MapGen::genActionMap()
{
	std::vector<std::vector<int>> matrix = defaultMatrix(0);
	writeToFile("Bin/Maps/" + _mapName + "/Action.txt", matrix);
}

void MapGen::genSfxMap()
{
	std::vector<std::vector<int>> matrix = defaultMatrix(0);
	writeToFile("Bin/Maps/" + _mapName + "/Sfx.txt", matrix);
}
void MapGen::genPassabilityMap()
{
	std::vector<std::vector<int>> matrix = defaultMatrix(0);
	for (int y = 0; y < _MAPYSIZE; y++)
	{
		for (int x = 0; x < _MAPXSIZE; x++)
		{
			//Ask if the tile at given x-y is below 2 which are all of the unpassibletiles 
			if (_map.at(0).at(x).at(y) < 2)
			{
				matrix.at(x).at(y) = 1;
			}
		}
	}
	_map.push_back(matrix);
	writeToFile("Bin/Maps/" + _mapName + "/Passability.txt", matrix);
}
void MapGen::genIsWaterMap()
{
	std::vector<std::vector<int>> matrix = defaultMatrix(0);
	for (int y = 0; y < _MAPYSIZE; y++)
	{
		for (int x = 0; x < _MAPXSIZE; x++)
		{
			//Ask if the tile at given x-y is below 2 which are all of the unpassibletiles 
			if (_map.at(0).at(x).at(y) == 0)
			{
				matrix.at(x).at(y) = 1;
			}
		}
	}
	_map.push_back(matrix);
	writeToFile("Bin/Maps/" + _mapName + "/IsWater.txt", matrix);
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