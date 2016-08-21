#include "Inventory.h"

Inventory::Inventory(Entity* owner, int size)
{
	_owner = owner;
	_size = size;
	_open = false;
}

Inventory::~Inventory()
{
}

//GUI
bool Inventory::getOpen()
{
	return _open;
}

void Inventory::setOpen(bool isOpen)
{
	_open = isOpen;
}

void Inventory::dumpToConsole()
{
	std::cout << "TESTING, this should be the inventory eventually\n";
}

//Data Management
std::vector<Item>* Inventory::getVector()
{
	return &_container;
}

Item* Inventory::getItem(int loc)
{
	return &_container.at(loc);
}

void Inventory::removeItem(int loc)
{
	_container.erase(_container.begin()+loc);
}

void Inventory::addItem(Item targetItem)
{
	_container.push_back(targetItem);
}

//Inter-Inventory
Item Inventory::giveToInventory(int loc, Inventory* targetInventory)
{
	Item givenItem = _container.at(loc);
	_container.erase(_container.begin() + loc);
	return givenItem;
}

void Inventory::takeFromInventory(int loc, Inventory* targetInventory)
{
	_container.push_back(targetInventory->giveToInventory(loc, this));
}

void Inventory::useOnEntity(int loc, Entity* targetEntity)
{
	if (loc < _container.size())
	{
		_container.at(loc).use(targetEntity);
		_container.erase(_container.begin() + loc);
	}
}