#ifndef __CHARACTER_CREATOR_H__
#define __CHARACTER_CREATOR_H__

#include <SFML\Graphics.hpp>
#include "MetaGet.h"
#include "TextureLibrary.h"

class CharacterCreator
{
private:
	TextureLibrary* _textureLibrary;
	sf::RenderWindow* _renderWindow;

	sf::Sprite _cursor;
	sf::Sprite _background;

public:
	CharacterCreator(sf::RenderWindow* mainWindow, std::string libraryLoc);
	~CharacterCreator();

	//Utilities
	void mainMenu();
	void getProfList();

};

#endif