#ifndef __VERONI_MAP_GEN__
#define __VERONI_MAP_GEN__

#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>

//FOR TESTING
#include <iostream>
#include <fstream>

class VeroniMapGen
{
private:
	std::vector<std::vector<int>> _matrix;
	int _xSize;
	int _ySize;
	int _density;
	int _variance;

public:
	VeroniMapGen(int xSize, int ySize, int density, int variance);
	~VeroniMapGen();

	//Getters
	std::vector<std::vector<int>> getIntMatrix();
	std::vector<std::vector<int>> newIntMatrix();
	//std::vector<std::vector<std::string>> getStringMatrix();

	//Test
	void writeToFile(std::string writeLoc);
};

#endif