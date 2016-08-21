#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML\Graphics.hpp>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item> _container;
	int _size;
	bool _open;

public:
	Inventory(Entity* owner, int size);
	~Inventory();

	//GUI - Only applicable for viewing the inventory
	bool getOpen();
	void setOpen(bool isOpen);
	void dumpToConsole();

	//Data Management
	std::vector<Item>* getVector();
	Item* getItem(int loc);
	void removeItem(int loc);
	void addItem(Item targetItem);

	//Inter-Inventory
	Item giveToInventory(int loc, Inventory* targetInventory);
	void takeFromInventory(int loc, Inventory* targetInventory);
	void useOnEntity(int loc, Entity* targetEntity);

	//PUBLIC ONLY FOR TESTING
	Entity* _owner;

};

#endif