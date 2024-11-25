#include "Map.h"

Map::Map() {
	map = new string[height]{
		"##################",
		"#...#....#.#.....#",
		"#...#......#.....#",
		"##.##....#.#.....#",
		"#........#.####.##",
		"#..v.....#.#.....#",
		"#....vv..#.#.....#",
		"#........#.......#",
		"#...vv...#.......]",
		"##################"
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
	if (x < 0 || x >= width || y < 0 || y >= height) {
		return true;
	}
	return map[y][x] == '#' || map[y][x] == '|';
}

bool Map::CheckExit(int x, int y) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		return false;
	}
	return map[y][x] == ']';
}