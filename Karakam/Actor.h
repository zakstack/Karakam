#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <SFML\Graphics.hpp>
#include "MetaGet.h"

class Actor
{
private:
	sf::Sprite _actorGraphic;
	sf::Texture _actorTexture;

	//TO DO : Divide health among limbs and have each limb have a health and make this master health
	int _health;
	int _stamina;
	std::string _name;
	int _str;
	int _dex;
	int _end;
	int _agl;
	int _int;
	int _lck;
	int _xPos;
	int _yPos;
	int _graphicID;

	//Inventory
public:
	Actor();
	~Actor();

	//Getters
	int getHealth();
	int getStamina();
	int getStr();
	int getDex();
	int getEnd();
	int getAgl();
	int getInt();
	int getLck();
	sf::Sprite getGraphic();
	int getXPos();
	int getYPos();
	int getGraphicID();
	std::string getName();

	//Setters
	void setName(std::string newName);
	void modHealth(int amount);
	void modStamina(int amount);
	void setHealth(int amount);
	void setStamina(int amount);
	void setStr(int amount);
	void setDex(int amount);
	void setEnd(int amount);
	void setAgl(int amount);
	void setInt(int amount);
	void setLck(int amount);
	void setXPos(int xLoc);
	void setYPos(int yLoc);
	void setPosition(int x, int y);
	void setGraphic(sf::Texture* targetTexture);
	void setGraphicID(int newID);
	

	//Utilities
	void loadActor(std::string actorLoc);
};

#endif