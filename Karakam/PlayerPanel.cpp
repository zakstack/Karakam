#include "PlayerPanel.h"

PlayerPanel::PlayerPanel(sf::RenderWindow* renderWindow, Actor* targetActor)
{
	_renderWindow = renderWindow;
	_targetActor = targetActor;

	//Load in the fonts
	_panelTitle_f.loadFromFile("Bin/Fonts/Title1.ttf");
	_panelText_f.loadFromFile("Bin/Fonts/Body1.otf");

	//Set Up the Status Bar
	_statusBar_t.setFont(_panelTitle_f);
	_statusBar_t.setPosition(0, 0);
	_statusBar_t.setColor(sf::Color::Red);


	//Set Up the Skill Bar
	_skillBar_t.setFont(_panelText_f);
	_skillBar_t.setPosition(0, 600);
	_skillBar_t.setColor(sf::Color::Red);


}


PlayerPanel::~PlayerPanel()
{

}

//Utilities
void PlayerPanel::drawPanel()
{
	std::string str = "HEALTH : " + std::to_string(_targetActor->getHealth()) + "               Stamina : " + std::to_string(_targetActor->getStamina());
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	_statusBar_t.setString(str);
	_statusBar_t.setPosition((_targetActor->getXPos()*50) - 390, (_targetActor->getYPos()*50) - 340);
	_renderWindow->draw(_statusBar_t);
	str = "STR : " + std::to_string(_targetActor->getStr()) + " DEX : " + std::to_string(_targetActor->getDex()) + " END : " + std::to_string(_targetActor->getEnd()) + "\nAGL : " + std::to_string(_targetActor->getAgl()) + " INT : " + std::to_string(_targetActor->getInt()) + " LCK : " + std::to_string(_targetActor->getLck());
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	_skillBar_t.setString(str);
	_skillBar_t.setPosition((_targetActor->getXPos() * 50) - 390, (_targetActor->getYPos() * 50) + 340);
	_renderWindow->draw(_skillBar_t);
}