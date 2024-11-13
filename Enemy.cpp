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

	bool acted = false;

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
	// попытатьс€ атаковать клетку
	// удалим его потом
	for (size_t i = 0; i < eCount; i++)
	{
		Entity* target = entities[i];
		if (!target->isAlive) {
			continue;
		}

		if (target->GetX() == ax && target->GetY() == ay) {
			// если на этой клетке кто-то есть и это »»
			if (target->type == EType::_Player) {
				short damage = attack - target->defence;
				target->health -= damage;

				if (target->health <= 0) {
					target->isAlive = false;
					//delete target; это довольно сложно и дл€ нас не выгодно
				}
				acted = true;
			}
			// »наче, если на клетке предмет
			else if (target->type == EType::_Item) {

			}
		}
	}

	// посмотреть, есть ли р€дом игрок, и атаковать его
	for (size_t i = 0; i < eCount; i++)
	{
		Entity* target = entities[i];
		if (target->type != EType::_Player) {
			continue;
		}
		short tx = target->GetX();
		short ty = target->GetY();
		// ≈сли мы стоим в одной клетке по вертикали или горизонтали
		if (	(y == ty && abs(x - tx) <= 2) 
			||	(x == tx && abs(y - ty) <= 2)	) {
			short damage = attack - target->defence;
			target->health -= damage;
			if (target->health <= 0) {
				target->isAlive = false;
			}
			acted = true;
		}
	}

	// попытатьс€ переместитьс€
	if (acted) {
		return;
	}
	if (!map->CheckCollision(ax, ay)) {
		x = ax;
		y = ay;
	}
}