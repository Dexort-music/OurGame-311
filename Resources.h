#pragma once
#include "Map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void SaveMap(Map* gameMap, const char* file) {
	ofstream outFile(file, ios::out);

	if (!outFile.is_open()) {
		cout << "Can't open file: " << file << "\n";
		int x;
		cin >> x;
		return;
	}
	outFile << "map_name";
	outFile << "\n"; // при считывании читать до \n а не до \0
	outFile << "next_map";
	outFile << "\n";
	outFile << gameMap->width << ' ' << gameMap->height << "\n";
	for (size_t i = 0; i < gameMap->height; i++)
	{
		outFile << gameMap->map[i] << "\n";
	}
	outFile << 1 << ' ' << 1; // старт игрока, поменять это дело
	outFile.close();
}