#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player(short x, short y, char symbol) {
		this->x = x;
		this->y = y;
		this->symbol = symbol;
	}
};

