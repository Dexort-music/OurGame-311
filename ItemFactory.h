#pragma once
#include "Entity.h"
#include "Item.h"

static class ItemFactory
{
public:
	static Item* CreateMedkit(short x, short y);
	static Item* CreateLargeMedkit(short x, short y);
	static Item* CreateGenericMedkit(short x, short y, short health);
	static Item* CreateHealthBonus(short x, short y, short health);
};

