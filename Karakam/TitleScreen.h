#ifndef __TITLE_SCREEN_H__
#define __TITLE_SCREEN_H__

#include "MetaGet.h"
#include "TextureLibrary.h"
#include <SFML\Graphics.hpp>
#include "CharacterCreator.h"
#include "Map.h"
#include "MapViewer.h"

class TitleScreen
{
private:
	TextureLibrary* _textureLibrary;
	sf::RenderWindow* _renderWindow;

	sf::Sprite _cursor;
	sf::Sprite _background;
	
	sf::Font _titleFont;
	sf::Font _buttonFont;

public:
	TitleScreen(sf::RenderWindow* mainWindow, std::string libraryLoc);
	~TitleScreen();

	//Utilities
	void mainMenu();
	void newGame();
	void loadGame();
	void settings();
	void quit();
};

#endif