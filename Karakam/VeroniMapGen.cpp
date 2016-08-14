#include "VeroniMapGen.h"

VeroniMapGen::VeroniMapGen(int xSize, int ySize,int density, int variance)
{
	_xSize = xSize;
	_ySize = ySize;
	_density = density;
	_variance = variance;
	std::srand(time(NULL));
	newIntMatrix();
}

VeroniMapGen::~VeroniMapGen()
{
}

//Getters
std::vector<std::vector<int>> VeroniMapGen::getIntMatrix()
{
	return _matrix;
}

std::vector<std::vector<int>> VeroniMapGen::newIntMatrix()
{
	//Build the default matrix
	_matrix.clear();
	for (int y = 0; y < _ySize; y++)
	{
		std::vector<int> row;
		for (int x = 0; x < _xSize; x++)
		{
			row.push_back(0);
		}
		_matrix.push_back(row);
	}

	//Determine the random center points
	std::vector<std::pair<int, int>> randomPoints;
	for (int i = 0; i < _density; i++)
	{
		std::pair<int, int> point;
		point.first = rand() % _xSize;
		point.second = rand() % _ySize;
		randomPoints.push_back(point);
	}

	//Set those points to seeds on matrix
	for (int y = 0; y < _ySize; y++)
	{
		for (int x = 0; x < _xSize; x++)
		{
			for (int i = 0; i < randomPoints.size(); i++)
			{
				if (randomPoints.at(i).first == x && randomPoints.at(i).second == y)
				{
					if (_matrix.at(x).at(y) == 0)
					{
						_matrix.at(x).at(y) = (rand() % _variance);
					}
				}
			}
		}
	}

	//Grow the seeds to closest area maps
	for (int y = 0; y < _ySize; y++)
	{
		for (int x = 0; x < _xSize; x++)
		{
			float distance = 0.0f;

			for (int i = 0; i < randomPoints.size(); i++)
			{
				if (distance == 0)
				{
					//Calculate the distance between the target point and current point
					distance = sqrt(pow((randomPoints.at(i).first - x), 2) + pow((randomPoints.at(i).second - y), 2));
					//Define the point as the closest random point which is currenlty the first choice
					_matrix.at(x).at(y) = _matrix.at(randomPoints.at(i).first).at(randomPoints.at(i).second);
				}
				else
				{
					//Calculate the distance between the target point and current point
					float newDistance;
					newDistance = sqrt(pow((randomPoints.at(i).first - x), 2) + pow((randomPoints.at(i).second - y), 2));
					if (newDistance < distance)
					{
						//Define the point as the closest random point which is no long the last choice
						distance = newDistance;
						_matrix.at(x).at(y) = _matrix.at(randomPoints.at(i).first).at(randomPoints.at(i).second);
					}
				}
			}
		}
	}

	return _matrix;
}

//std::vector<std::vector<std::string>> VeroniMapGen::getStringMatrix()
//{
//	return 
//}

//Test
void VeroniMapGen::writeToFile(std::string writeLoc )
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