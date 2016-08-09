#include "Actor.h"

Actor::Actor()
{

}

Actor::~Actor()
{

}

//Getters
int Actor::getHealth()
{
	return _health;
}
int Actor::getStamina()
{
	return _stamina;
}
int Actor::getStr()
{
	return _str;
}
int Actor::getDex()
{
	return _dex;
}
int Actor::getEnd()
{
	return _end;
}
int Actor::getAgl()
{
	return _agl;
}
int Actor::getInt()
{
	return _int;
}
int Actor::getLck()
{
	return _lck;
}
sf::Sprite Actor::getGraphic()
{
	return _actorGraphic;
}
int Actor::getXPos()
{
	return _xPos;
}
int Actor::getYPos()
{
	return _yPos;
}
int Actor::getGraphicID()
{
	return _graphicID;
}

//Setters
void Actor::setName(std::string newName)
{
	_name = newName;
}
void Actor::modHealth(int amount)
{
	_health = _health + amount;
}
void Actor::modStamina(int amount)
{
	_stamina = _stamina + amount;
}
void Actor::setHealth(int amount)
{
	_health = amount;
}
void Actor::setStamina(int amount)
{
	_stamina = amount;
}
void Actor::setStr(int amount)
{
	_str = amount;
}
void Actor::setDex(int amount)
{
	_dex = amount;
}
void Actor::setEnd(int amount)
{
	_end = amount;
}
void Actor::setAgl(int amount)
{
	_agl = amount;
}
void Actor::setInt(int amount)
{
	_int = amount;
}
void Actor::setLck(int amount)
{
	_lck = amount;
}
void Actor::setXPos(int xLoc)
{
	_xPos = xLoc;
}
void Actor::setYPos(int yLoc)
{
	_yPos = yLoc;
}
void Actor::setPosition(int x, int y)
{
	_xPos = x;
	_yPos = y;
	_actorGraphic.setPosition(50 * _xPos, 50 * _yPos);
}
void Actor::setGraphic(sf::Texture* targetTexture)
{
	_actorGraphic.setTexture(*targetTexture);
}
void Actor::setGraphicID(int newID)
{
	_graphicID = newID;
}

//Utilities
void Actor::loadActor(std::string actorLoc)
{
	MetaGet actorGetter;
	std::vector<std::vector<std::string>> dataSet = actorGetter.getArray(actorLoc);
	setHealth(std::stoi(dataSet.at(0).at(0)));
	setStamina(std::stoi(dataSet.at(0).at(1)));
	setName(dataSet.at(0).at(2));
	setStr(std::stoi(dataSet.at(0).at(3)));
	setDex(std::stoi(dataSet.at(0).at(4)));
	setEnd(std::stoi(dataSet.at(0).at(5)));
	setAgl(std::stoi(dataSet.at(0).at(6)));
	setInt(std::stoi(dataSet.at(0).at(7)));
	setLck(std::stoi(dataSet.at(0).at(8)));
	setXPos(std::stoi(dataSet.at(0).at(9)));
	setYPos(std::stoi(dataSet.at(0).at(10)));
	setGraphicID(std::stoi(dataSet.at(0).at(11)));
	_actorGraphic.setPosition(50 * _xPos, 50 * _yPos);
}