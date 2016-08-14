#include "Game.h"

Game::Game()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800, 800), "Karakram");

	//Load the Map (Requires the Graphic Libraries to draw self)
	Map newMap("Bin/Maps/SaveSlot1/Master.txt",&mainWindow);

	//Begin the game loop
	// run the program as long as the window is open
	while (mainWindow.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}

		// clear the window with black color
		mainWindow.clear(sf::Color::Black);

		//mainWindow.draw();

		mainWindow.display();
	}
	
	//GAME LOOP
		//Check for events
			//Iterate through actors list via Map command
		//Draw the Map via Map command
		//Draw the PlayerPanel
}


Game::~Game()
{
}
