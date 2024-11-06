#include "Entity.h"

void Entity::Draw() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD a;
	FillConsoleOutputCharacter(consoleHandle, symbol, 1, { x, y }, &a);
}