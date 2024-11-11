#include "Entity.h"

Entity::Entity() {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Entity::Draw() {
	FillConsoleOutputCharacter(consoleHandle, symbol, 1, { x, y }, &a);
}