#include <string>
#include "TitleScreen.h"
#include "MapGen.h"

int main()
{
	//Load the Title Screen
	sf::RenderWindow* mainWindow = new sf::RenderWindow;
	mainWindow->create(sf::VideoMode(800, 800), "Karakam");
	while (mainWindow->isOpen())
	{
		//START THE GAME
		TitleScreen Karakam(mainWindow, "Textures/Test/Test.txt");
	}

	return 1;
}