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
	// ��������� ���� ����
	void DrawInfo(Map* map, Entity** entities, int eCount);
	// ��������� ����������� �������
	void DrawCursor();
	// ��������� ���� ��� ����� �� �����
	void DrawMapInfo(Map* map);
	// ��������� ���� ��� ���������� entity
	void DrawEntityInfo(Entity* entity, int n);
};