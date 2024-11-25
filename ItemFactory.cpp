#include "ItemFactory.h"

Item* ItemFactory::CreateGenericMedkit(short x, short y, short health, string name, string desc) {
	return new Item(x, y, '+', health, 0, 0, 0, name, desc);
}

Item* ItemFactory::CreateMedkit(short x, short y) {
	//return new Item(x, y, '+', 5, 0, 0, 0);
	return CreateGenericMedkit(x, y, 5, "Medkit", "Small medkit, restores 5 hp");
}

Item* ItemFactory::CreateLargeMedkit(short x, short y) {
	//return new Item(x, y, '+', 5, 0, 0, 0);
	return CreateGenericMedkit(x, y, 10, "Large Medkit", "Large medkit, restores 10 hp");
}

Item* ItemFactory::CreateHealthBonus(short x, short y, short health) {
	return new Item(x, y, '*', health, health, 0, 0, "HP Bonus", "HP bonus, increases max hp");
}