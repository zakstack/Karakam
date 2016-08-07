#include <string>
#include "TitleScreen.h"

int main()
{
	//Load the Title Screen
	sf::RenderWindow* mainWindow = new sf::RenderWindow;
	mainWindow->create(sf::VideoMode(800, 800), "Karakam");
	while (mainWindow->isOpen())
	{
		TitleScreen Karakam(mainWindow, "Textures/Test/Test.txt");
	}

	return 1;
}