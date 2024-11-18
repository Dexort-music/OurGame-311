#include "Item.h"

Item::Item(short x, short y, char symbol, short health, short maxHealth, short attack, short defence) {
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	this->health = health;
	this->maxHealth = maxHealth;
	this->attack = attack;
	this->defence = defence;

	type = EType::_Item;
}

bool Item::Use(Entity* target) {
	// ������� �������� ������������ ��������
	if (maxHealth != 0) {
		target->maxHealth += maxHealth;
		if (target->health <= 0) {
			target->isAlive = false;
		}
	}
	// ������� �������� ��������
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
	// ������ / ��������� �����
	if (attack != 0) {
		target->attack = attack;
	}
	// ������ / ��������� ������
	if (defence != 0) {
		target->defence = defence;
	}
	return true;
}