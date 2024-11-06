#pragma once
#include <iostream>
#include <string>

using namespace std;

class Map
{
	int width = 10;
	int height = 5;
	string* map;

public:
	Map();
	void Draw();
	bool CheckCollision(int x, int y);
};

