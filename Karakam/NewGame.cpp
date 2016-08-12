#include "NewGame.h"

NewGame::NewGame(sf::RenderWindow* targetWindow)
{
	_renderWindow = targetWindow;
	//Start the game
	MainGame newGame(_renderWindow, "Bin/Maps/SaveSlot1/Master.txt");
}


NewGame::~NewGame()
{
}