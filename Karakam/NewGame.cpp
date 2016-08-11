#include "NewGame.h"

NewGame::NewGame(sf::RenderWindow* targetWindow, std::string characterLoc)
{
	_renderWindow = targetWindow;
	//Create the map

	//Add the Player Character to the map


	//Start the game
	MainGame newGame(_renderWindow, "Bin/Maps/SaveSlot1/Master.txt");
}


NewGame::~NewGame()
{
}

//Utilities THESE ARE TEMPORARY UNTIL WORLD MAP GENERATOR IS BUILT AND THEN THEY WILL GO THERE
void NewGame::buildMap()
{

}
void NewGame::buildLayout()
{

}
void NewGame::buildPassability()
{

}
void NewGame::buildIsWater()
{

}
void NewGame::populateActors()
{

}
