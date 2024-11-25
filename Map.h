#pragma once
#include <iostream>
#include <string>

using namespace std;

class Map
{
	int width = 20;
	int height = 10;
	string* map;

public:
	Map();
	void Draw();
	bool CheckCollision(int x, int y);
	bool CheckExit(int x, int y);
};