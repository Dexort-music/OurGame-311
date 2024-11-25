#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

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

	string name;
	string desc;

public:
	short GetX() { return x; };
	short GetY() { return y; };
	string GetName() { return name; };
	string GetDesc() { return desc; };
	Entity();
	Entity(short x, short y, char symbol, short health, short attack, short defence, string name, string desc);
	void Draw();
};

