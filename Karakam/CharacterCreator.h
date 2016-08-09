#ifndef __CHARACTER_CREATOR_H__
#define __CHARACTER_CREATOR_H__

#include <SFML\Graphics.hpp>
#include "MetaGet.h"
#include "TextureLibrary.h"
#include "MainGame.h"

class CharacterCreator
{
private:
	TextureLibrary* _textureLibrary;
	sf::RenderWindow* _renderWindow;

	sf::Sprite _cursor;
	sf::Sprite _background;

	sf::Font _titleFont;
	sf::Font _bodyFont;
	sf::Font _headerFont;

public:
	CharacterCreator(sf::RenderWindow* mainWindow, std::string libraryLoc);
	~CharacterCreator();

	//Utilities
	void mainMenu();
	void getProfList();

};

#endif