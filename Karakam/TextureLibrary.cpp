#include "TextureLibrary.h"


TextureLibrary::TextureLibrary()
{
}

TextureLibrary::~TextureLibrary()
{
}

//Getters
sf::Texture& TextureLibrary::getTexture(int textID)
{
	return _library.at(textID);
}

//Setters
void TextureLibrary::addTexture(sf::Texture targetTexture)
{
	_library.push_back(targetTexture);
}

//Utilities
void TextureLibrary::LoadLibrary(std::string fileLoc)
{
	std::vector<std::vector<std::string>> locArray = _unpacker.getArray(fileLoc);
	for (int y = 0; y < locArray.size(); y++)
	{
		for (int x = 0; x < locArray.at(y).size(); x++)
		{
			//Add the texture at the given location to the library
			sf::Texture newTexture;
			_library.push_back(newTexture);
			_library.at(y).loadFromFile(locArray.at(y).at(x));
		}
	}
	std::cout << fileLoc + " : Library Loaded\n";
}