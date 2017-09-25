#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(sf::RenderWindow* renderWindow, Map* targetMap, std::string tglLoc, std::string aglLoc, std::string iglLoc)
{
	_renderWindow = renderWindow;
	_targetMap = targetMap;
	
	_tileGraphicLibrary.LoadLibrary(tglLoc);
	_actorGraphicLibrary.LoadLibrary(aglLoc);
	_itemGraphicLibrary.LoadLibrary(iglLoc);
	
	_gameFont.loadFromFile("Bin/Fonts/Body1.otf");
	
	_heightText.setFont(_gameFont);
	_heightText.setColor(sf::Color::White);
	_heightText.setCharacterSize(10);
	
	//Clear it and set up size
	_matrix.clear();
	for (int yy = 0; yy < _targetMap->getMapSizeVector().y; yy++)
	{
		std::vector<int> row;
		for (int xx = 0; xx < _targetMap->getMapSizeVector().x; xx++)
		{
			row.push_back(0);
		}
		_matrix.push_back(row);
	}

	//Populate _matrix with all of the top positions
	for (int yy = 0; yy < _targetMap->getMapSizeVector().y; yy++)
	{
		for (int xx = 0; xx < _targetMap->getMapSizeVector().x; xx++)
		{
			for (int zz = _targetMap->getActiveActors()->at(0)->_zPosition; zz < _targetMap->getMapSizeVector().z; zz++)
			{
				//Find which tile is on top
				if (_targetMap->getGameMap()[xx][yy][zz] == nullptr)
				{
					//This is the top point from the current player position
					_matrix.at(xx).at(yy) = zz;
					zz = _targetMap->getMapSizeVector().z;
				}
			}
		}
	}

}


GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::drawTile(int x, int y, int z)
{
	sf::Sprite drawSprite;

	switch (_targetMap->getGameMap()[x][y][z]->getEntityTypeID())
	{
		//Tiles
	case 0:
		//Determine if the tile is on the same level as the player or not
		drawSprite.setTexture(_tileGraphicLibrary.getTexture(_targetMap->getGameMap()[x][y][z]->getEntityID()));
		break;
		//Actor
	case 1:
		drawSprite.setTexture(_actorGraphicLibrary.getTexture(_targetMap->getGameMap()[x][y][z]->getEntityID()));
		break;
		//Other
	case 2:
		break;
	default:
		break;
	}

	drawSprite.setPosition(x * 50, y * 50);
	//Determine where the sprite is in accordance to where the player is and draw accordingly
	if (z < _targetMap->getActiveActors()->at(0)->_zPosition - 1)
	{
		drawSprite.setColor(sf::Color(122 / _targetMap->getActiveActors()->at(0)->_zPosition - z, 122 / (_targetMap->getActiveActors()->at(0)->_zPosition - z), 122 / (_targetMap->getActiveActors()->at(0)->_zPosition - z), 255));
		_renderWindow->draw(drawSprite);
	}
	//The tile is directly below the actor and is top tile
	else if (z == _targetMap->getActiveActors()->at(0)->_zPosition - 1)
	{
		drawSprite.setColor(sf::Color(255, 255, 255, 255));
		_renderWindow->draw(drawSprite);
	}
	//If the target is the character
	else if (_targetMap->getGameMap()[x][y][z] == _targetMap->getActiveActors()->at(0))
	{
		drawSprite.setColor(sf::Color(255, 255, 255, 255));
		_renderWindow->draw(drawSprite);
	}
	//If the target is on the same level as the actor display how many tiles until the next highest tile
	else if (z == _targetMap->getActiveActors()->at(0)->_zPosition && _targetMap->getGameMap()[x][y][z] != nullptr)
	{
		drawSprite.setColor(sf::Color(50, 50, 50, 255));
		_heightText.setPosition(x * 50 + 20, y * 50 + 20);
		_heightText.setString(std::to_string(_matrix.at(x).at(y) - _targetMap->getActiveActors()->at(0)->_zPosition));
		_renderWindow->draw(drawSprite);
		_renderWindow->draw(_heightText);
	}

}

void GraphicsEngine::drawInventory(Inventory* targetInventory)
{
	//Draw a window extending from the object who's inventory has been opened
	if (targetInventory->getOpen() == true)
	{
		//Pull positional information
		int colums = (targetInventory->getVector()->size() - (targetInventory->getVector()->size() % 5)) / 5;
		if (colums == 0) { colums = 1; }
		int rows = targetInventory->getVector()->size() % 5;
		int boxSize = 50;

		//Draw the window
		sf::RectangleShape background; 
		background.setFillColor(sf::Color::White);
		background.setPosition(sf::Vector2f(targetInventory->_owner->_location.first*boxSize + boxSize, targetInventory->_owner->_location.second*boxSize - boxSize));
		background.setSize(sf::Vector2f(boxSize * rows,boxSize * colums));
		_renderWindow->draw(background);
		//Draw the items
		for(int i = 0; i < targetInventory->getVector()->size(); i++)
		{
			//draw each items box determined by the size of the inventory
			sf::RectangleShape stall;
			stall.setFillColor(sf::Color::Blue);
			stall.setPosition(sf::Vector2f((((targetInventory->_owner->_location.first + (i % 5)) * boxSize) + boxSize), (((targetInventory->_owner->_location.second + ((i - (i % 5))/5)) * boxSize) - boxSize)));
			stall.setSize(sf::Vector2f(boxSize * rows, boxSize * colums));
			_renderWindow->draw(stall);
		}
	}
	else
	{
		std::cout << "THERE HASE BEEN AN ERROR IN THE GRAPHICS ENGINE : DRAW INVENTORY";
	}
	//The player will eventually be able to click on an item to either use/drop/take/give the item
}