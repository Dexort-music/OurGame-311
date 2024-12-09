#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "ItemFactory.h"
#include "Cursor.h"

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

enum GameMode {
	_Game,
	_Cursor
};

char GetInput() {
	return _getch();
}

/// <summary>
/// TODO:
/// 
/// 1) Перевести все на расширенные символы
///		1.1) узнать про wchar - wchar_t = 16 бит, 2 байта
///		1.2) wstring 
///		1.3) поменять char на wchar_t
///		1.4) что делать с cout?
/// 
/// 2) Меню
/// 3) Загрузка уровней из файлов
/// 
/// </summary>
/// <returns></returns>

int main()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	Map* gameMap = new Map();
	
	Player* player = new Player(1, 1, '@', 40, 5, 2, "Hero", "Brave knigth of 9'th kingdom");
	int eCount = 7;
	Entity** entities = new Entity*[eCount];
	entities[0] = player;
	entities[1] = new Enemy(6, 4, 'O', 10, 3, 2, "Zombie", "Rotten abomination");
	entities[2] = new Enemy(6, 4, 'O', 10, 3, 2, "Big Zombie", "Big rotten abomination");
	entities[3] = ItemFactory::CreateGenericMedkit(6, 1, 2, "Medpack", "Restores 2hp");
	entities[4] = new Item(10, 8, '!', 0, 0, 7, 0, "Great Sword", "Sword made by Zeus");
	entities[5] = ItemFactory::CreateMedkit(16, 2);
	entities[6] = ItemFactory::CreateHealthBonus(16, 7, 3);
	//entities[7] = new Item(10, 11, 'X', 0, 1, 0, 0);

	GameMode gameMode = GameMode::_Game;

	Cursor* cursor = new Cursor();

	while (true) {
		// вывод
		// очищаем консоль
		system("cls");

		// отрисовываем карту
		gameMap->Draw();

		if (gameMode == GameMode::_Cursor) {
			cursor->DrawInfo(gameMap, entities, eCount);
			//cursor->DrawMapInfo(gameMap);
			//cursor->DrawCursor();
		}

		// рисуем entity
		for (size_t i = 0; i < eCount; i++)
		{
			if (entities[i]->isAlive) {
				entities[i]->Draw();
			}
		}

		// временное решение. Условия проигрыша
		if (!player->isAlive) {
			Sleep(2000);
			system("cls");
			cout << "\n\n\t\t\tYou Lose!\n";
			break;
		}

		bool won = false;
		// условия победы
		for (size_t i = 0; i < eCount; i++)
		{
			Entity* e = entities[i];
			if (e->type == EType::_AI) {
				if (e->isAlive) {
					// Если есть живой враг, выходим из цикла
					won = false;
					break;
				}
				// Если мы сюда дошли, значит ни одного живого врага нет
				won = true;
			}
		}

		if (gameMap->CheckExit(player->GetX(), player->GetY())) {
			won = true;
		}

		// код победного экрана
		if (won) {
			Sleep(2000);
			system("cls");
			cout << "\n\n\t\t\tCongratulations!\n";
			break;
		}

		// ввод
		char key = GetInput();

		// проверяем, не хотим ли мы поменять режим игры
		if (key == 'i' || key == 'I') {
			if (gameMode == GameMode::_Game) {
				gameMode = GameMode::_Cursor;
			} else if (gameMode == GameMode::_Cursor) {
				gameMode = GameMode::_Game;
			}
			// если я поменял режим, то в этот раз хочу пропустить логику
			continue;
		}

		// игровая логика
		if (gameMode == GameMode::_Game) {
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
		}
		else if (gameMode == GameMode::_Cursor) {
			// логика режима курсора
			cursor->Move(key, gameMap);
		}
	}
}