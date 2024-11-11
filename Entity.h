#pragma once
#include <Windows.h>

enum EType {
	_AI,
	_Player,
	_Item
};

class Entity
{
public:
	EType type;

protected:
	short x;
	short y;
	char symbol;
	HANDLE consoleHandle;
	DWORD a;

	short health;
	short attack;
	short defence;
public:
	Entity();
	void Draw();
};

