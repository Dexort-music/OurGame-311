#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

void oldMain() {
	int counter = 0;

	// координаты символа #
	int x = 0;
	int y = 0;

	
	int width = 20;
	int height = 20;

	bool isUp = false;

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD a;
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);

	DWORD bufferLength = bufferInfo.srWindow.Right * bufferInfo.srWindow.Bottom;


	while (true) {
		//system("cls");

		// отрисовываем стейт (state) - состояние нашей программы
		//std::cout << counter << "\n";

		//for (size_t i = 0; i < 256; i++)
		//{
		//	if (GetAsyncKeyState(i) & 0x8000) {
		//		std::cout << "\nkey " << i << " pressed!";
		//	}
		//}

		// Если нажата кнопка вверх
		if (GetAsyncKeyState(38) & 0x8000) {
			y--;
		}
		// Если нажата кнопка вниз
		if (GetAsyncKeyState(40) & 0x8000) {
			y++;
		}
		// Если нажата кнопка влево
		if (GetAsyncKeyState(37) & 0x8000) {
			x--;
		}
		// Если нажата кнопка вправо
		if (GetAsyncKeyState(39) & 0x8000) {
			x++;
		}



		//std::cout << bufferInfo.srWindow.Right<< " " << bufferInfo.srWindow.Bottom << "\n";


		//SetConsoleCursorPosition(consoleHandle, { 10,10 });

		// отрисовываем примитивное поле
		/*if (isUp) {
			counter--;
		}
		else {
			counter++;
		}
		if (counter <= 0 || counter >= height - 1) {
			isUp = !isUp;
		}

		for (size_t j = 0; j < height; j++)
		{
			for (size_t i = 0; i < width; i++)
			{
				if (i == 10 && j == counter) {
					std::cout << "**";
				}
				else if (i == x && j == y) {
					std::cout << "##";
				}
				else {
					std::cout << "..";
				}
			}
			std::cout << "\n";
		}*/

		// заполнение консоли
		/*FillConsoleOutputCharacter(consoleHandle, ' ', bufferLength, {0,0}, &a);
		FillConsoleOutputCharacter(consoleHandle, '#', 1, { 10,10 }, &a);*/
		//Sleep(50);

		//char c = _getch();
		//std::cout << c << " was hit";
	}
}

char GetInput() {
	return _getch();
}

int main()
{
	Map* gameMap = new Map();
	
	Player* player = new Player(1, 1, '@', 20, 5, 2);

	int eCount = 3;
	Entity** entities = new Entity*[eCount];
	entities[0] = player;
	entities[1] = new Enemy(6, 4, 'O', 10, 3, 2);
	entities[2] = new Enemy(6, 7, 'O', 10, 3, 2);

	while (true) {
		// ввод
		char key = GetInput();
		//cout << key;

		// игровая логика
		player->Act(key, gameMap, entities, eCount);
		
		for (size_t i = 0; i < eCount; i++)
		{
			if (!entities[i]->isAlive) {
				continue;
			}

			if (entities[i]->type == EType::_AI) {
				((Enemy*)entities[i])->SimpleAI(gameMap, entities, eCount);
			}
		}

		// вывод
		system("cls");
		// отрисовываем карту
		gameMap->Draw();
		
		// рисуем что хотим (пока дебаг)
		for (size_t i = 0; i < eCount; i++)
		{
			cout << "E" << i 
				<< ": HP: " << entities[i]->health 
				<< " IsAlive: " << entities[i]->isAlive 
				<< endl;
		}

		// рисуем entity
		for (size_t i = 0; i < eCount; i++)
		{
			if (entities[i]->isAlive) {
				entities[i]->Draw();
			}
		}

	}
}
