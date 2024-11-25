#pragma once
#include "Entity.h"

class Item : public Entity
{
public:
	Item(short x, short y, char symbol, short health, short maxHealth, short attack, short defence, string name, string desc);
	bool Use(Entity* target);
};

