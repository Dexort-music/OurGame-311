#include "Map.h"

Map::Map() {
	map = new string[height]{
		"#########",
		"#..|....#",
		"#..#.#..#",
		"#....#..#",
		"#########"
	};
}

void Map::Draw() {
	for (size_t i = 0; i < height; i++)
	{
		cout << map[i] << endl;
	}
}

bool Map::CheckCollision(int x, int y) {
	/*switch (map[y][x])
	{
	case '#': 
	case '|':
		return true;
	}
	return false;*/


	// возвращаем тру, если есть стенка
	if (map[y][x] == '#' || map[y][x] == '|') {
		return true;
	}
	return false;
}