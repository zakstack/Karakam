#ifndef __MetaGet__
#define __MetaGet__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

//Allows you to extract meta data array's from specified files
class MetaGet
{
private:
	std::vector<std::vector<std::string>> _storageArray;
	int _storageXSize;
	int _storageYSize;

public:
	MetaGet();
	~MetaGet();

	//Getters
	std::vector<std::vector<std::string>> getArray(std::string fileLocation);
};

#endif