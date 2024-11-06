﻿#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"

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
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);

	DWORD bufferLength = bufferInfo.srWindow.Right * bufferInfo.srWindow.Bottom;

	DWORD a;

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
		/*FillConsoleOutputCharacter(consoleHandle, ' ', bufferLength, { 0,0 }, &a);
		FillConsoleOutputCharacter(consoleHandle, '#', 1, { 10,10 }, &a);*/
		Sleep(50);

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

	while (true) {
		// ввод
		char key = GetInput();
		cout << key;

		// игровой код

		// вывод
		system("cls");
		gameMap->Draw();
	}
}