#include "Enemy.h"

Enemy::Enemy(short x, short y, char symbol, short health, short attack, short defence) {
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	this->health = health;
	this->attack = attack;
	this->defence = defence;
	type = EType::_AI;
}

void Enemy::SimpleAI(Map* map, Entity** entities, int eCount) {
	short ax = x;
	short ay = y;

	int r = rand() % 5;
	if (r == 0) {
		ay = y - 1;
	}
	if (r == 1) {
		ay = y + 1;
	}
	if (r == 2) {
		ax = x - 1;
	}
	if (r == 3) {
		ax = x + 1;
	}

	// попытаться атаковать клетку

	// попытаться переместиться
	if (!map->CheckCollision(ax, ay)) {
		x = ax;
		y = ay;
	}
}