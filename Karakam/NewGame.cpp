#include "NewGame.h"
#include "MapGen.h"

NewGame::NewGame(sf::RenderWindow* targetWindow)
{
	_renderWindow = targetWindow;
	//Generate the new Map
	MapGen newMap("SaveSlot1");
	newMap.genTileMap();
	newMap.genPassabilityMap();
	newMap.genIsWaterMap();
	//Start the game
	MainGame newGame(_renderWindow, "Bin/Maps/SaveSlot1/Master.txt");
}


NewGame::~NewGame()
{
}