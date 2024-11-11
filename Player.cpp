#include "Player.h"

Player::Player(short x, short y, char symbol) {
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	type = EType::_Player;
}

void Player::Act(char key, Map* map, Entity** entities, int eCount) {
	short ax = 0;
	short ay = 0;
	
	// поняли, куда хотим действовать
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

	// проверяем, есть ли entity в том месте...

	// проверяем карту, и пытаемся идти
	if (!map->CheckCollision(ax, ay)) {
		// если место в ax ay на карте свободно, то идем туда
		x = ax;
		y = ay;
	}
}