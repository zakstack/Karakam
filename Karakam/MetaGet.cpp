#include "MetaGet.h"

MetaGet::MetaGet()
{
	_storageArray.clear();
}

MetaGet::~MetaGet()
{
}

std::vector<std::vector<std::string>> MetaGet::getArray(std::string fileLocation)
{
	_storageArray.clear();
	std::string line;
	std::vector<std::string> divLine;
	std::ifstream file (fileLocation);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			//Check if it is a skip line
			if (line.substr(0, 1) != "@")
			{
				//Build the divLine
				size_t pos = 0;
				while ((pos = line.find(",")) != std::string::npos)
				{
					divLine.push_back(line.substr(0, pos));
					line.erase(0, pos + 1);
				}
				_storageArray.push_back(divLine);
				divLine.clear();
			}
		}
	}
	else 
	{
		//FILE COULD NOT BE READ
		std::cout << "File at :" + fileLocation + " could not be read";
	}
	return _storageArray;
}