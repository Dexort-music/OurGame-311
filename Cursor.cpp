#include "Cursor.h"

Cursor::Cursor() {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}
void Cursor::Move(char key, Map* map) {
	short ax = x;
	short ay = y;

	if (key == 'w' || key == 'W') {
		ay = y - 1;
	}
	if (key == 's' || key == 'S') {
		ay = y + 1;
	}
	if (key == 'a' || key == 'A') {
		ax = x - 1;
	}
	if (key == 'd' || key == 'D') {
		ax = x + 1;
	}

	if (map->CheckInBounds(ax, ay)) {
		x = ax;
		y = ay;
	}
}
// Отрисовка всей инфы
void Cursor::DrawInfo(Map* map, Entity** entities, int eCount) {
	DrawMapInfo(map);

	int n = 0;
	// понять, для какого entity надо рисовать, если вообще надо
	for (int i = 0; i < eCount; i++) {
		Entity* e = entities[i];
		if (!e->isAlive) {
			continue;
		}
		if (e->GetX() == x && e->GetY() == y) {
			DrawEntityInfo(e, n++);
		}
	}

	DrawCursor();
}

// Отрисовка консольного курсора
void Cursor::DrawCursor() {
	SetConsoleCursorPosition(consoleHandle, { x, y });
}

// Отрисовка инфы про точку на карте
void Cursor::DrawMapInfo(Map* map) {
	SetConsoleCursorPosition(consoleHandle, { 0, 10 });

	cout << "===================\n"
		<< "||\t" << map->GetTileName(x, y) << "\t||\n"
		<< "===================\n";
}
// Отрисовка инфы про конкретный entity

void Cursor::DrawEntityInfo(Entity* entity, int n) {
	short startY = 13;
	short height = 10;
	SetConsoleCursorPosition(consoleHandle, { 0, (short)(startY + height * n) });
	
	/*switch (entity->type) {
	case EType::_AI: cout << "ИИ"; break;
	case EType::_Item: break;
	case EType::_Player: break;
	}*/
	cout << "===================\n";
	cout << entity->GetName() << "\n";
	cout << entity->GetDesc() << "\n";
	
	cout << "Type: ";
	switch(entity->type) {
	case EType::_AI: cout << "AI\n"; break;
	case EType::_Player: cout << "Player\n"; break;
	case EType::_Item: cout << "Item\n"; break;
	}

	if (entity->type == EType::_AI || entity->type == EType::_Player) {
		cout << "HP:  " << entity->health << " / " << entity->maxHealth << "\t\n";
		cout << "ATK: " << entity->attack << "\n";
		cout << "DEF: " << entity->defence << "\n";
	}
	if (entity->type == EType::_Item) {
		if (entity->health != 0) {
			cout << "HP:  " << entity->health << "\n";
		}
		if (entity->maxHealth != 0) {
			cout << "MHP: " << entity->maxHealth << "\n";
		}
		if (entity->attack != 0) {
			cout << "ATK: " << entity->attack << "\n";
		}
		if (entity->defence != 0) {
			cout << "DEF: " << entity->defence << "\n";
		}
	}

	cout << "===================\n";
}