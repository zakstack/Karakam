#include "CharacterCreator.h"

CharacterCreator::CharacterCreator(sf::RenderWindow* mainWindow, std::string libraryLoc)
{
	_renderWindow = mainWindow;
	_textureLibrary = new TextureLibrary;
	_textureLibrary->LoadLibrary(libraryLoc);
	_cursor.setTexture(_textureLibrary->getTexture(0));
	_cursor.setPosition(200, 200);
	_titleFont.loadFromFile("Bin/Fonts/Title2.ttf");
	_bodyFont.loadFromFile("Bin/Fonts/Body1.otf");
	_headerFont.loadFromFile("Bin/Fonts/Button1.ttf");
	mainMenu();
}


CharacterCreator::~CharacterCreator()
{
}

//Utilities
void CharacterCreator::mainMenu()
{
	bool back = false;

	//Title Bar
	sf::Text titleBar_text;

	//Back Button
	sf::RectangleShape back_but;
	back_but.setFillColor(sf::Color::White);
	back_but.setSize(sf::Vector2f(80, 30));
	back_but.setPosition(710, 10);

	//Character Window
	//TO DO : Add character customization
	sf::RectangleShape characterWindow_back;
	characterWindow_back.setFillColor(sf::Color::Yellow);
	characterWindow_back.setPosition(250,25);
	characterWindow_back.setSize(sf::Vector2f(300, 300));

		//Title Bar

		//Character
		sf::Sprite character_hair;
		sf::Sprite character_face;
		sf::Sprite character_body;
	//Gender : 0 = Male, 1 = Female, 2 = Ninja Turtle
	int gender = 0;

	//Stat Window
	sf::RectangleShape statWindow_back;
	statWindow_back.setFillColor(sf::Color::Yellow);
	statWindow_back.setSize(sf::Vector2f(300, 425));
	std::pair<int,int> statWindowLoc;
	statWindowLoc.first = 50;
	statWindowLoc.second = 350;
	statWindow_back.setPosition(statWindowLoc.first, statWindowLoc.second);

		//Title Bar
			sf::Text statWindowTitle_text;
			statWindowTitle_text.setFont(_headerFont);
			statWindowTitle_text.setColor(sf::Color::Red);
			statWindowTitle_text.setPosition(sf::Vector2f(statWindowLoc.first + 60, statWindowLoc.second + 5));
			statWindowTitle_text.setString("Character Stats");
			statWindowTitle_text.setStyle(sf::Text::Underlined);

		//STR
			sf::Text str_text;
			int strVal = 1;
			str_text.setFont(_headerFont);
			str_text.setColor(sf::Color::Red);
			str_text.setPosition(sf::Vector2f(statWindowLoc.first + 50, statWindowLoc.second + 50));
			str_text.setString("STR : " + std::to_string(strVal));

			sf::Text str_p;
			str_p.setFont(_headerFont);
			str_p.setColor(sf::Color::Red);
			str_p.setPosition(sf::Vector2f(statWindowLoc.first + 200, statWindowLoc.second + 50));
			str_p.setString("+");

			sf::Text str_m;
			str_m.setFont(_headerFont);
			str_m.setColor(sf::Color::Red);
			str_m.setPosition(sf::Vector2f(statWindowLoc.first + 175, statWindowLoc.second + 50));
			str_m.setString("-");

		//DEX
			sf::Text dex_text;
			int dexVal = 1;
			dex_text.setFont(_headerFont);
			dex_text.setColor(sf::Color::Red);
			dex_text.setPosition(sf::Vector2f(statWindowLoc.first + 50, statWindowLoc.second + 100));
			dex_text.setString("DEX : " + std::to_string(dexVal));

			sf::Text dex_p;
			dex_p.setFont(_headerFont);
			dex_p.setColor(sf::Color::Red);
			dex_p.setPosition(sf::Vector2f(statWindowLoc.first + 200, statWindowLoc.second + 100));
			dex_p.setString("+");

			sf::Text dex_m;
			dex_m.setFont(_headerFont);
			dex_m.setColor(sf::Color::Red);
			dex_m.setPosition(sf::Vector2f(statWindowLoc.first + 175, statWindowLoc.second + 100));
			dex_m.setString("-");

		//END
			sf::Text end_text;
			int endVal = 1;
			end_text.setFont(_headerFont);
			end_text.setColor(sf::Color::Red);
			end_text.setPosition(sf::Vector2f(statWindowLoc.first + 50, statWindowLoc.second + 150));
			end_text.setString("END : " + std::to_string(endVal));

			sf::Text end_p;
			end_p.setFont(_headerFont);
			end_p.setColor(sf::Color::Red);
			end_p.setPosition(sf::Vector2f(statWindowLoc.first + 200, statWindowLoc.second + 150));
			end_p.setString("+");

			sf::Text end_m;
			end_m.setFont(_headerFont);
			end_m.setColor(sf::Color::Red);
			end_m.setPosition(sf::Vector2f(statWindowLoc.first + 175, statWindowLoc.second + 150));
			end_m.setString("-");

		//AGL
			sf::Text agl_text;
			int aglVal = 1;
			agl_text.setFont(_headerFont);
			agl_text.setColor(sf::Color::Red);
			agl_text.setPosition(sf::Vector2f(statWindowLoc.first + 50, statWindowLoc.second + 200));
			agl_text.setString("AGL : " + std::to_string(aglVal));

			sf::Text agl_p;
			agl_p.setFont(_headerFont);
			agl_p.setColor(sf::Color::Red);
			agl_p.setPosition(sf::Vector2f(statWindowLoc.first + 200, statWindowLoc.second + 200));
			agl_p.setString("+");

			sf::Text agl_m;
			agl_m.setFont(_headerFont);
			agl_m.setColor(sf::Color::Red);
			agl_m.setPosition(sf::Vector2f(statWindowLoc.first + 175, statWindowLoc.second + 200));
			agl_m.setString("-");

		//INT
			sf::Text int_text;
			int intVal = 1;
			int_text.setFont(_headerFont);
			int_text.setColor(sf::Color::Red);
			int_text.setPosition(sf::Vector2f(statWindowLoc.first + 50, statWindowLoc.second + 250));
			int_text.setString("INT : " + std::to_string(intVal));

			sf::Text int_p;
			int_p.setFont(_headerFont);
			int_p.setColor(sf::Color::Red);
			int_p.setPosition(sf::Vector2f(statWindowLoc.first + 200, statWindowLoc.second + 250));
			int_p.setString("+");

			sf::Text int_m;
			int_m.setFont(_headerFont);
			int_m.setColor(sf::Color::Red);
			int_m.setPosition(sf::Vector2f(statWindowLoc.first + 175, statWindowLoc.second + 250));
			int_m.setString("-");

		//LUCK
			sf::Text lck_text;
			int lckVal = 1;
			lck_text.setFont(_headerFont);
			lck_text.setColor(sf::Color::Red);
			lck_text.setPosition(sf::Vector2f(statWindowLoc.first + 50, statWindowLoc.second + 300));
			lck_text.setString("LCK : " + std::to_string(lckVal));

			sf::Text lck_p;
			lck_p.setFont(_headerFont);
			lck_p.setColor(sf::Color::Red);
			lck_p.setPosition(sf::Vector2f(statWindowLoc.first + 200, statWindowLoc.second + 300));
			lck_p.setString("+");

			sf::Text lck_m;
			lck_m.setFont(_headerFont);
			lck_m.setColor(sf::Color::Red);
			lck_m.setPosition(sf::Vector2f(statWindowLoc.first + 175, statWindowLoc.second + 300));
			lck_m.setString("-");

		//Points
			sf::Text points_text;
			int points = 24;
			points_text.setFont(_headerFont);
			points_text.setColor(sf::Color::Red);
			points_text.setPosition(sf::Vector2f(statWindowLoc.first + 25, statWindowLoc.second + 350));
			points_text.setString("Points to Spend : " + std::to_string(points));

	//Profession Window
		sf::RectangleShape profWindow_back;
		profWindow_back.setFillColor(sf::Color::Yellow);
		profWindow_back.setSize(sf::Vector2f(350, 425));
		std::pair<int, int> profWindowLoc;
		profWindowLoc.first = 400;
		profWindowLoc.second = 350;
		profWindow_back.setPosition(profWindowLoc.first, profWindowLoc.second);

			//Title Bar
			sf::Text profWindowTitle_text;
			profWindowTitle_text.setFont(_headerFont);
			profWindowTitle_text.setColor(sf::Color::Red);
			profWindowTitle_text.setPosition(sf::Vector2f(profWindowLoc.first + 115, profWindowLoc.second + 5));
			profWindowTitle_text.setString("Profession");
			profWindowTitle_text.setStyle(sf::Text::Underlined);

	while (_renderWindow->isOpen() && back != true)
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow->close();
			if (event.type == sf::Event::MouseMoved)
				_cursor.setPosition(event.mouseMove.x, event.mouseMove.y);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//REMEMBER THAT THIS IS THE POLLING YOU WANT FOR PROPER MOUSE POSITION
				int xClickPos = event.mouseButton.x;
				int yClickPos = event.mouseButton.y;
				//Back Button
				if (xClickPos >= back_but.getPosition().x && xClickPos <= back_but.getPosition().x + back_but.getSize().x)
				{
					if (yClickPos >= back_but.getPosition().y && yClickPos <= back_but.getPosition().y + back_but.getSize().y)
					{
						back = true;
					}
				}
				//STR
				if (xClickPos >= str_p.getPosition().x && xClickPos <= str_p.getPosition().x + 10)
				{
					if (yClickPos >= str_p.getPosition().y + 15 && yClickPos <= str_p.getPosition().y + 25)
					{
						if (strVal < 10 && points > 0)
						{
							strVal++;
							points--;
							str_text.setString("STR : " + std::to_string(strVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				else if (xClickPos >= str_m.getPosition().x && xClickPos <= str_m.getPosition().x + 10)
				{
					if (yClickPos >= str_m.getPosition().y + 15 && yClickPos <= str_m.getPosition().y + 25)
					{
						if (strVal > 1)
						{
							strVal--;
							points++;
							str_text.setString("STR : " + std::to_string(strVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				//Dex
				if (xClickPos >= dex_p.getPosition().x && xClickPos <= dex_p.getPosition().x + 10)
				{
					if (yClickPos >= dex_p.getPosition().y + 15 && yClickPos <= dex_p.getPosition().y + 25)
					{
						if (dexVal < 10 && points > 0)
						{
							dexVal++;
							points--;
							dex_text.setString("DEX : " + std::to_string(dexVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				else if (xClickPos >= dex_m.getPosition().x && xClickPos <= dex_m.getPosition().x + 10)
				{
					if (yClickPos >= dex_m.getPosition().y + 15 && yClickPos <= dex_m.getPosition().y + 25)
					{
						if (dexVal > 1)
						{
							dexVal--;
							points++;
							dex_text.setString("DEX : " + std::to_string(dexVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				//End
				if (xClickPos >= end_p.getPosition().x && xClickPos <= end_p.getPosition().x + 10)
				{
					if (yClickPos >= end_p.getPosition().y + 15 && yClickPos <= end_p.getPosition().y + 25)
					{
						if (endVal < 10 && points > 0)
						{
							endVal++;
							points--;
							end_text.setString("END : " + std::to_string(endVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				else if (xClickPos >= end_m.getPosition().x && xClickPos <= end_m.getPosition().x + 10)
				{
					if (yClickPos >= end_m.getPosition().y + 15 && yClickPos <= end_m.getPosition().y + 25)
					{
						if (endVal > 1)
						{
							endVal--;
							points++;
							end_text.setString("END : " + std::to_string(endVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				//Agl
				if (xClickPos >= agl_p.getPosition().x && xClickPos <= agl_p.getPosition().x + 10)
				{
					if (yClickPos >= agl_p.getPosition().y + 15 && yClickPos <= agl_p.getPosition().y + 25)
					{
						if (aglVal < 10 && points > 0)
						{
							aglVal++;
							points--;
							agl_text.setString("AGL : " + std::to_string(aglVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				else if (xClickPos >= agl_m.getPosition().x && xClickPos <= agl_m.getPosition().x + 10)
				{
					if (yClickPos >= agl_m.getPosition().y + 15 && yClickPos <= agl_m.getPosition().y + 25)
					{
						if (aglVal > 1)
						{
							aglVal--;
							points++;
							agl_text.setString("AGL : " + std::to_string(aglVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				////Int
				if (xClickPos >= int_p.getPosition().x && xClickPos <= int_p.getPosition().x + 10)
				{
					if (yClickPos >= int_p.getPosition().y + 15 && yClickPos <= int_p.getPosition().y + 25)
					{
						if (intVal < 10 && points > 0)
						{
							intVal++;
							points--;
							int_text.setString("INT : " + std::to_string(intVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				else if (xClickPos >= int_m.getPosition().x && xClickPos <= int_m.getPosition().x + 10)
				{
					if (yClickPos >= int_m.getPosition().y + 15 && yClickPos <= int_m.getPosition().y + 25)
					{
						if (intVal > 1)
						{
							intVal--;
							points++;
							int_text.setString("INT : " + std::to_string(intVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				////Luck
				if (xClickPos >= lck_p.getPosition().x && xClickPos <= lck_p.getPosition().x + 10)
				{
					if (yClickPos >= lck_p.getPosition().y + 15 && yClickPos <= lck_p.getPosition().y + 25)
					{
						if (lckVal < 10 && points > 0)
						{
							lckVal++;
							points--;
							lck_text.setString("LCK : " + std::to_string(lckVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
				else if (xClickPos >= lck_m.getPosition().x && xClickPos <= lck_m.getPosition().x + 10)
				{
					if (yClickPos >= lck_m.getPosition().y + 15 && yClickPos <= lck_m.getPosition().y + 25)
					{
						if (lckVal > 1)
						{
							lckVal--;
							points++;
							lck_text.setString("LCK : " + std::to_string(lckVal));
							points_text.setString("Points to Spend : " + std::to_string(points));
						}
					}
				}
			}
		}

		_renderWindow->clear();

		//Draw the Back Button
		_renderWindow->draw(back_but);

		//Draw the Character Window
		_renderWindow->draw(characterWindow_back);

		//Draw the Stat Window
		_renderWindow->draw(statWindow_back);
		_renderWindow->draw(statWindowTitle_text);
		_renderWindow->draw(str_text);
			_renderWindow->draw(str_p);
			_renderWindow->draw(str_m);
		_renderWindow->draw(dex_text);
			_renderWindow->draw(dex_p);
			_renderWindow->draw(dex_m);
		_renderWindow->draw(end_text);
			_renderWindow->draw(end_p);
			_renderWindow->draw(end_m);
		_renderWindow->draw(agl_text);
			_renderWindow->draw(agl_p);
			_renderWindow->draw(agl_m);
		_renderWindow->draw(int_text);
			_renderWindow->draw(int_p);
			_renderWindow->draw(int_m);
		_renderWindow->draw(lck_text);
			_renderWindow->draw(lck_p);
			_renderWindow->draw(lck_m);
		_renderWindow->draw(points_text);

		//Draw the Proffession Window
		_renderWindow->draw(profWindow_back);
		_renderWindow->draw(profWindowTitle_text);

		//Draw the Cursor
		_renderWindow->draw(_cursor);

		_renderWindow->display();
	}
}

void CharacterCreator::getProfList()
{

}