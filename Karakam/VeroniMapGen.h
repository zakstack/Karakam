#ifndef __VERONI_MAP_GEN__
#define __VERONI_MAP_GEN__

#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include "Entity.h"
#include "MetaGet.h"

//FOR TESTING
#include <iostream>
#include <fstream>

class VeroniMapGen
{
private:
	std::vector<std::vector<std::vector<int>>> _cube;
	std::vector<std::vector<int>> _matrix;
	int _xSize;
	int _ySize;
	int _zSize;
	int _density;
	int _variance;

public:
	VeroniMapGen(int xSize, int ySize, int zSize, int density, int variance);
	~VeroniMapGen();

	//Getters
	std::vector<std::vector<int>> getMap();

	//Matrix Controls
	void clearMatrix(std::vector<std::vector<int>>* targetMatrix);
	void clearCube(std::vector<std::vector<std::vector<int>>>* targetMatrix);
	std::vector<std::vector<int>> getTops(std::vector<std::vector<std::vector<int>>>* targetCube);

	//Seed Controls
	std::vector<std::pair<int,int>> generateSeeds(int xMin, int xMax, int yMin, int yMax, int density);
	void plantSeeds(std::vector<std::pair<int, int>> seeds, int seedVariance, std::vector<std::vector<int>>* targetMatrix);
	void growSeeds(std::vector<std::pair<int,int>> seeds, std::vector<std::vector<int>>* targetMatrix);

	//Generators
	std::vector<std::vector<int>> generateMultiPassMap(int numPasses);
	std::vector<std::vector<int>> genMap();
	std::vector<std::vector<std::vector<int>>> generateCubeMap(int numPasses);
	std::vector<std::vector<std::vector<int>>> generateWorkingMap(int numPasses);
	std::vector<std::vector<std::vector<int>>> generatePerfectMap();

	//File IO
	void writeToFile(std::string writeLoc);
	void writeCubeToFile(std::string writeLoc, int zLevels);
	std::vector<std::vector<std::vector<int>>> loadCubeFromFile(std::string loadLoc, int zLevels);

};

#endif