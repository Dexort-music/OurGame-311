#pragma once
#include "Entity.h"
#include "Map.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class Cursor
{
	short x = 0;
	short y = 0;

	HANDLE consoleHandle;
	DWORD a;
public:
	Cursor();
	void Move(char key, Map* map);
	// Отрисовка всей инфы
	void DrawInfo(Map* map, Entity** entities, int eCount);
	// Отрисовка консольного курсора
	void DrawCursor();
	// Отрисовка инфы про точку на карте
	void DrawMapInfo(Map* map);
	// Отрисовка инфы про конкретный entity
	void DrawEntityInfo(Entity* entity, int n);
};