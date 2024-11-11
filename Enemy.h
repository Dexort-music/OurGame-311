#pragma once
#include "Entity.h"
#include "Map.h"

class Enemy : public Entity
{
public:
	Enemy(short x, short y, char symbol, short health, short attack, short defence);

	void SimpleAI(Map* map, Entity** entities, int eCount);
};

