#pragma once
#include "Entity.h"
#include "Map.h"

class Player : public Entity
{
public:
	Player(short x, short y, char symbol);
	void Act(char key, Map* map, Entity** entities, int eCount);
};

