#include "TitleScreen.h"

TitleScreen::TitleScreen(sf::RenderWindow* mainWindow, std::string libraryLoc)
{
	_textureLibrary = new TextureLibrary;
	_textureLibrary->LoadLibrary(libraryLoc);
	_renderWindow = mainWindow;
	_cursor.setTexture(_textureLibrary->getTexture(0));
	_cursor.setPosition(200, 200);
	_background.setTexture(_textureLibrary->getTexture(3));
	_background.setPosition(0, 0);
	_titleFont.loadFromFile("Bin/Fonts/Title1.ttf");
	_buttonFont.loadFromFile("Bin/Fonts/Button1.ttf");
	//Build and display the title screen
	mainMenu();
}

TitleScreen::~TitleScreen()
{
}

//Utilities
void TitleScreen::mainMenu()
{
	_renderWindow->setMouseCursorVisible(false);

	while (_renderWindow->isOpen())
	{
		//Title Bar
		sf::Text titleBar_text;
		titleBar_text.setFont(_titleFont);
		titleBar_text.setCharacterSize(64);
		titleBar_text.setPosition(sf::Vector2f(320, 70));
		titleBar_text.setString("ZOMBIE");
		titleBar_text.setColor(sf::Color::Black);

		//New Game Button
		sf::RectangleShape newGame_but(sf::Vector2f(150,50));
		newGame_but.setPosition(350, 200);
		newGame_but.setFillColor(sf::Color::Black);
		sf::Text newGame_text;
		newGame_text.setFont(_buttonFont);
		newGame_text.setPosition(370,200);
		newGame_text.setString("New Game");
		newGame_text.setColor(sf::Color::Red);
		//Load Game Button
		sf::RectangleShape loadGame_but(sf::Vector2f(150, 50));
		loadGame_but.setPosition(350, 350);
		loadGame_but.setFillColor(sf::Color::Black);
		sf::Text loadGame_text;
		loadGame_text.setFont(_buttonFont);
		loadGame_text.setPosition(370, 350);
		loadGame_text.setString("Load Game");
		loadGame_text.setColor(sf::Color::Red);
		//Settings Button
		sf::RectangleShape settings_but(sf::Vector2f(150, 50));
		settings_but.setPosition(350, 500);
		settings_but.setFillColor(sf::Color::Black);
		sf::Text settings_text;
		settings_text.setFont(_buttonFont);
		settings_text.setPosition(380, 500);
		settings_text.setString("Settings");
		settings_text.setColor(sf::Color::Red);
		//Quit Button
		sf::RectangleShape exit_but(sf::Vector2f(150, 50));
		exit_but.setPosition(350, 650);
		exit_but.setFillColor(sf::Color::Black);
		sf::Text exit_text;
		exit_text.setFont(_buttonFont);
		exit_text.setPosition(400, 650);
		exit_text.setString("Exit");
		exit_text.setColor(sf::Color::Red);

		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
			if (event.type == sf::Event::MouseMoved)
				_cursor.setPosition(event.mouseMove.x,event.mouseMove.y);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//REMEMBER THAT THIS IS THE POLLING YOU WANT FOR PROPER MOUSE POSITION
				int xClickPos = event.mouseButton.x;
				int yClickPos = event.mouseButton.y;
				if (xClickPos >= 350 && xClickPos <= 500)
				{
					//New Game
					if (yClickPos >= newGame_but.getPosition().y && yClickPos <= newGame_but.getPosition().y + newGame_but.getSize().y)
					{
						newGame();
					}
					//Load Game
					else if (yClickPos >= loadGame_but.getPosition().y && yClickPos <= loadGame_but.getPosition().y + loadGame_but.getSize().y)
					{
						NewGame newGame(_renderWindow);
					}
					//Settings
					else if (yClickPos >= settings_but.getPosition().y && yClickPos <= settings_but.getPosition().y + settings_but.getSize().y)
					{
						settings();
					}
					//Exit
					else if (yClickPos >= exit_but.getPosition().y && yClickPos <= exit_but.getPosition().y + exit_but.getSize().y)
					{
						quit();
					}
				}
			}
		}

		_renderWindow->clear();
		_renderWindow->draw(_background);
		_renderWindow->draw(titleBar_text);
		_renderWindow->draw(newGame_but);
		_renderWindow->draw(newGame_text);
		_renderWindow->draw(loadGame_but);
		_renderWindow->draw(loadGame_text);
		_renderWindow->draw(settings_but);
		_renderWindow->draw(settings_text);
		_renderWindow->draw(exit_but);
		_renderWindow->draw(exit_text);
		_renderWindow->draw(_cursor);
		_renderWindow->display();
	}
}

void TitleScreen::newGame()
{
	//TO DO : Select a Save Slot
	//Run Character Creator
	CharacterCreator(_renderWindow, "Textures/CharacterCreator/Test.txt");
}

//TO DO : FINISH IMPLEMENTING LOAD GAMES
void TitleScreen::loadGame()
{
	MetaGet listGetter;
	std::vector<std::vector<std::string>> saveList = listGetter.getArray("Bin/Saves/list.txt");

	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
		}

		_renderWindow->clear();
		_renderWindow->display();
	}
}


//TO DO: FINISH IMPLEMENTING SETTINGS
void TitleScreen::settings()
{
	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
		}

		_renderWindow->clear();
		_renderWindow->display();
	}
}

void TitleScreen::quit()
{
	_renderWindow->close();
}