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

	short health;
	short maxHealth;
	short attack;
	short defence;

	bool isAlive = true;

protected:
	short x;
	short y;
	char symbol;
	HANDLE consoleHandle;
	DWORD a;

public:
	short GetX() { return x; };
	short GetY() { return y; };
	Entity();
	void Draw();
};

