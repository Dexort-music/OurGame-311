#pragma once
#include "Map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

wstring GetExecutablePath() {
	wchar_t buffer[MAX_PATH];
	GetModuleFileNameW(NULL, buffer, MAX_PATH);
	wstring path(buffer);
	return path.substr(0, path.find_last_of(L"\\/"));
}

void SaveMap(Map* gameMap, string mapName) {
	wstring wmapName(mapName.begin(), mapName.end());
	ofstream outFile(GetExecutablePath() + L"/maps/" + wmapName + L".map", ios::out);

	if (!outFile.is_open()) {
		wcout << L"Can't open file: " + wmapName + L".map\n";
		int x;
		cin >> x;
		return;
	}
	outFile << gameMap->GetName();
	outFile << "\n"; // при считывании читать до \n а не до \0
	outFile << gameMap->GetNextMapFileName();
	outFile << "\n";
	outFile << gameMap->GetWidth() << ' ' << gameMap->GetHeight()<< "\n";
	for (size_t i = 0; i < gameMap->GetHeight(); i++)
	{
		outFile << gameMap->GetMap()[i] << "\n";
	}
	outFile << gameMap->GetStartX() << ' ' << gameMap->GetStartY(); // старт игрока, поменять это дело
	outFile.close();
}

Map* LoadMap(string mapName) {
	wstring wmapName(mapName.begin(), mapName.end());
	ifstream inFile(GetExecutablePath() + L"/maps/" + wmapName + L".map", ios::in);
	if (!inFile.is_open()) {
		wcout << L"Can't open file: " + wmapName + L".map\n";
		int x;
		cin >> x;
		return nullptr;
	}
	string name;
	string nextMapFileName;
	int width;
	int height;
	string* map;
	short startX;
	short startY;

	getline(inFile, name, '\n');
	getline(inFile, nextMapFileName, '\n');
	inFile >> width >> height;
	inFile.ignore(1);
	map = new string[height];
	for (size_t i = 0; i < height; i++)
	{
		getline(inFile, map[i], '\n');
	}
	inFile >> startX >> startY;
	return new Map(width, height, map, name, nextMapFileName, startX, startY);
}

Entity* LoadEntity(string entityName) {
	wstring wentityName(entityName.begin(), entityName.end());
	ifstream inFile(GetExecutablePath() + L"/entities/" + wentityName + L".ent", ios::in);
	if (!inFile.is_open()) {
		wcout << L"Can't open file: " + wentityName + L".ent\n";
		int x;
		cin >> x;
		return nullptr;
	}
	int type;
	string name;
	string desc;
	char symbol;
	short x, y;
	short health, maxHealth, attack, defence;

	inFile >> type;
	inFile.ignore(1);
	getline(inFile, name, '\n');
	getline(inFile, desc, '\n');
	inFile >> symbol;
	inFile >> x >> y;
	if (type == EType::_Player) {
		inFile >> health >> attack >> defence;
		return new Player(x, y, symbol, health, attack, defence, name, desc);
	}
	else if (type == EType::_AI) {
		inFile >> health >> attack >> defence;
		return new Enemy(x, y, symbol, health, attack, defence, name, desc);
	}
	else if (type == EType::_Item) {
		inFile >> health >> maxHealth >> attack >> defence;
		return new Item(x, y, symbol, health, maxHealth, attack, defence, name, desc);
	}
	else {
		return new Entity();
	}

}