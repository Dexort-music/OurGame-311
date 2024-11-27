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
// ��������� ���� ����
void Cursor::DrawInfo(Map* map, Entity** entities) {

}

// ��������� ����������� �������
void Cursor::DrawCursor() {
	SetConsoleCursorPosition(consoleHandle, { x, y });
}

// ��������� ���� ��� ����� �� �����
void Cursor::DrawMapInfo(Map* map) {
	SetConsoleCursorPosition(consoleHandle, { 0, 15 });

	cout << "===================\n"
		<< "||\t" << map->GetTileName(x, y) << "\t||\n"
		<< "===================\n";
}
// ��������� ���� ��� ���������� entity

void Cursor::DrawEntityInfo(Entity* entity) {

}