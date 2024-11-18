#pragma once
#include "Entity.h"
#include "Map.h"
#include "Item.h"

class Player : public Entity
{
public:
	Player(short x, short y, char symbol, short health, short attack, short defence);
	void Act(char key, Map* map, Entity** entities, int eCount);
};

