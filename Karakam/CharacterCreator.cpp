#include "CharacterCreator.h"

CharacterCreator::CharacterCreator(sf::RenderWindow* mainWindow, std::string libraryLoc)
{
	_renderWindow = mainWindow;
	_textureLibrary = new TextureLibrary;
	_textureLibrary->LoadLibrary(libraryLoc);
	_cursor.setTexture(_textureLibrary->getTexture(0));
	_cursor.setPosition(200, 200);
	mainMenu();
}


CharacterCreator::~CharacterCreator()
{
}

//Utilities
void CharacterCreator::mainMenu()
{
	bool back = false;

	while (_renderWindow->isOpen() && back != true)
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
			if (event.type == sf::Event::MouseMoved)
				_cursor.setPosition(event.mouseMove.x, event.mouseMove.y);
		}

		_renderWindow->clear();
		_renderWindow->draw(_cursor);
		_renderWindow->display();
	}
}

void CharacterCreator::getProfList()
{

}