#ifndef __TEXTURE_LIBRARY_H__
#define __TEXTURE_LIBRARY_H__

#include "MetaGet.h"
#include <SFML\Graphics.hpp>

//Holds all of the texture for the game and manages their distribution

//TO DO:
	//- Add a way to load the Library
	//- Add a way to get a particular texture
	//- Add a way to view all of the textures in a library for testing purposes
class TextureLibrary
{
private:
	std::vector<sf::Texture> _library;
	MetaGet _unpacker;

public:
	TextureLibrary();
	~TextureLibrary();

	//Getters
	sf::Texture& getTexture(int textID);

	//Setters
	void addTexture(sf::Texture targetTexture);

	//Utilities
	void LoadLibrary(std::string fileLoc);
};

#endif