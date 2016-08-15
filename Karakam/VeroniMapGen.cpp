#include "VeroniMapGen.h"

VeroniMapGen::VeroniMapGen(int xSize, int ySize, int zSize,int density, int variance)
{
	_xSize = xSize;
	_ySize = ySize;
	if (zSize < variance)
	{
		_zSize = variance;
	}
	else
	{
		_zSize = zSize;
	}
	_density = density;
	_variance = variance;
	std::srand(time(NULL));
	genMap();
}

VeroniMapGen::~VeroniMapGen()
{
}

//Getters
std::vector<std::vector<int>> VeroniMapGen::getMap()
{
	return _matrix;
}

//Matrix Controls
void VeroniMapGen::clearMatrix(std::vector<std::vector<int>>* targetMatrix)
{
	targetMatrix->clear();
	for (int y = 0; y < _ySize; y++)
	{
		std::vector<int> row;
		for (int x = 0; x < _xSize; x++)
		{
			row.push_back(0);
		}
		targetMatrix->push_back(row);
	}
}

void VeroniMapGen::clearCube(std::vector<std::vector<std::vector<int>>>* targetMatrix)
{
	//Clear out the cube
	_cube.clear();

	//Fill the cube with new clear layers
	for (int z = 0; z < _zSize; z++)
	{
		std::vector<std::vector<int>> newMatrix;
		clearMatrix(&newMatrix);
		_cube.push_back(newMatrix);
	}
}


//Seed Controls
std::vector<std::pair<int,int>> VeroniMapGen::generateSeeds(int xMin, int xMax, int yMin, int yMax, int density)
{
	//Determine the random center points
	std::vector<std::pair<int, int>> seeds;
	for (int i = 0; i < density; i++)
	{
		std::pair<int, int> point;
		point.first = xMin + rand() % (xMax - xMin);
		point.second = yMin + rand() % (yMax - yMin);
		seeds.push_back(point);
	}
	return seeds;
}

void VeroniMapGen::plantSeeds(std::vector<std::pair<int, int>> seeds, int seedVariance, std::vector<std::vector<int>>* targetMatrix)
{
	//Set those points to seeds on matrix
	for (int i = 0; i < seeds.size(); i++)
	{
		int x = seeds.at(i).first;
		int y = seeds.at(i).second;
		targetMatrix->at(x).at(y) = (rand() % seedVariance);
	}
}

void VeroniMapGen::growSeeds(std::vector<std::pair<int,int>> seeds, std::vector<std::vector<int>>* targetMatrix)
{
	//Grow the seeds to closest seed area maps
	for (int y = 0; y < _ySize; y++)
	{
		for (int x = 0; x < _xSize; x++)
		{
			float distance = 0.0f;

			for (int i = 0; i < seeds.size(); i++)
			{
				if (distance == 0)
				{
					//Calculate the distance between the target point and current point
					distance = sqrt(pow((seeds.at(i).first - x), 2) + pow((seeds.at(i).second - y), 2));
					//Define the point as the closest random point which is currenlty the first choice
					targetMatrix->at(x).at(y) = targetMatrix->at(seeds.at(i).first).at(seeds.at(i).second);
				}
				else
				{
					//Calculate the distance between the target point and current point
					float newDistance;
					newDistance = sqrt(pow((seeds.at(i).first - x), 2) + pow((seeds.at(i).second - y), 2));
					if (newDistance < distance)
					{
						//Define the point as the closest random point which is no long the last choice
						distance = newDistance;
						targetMatrix->at(x).at(y) = targetMatrix->at(seeds.at(i).first).at(seeds.at(i).second);
					}
				}
			}
		}
	}
}



//Generators
std::vector<std::vector<int>> VeroniMapGen::genMap()
{
	//Build the default matrix
	clearMatrix(&_matrix);

	//Determine the random center points
	std::vector<std::pair<int, int>> seeds = generateSeeds(0, _xSize, 0, _ySize, _density);

	//Plant the seeds in the area map
	plantSeeds(seeds, _variance, &_matrix);

	//Grow the seeds to closest area maps
	growSeeds(seeds, &_matrix);

	return _matrix;
}

std::vector<std::vector<int>> VeroniMapGen::generateMultiPassMap(int numPasses)
{
	clearMatrix(&_matrix);

	//Determine the random center points
	std::vector<std::pair<int, int>> seeds = generateSeeds(0, _xSize, 0, _ySize, _density);

	//Plant the seeds in the area map
	plantSeeds(seeds, _variance, &_matrix);

	//Grow the seed bed
	growSeeds(seeds, &_matrix);

	//Regrow the seed bed a number of times
	for (int i = 0; i < numPasses - 1; i++)
	{
		std::vector<std::pair<int, int>> newSeeds = generateSeeds(0, _xSize, 0, _ySize, _density);
		growSeeds(newSeeds, &_matrix);
	}

	return _matrix;
}

std::vector<std::vector<std::vector<int>>> VeroniMapGen::generateCubeMap(int numPasses)
{
	//Clear out and fill with empty the Cube
	clearCube(&_cube);

	//Generate a MultiPassMap to be the topographical map for the game
	generateMultiPassMap(numPasses);
	//For each point in the topographical map store a 1 at the designated point in the matrix and all points below it
	for (int y = 0; y < _ySize; y++)
	{
		for (int x = 0; x < _xSize; x++)
		{
			for (int z = 0; z < _matrix.at(x).at(y); z++)
			{
				_cube.at(z).at(x).at(y) = 1;
			}
		}
	}
	return _cube;
}

std::vector<std::vector<std::vector<int>>> VeroniMapGen::generateWorkingMap(int numPasses)
{
	//Generate a new cube-map
	generateCubeMap(numPasses);

	for (int z = 0; z < _zSize; z++)
	{
		//Create a new genMap
		generateMultiPassMap(numPasses);
		for (int y = 0; y < _ySize; y++)
		{
			for (int x = 0; x < _xSize; x++)
			{
				//For each point in the cube-map
				if (_cube.at(z).at(x).at(y) != 0)
				{
					_cube.at(z).at(x).at(y) = _matrix.at(x).at(y);
				}
			}
		}
	}
	return _cube;
}


//File IO
void VeroniMapGen::writeToFile(std::string writeLoc)
{
	std::ofstream myfile(writeLoc, std::ios::ate);
	if (myfile.is_open())
	{
		for (int y = 0; y < _ySize; y++)
		{
			for (int x = 0; x < _xSize; x++)
			{
				myfile << _matrix.at(x).at(y);
				myfile << ",";
			}
			myfile << "\n";
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}

void VeroniMapGen::writeCubeToFile(std::string writeLoc, int zLevels)
{
		for (int z = 0; z < zLevels; z++)
		{
			std::ofstream myfile(writeLoc + std::to_string(z) + ".txt", std::ios::ate);
			if (myfile.is_open())
			{
				for (int y = 0; y < _ySize; y++)
				{
					for (int x = 0; x < _xSize; x++)
					{
						myfile << _cube.at(z).at(x).at(y);
						myfile << ",";
					}
					myfile << "\n";
				}
			}
			else
			{
				std::cout << "Unable to open file";
			}
			myfile.close();
		}

}

std::vector<std::vector<std::vector<int>>> VeroniMapGen::loadCubeFromFile(std::string loadLoc, int zLevels)
{
	std::vector<std::vector<std::vector<int>>> newCube;
	//For each map file
	for (int z = 0; z < zLevels; z++)
	{
		MetaGet getter;
		newCube.push_back(getter.getIntArray(loadLoc + std::to_string(z) + ".txt"));
	}
	return newCube;
}

//Entity**** VeroniMapGen::generateEntityMap()
//{
//}