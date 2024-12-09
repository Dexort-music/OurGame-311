#include "Entity.h"

Entity::Entity() {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

Entity::Entity(short x, short y, char symbol, short health, short attack, short defence, string name, string desc) {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	this->x = x;
	this->y = y;
	this->symbol = symbol;

	this->health = health;
	this->maxHealth = health;
	this->attack = attack;
	this->defence = defence;

	this->name = name;
	this->desc = desc;
}

void Entity::Draw() {
	FillConsoleOutputCharacter(consoleHandle, symbol, 1, {x, y}, &a);
}