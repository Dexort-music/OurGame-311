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

	// если мы вне границ, то возвращаем истину - мы нашли столкновение
	if (!CheckInBounds(x, y)) {
		return true;
	}
	return map[y][x] == '#' || map[y][x] == '|';
}

bool Map::CheckExit(int x, int y) {
	// если мы вне границ, то там нет никакого выхода
	if (!CheckInBounds(x, y)) {
		return false;
	}
	return map[y][x] == ']';
}

bool Map::CheckInBounds(int x, int y) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		return false;
	}
	return true;

	//return (x < 0 || x >= width || y < 0 || y >= height) ? false : true;
}

string Map::GetTileName(int x, int y) {
	if (!CheckInBounds(x, y)) {
		return "";
	}

	switch (map[y][x])
	{
	case '.': return "Ground";
	case '#': return "Wall";
	case 'v': return "Bush";
	case ']':
	case '[': return "Exit";
	default:
		return "";
	}
}