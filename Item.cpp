#include "Item.h"

Item::Item(short x, short y, char symbol, short health, short maxHealth, short attack, short defence, string name, string desc)
	: Entity::Entity(x, y, symbol, health, attack, defence, name, desc) {
	this->maxHealth = maxHealth;

	type = EType::_Item;
}

bool Item::Use(Entity* target) {
	// предмет изменяет максимальное здоровье
	if (maxHealth != 0) {
		target->maxHealth += maxHealth;
		if (target->health <= 0) {
			target->isAlive = false;
		}
	}
	// предмет изменяет здоровье
	if (health != 0) {

		if (target->health == target->maxHealth) {
			return false;
		}

		target->health += health;
		if (target->health > target->maxHealth) {
			target->health = target->maxHealth;
		}

		if (target->health <= 0) {
			target->isAlive = false;
		}
	}
	// оружие / изменение атаки
	if (attack != 0) {
		target->attack = attack;
	}
	// защита / изменение защиты
	if (defence != 0) {
		target->defence = defence;
	}
	return true;
}