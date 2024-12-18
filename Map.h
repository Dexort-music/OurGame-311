#pragma once
#include <iostream>
#include <string>

using namespace std;

class Map
{
	int width = 20;
	int height = 10;
	string* map;
	string name;
	string nextMapFileName;
	short startX = 1;
	short startY = 1;

public:
	Map();
	Map(int width, int height, string* map, string name, string nextMapFileName, short startX, short startY);
	void Draw();
	bool CheckCollision(int x, int y);
	bool CheckExit(int x, int y);
	bool CheckInBounds(int x, int y);
	string GetTileName(int x, int y);

	// getters
	int GetWidth() { return width; };
	int GetHeight() { return height; };
	string* GetMap() { return map; };
	string GetName() { return name; };
	string GetNextMapFileName() { return nextMapFileName; };
	short GetStartX() { return startX; };
	short GetStartY() { return startY; };
};