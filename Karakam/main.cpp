#include <string>
#include "VeroniMapGen.h"
#include "Game.h"

int main()
{
	VeroniMapGen newGen(100, 100, 200, 3);
	newGen.writeToFile("Bin/Maps/SaveSlot1/Maps/Layout.txt");
	//Testing out the new Map System
	Game newGame;
	newGame.~Game();
	return 1;
}