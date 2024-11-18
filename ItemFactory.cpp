#include "ItemFactory.h"

Item* ItemFactory::CreateGenericMedkit(short x, short y, short health) {
	return new Item(x, y, '+', health, 0, 0, 0);
}

Item* ItemFactory::CreateMedkit(short x, short y) {
	//return new Item(x, y, '+', 5, 0, 0, 0);
	return CreateGenericMedkit(x, y, 5);
}

Item* ItemFactory::CreateLargeMedkit(short x, short y) {
	//return new Item(x, y, '+', 5, 0, 0, 0);
	return CreateGenericMedkit(x, y, 10);
}

Item* ItemFactory::CreateHealthBonus(short x, short y, short health) {
	return new Item(x, y, '*', health, health, 0, 0);
}