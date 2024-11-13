#include "Player.h"

Player::Player(short x, short y, char symbol, short health, short attack, short defence) {
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	type = EType::_Player;

	this->health = health;
	this->attack = attack;
	this->defence = defence;
}

void Player::Act(char key, Map* map, Entity** entities, int eCount) {
	short ax = 0;
	short ay = 0;

	bool acted = false;
	
	// ������, ���� ����� �����������
	if (key == 'w' || key == 'W') {
		ax = x;
		ay = y - 1;
	}
	if (key == 's' || key == 'S') {
		ax = x;
		ay = y + 1;
	}
	if (key == 'a' || key == 'A') {
		ax = x - 1;
		ay = y;
	}
	if (key == 'd' || key == 'D') {
		ax = x + 1;
		ay = y;
	}

	// ���������, ���� �� entity � ��� �����...
	for (size_t i = 0; i < eCount; i++)
	{
		Entity* target = entities[i];
		if (!target->isAlive) {
			continue;
		}

		if (target->GetX() == ax && target->GetY() == ay) {
			// ���� �� ���� ������ ���-�� ���� � ��� ��
			if (target->type == EType::_AI) {
				short damage = attack - target->defence;
				target->health -= damage;

				if (target->health <= 0) {
					target->isAlive = false;
					//delete target; ��� �������� ������ � ��� ��� �� �������
				}
				acted = true;
			}
			// �����, ���� �� ������ �������
			else if (target->type == EType::_Item) {

			}
		}
	}

	// ��������� �����, � �������� ����
	if (acted) {
		// ���� �� �������� �� �����, ��� ���-�� ��� ��������
		return;
	}
	if (!map->CheckCollision(ax, ay)) {
		// ���� ����� � ax ay �� ����� ��������, �� ���� ����
		x = ax;
		y = ay;
	}
}