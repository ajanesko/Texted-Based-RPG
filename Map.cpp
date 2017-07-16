#include "Map.h"

/********************************************
*				Constructors				*
********************************************/
Map::Map() {
	length = 0;
	width = 0;
	roomName = "";
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

Map::Map(int l, int w, std::string name) {
	length = l;
	width = w;
	roomName = name;
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

Map::~Map() {
	for (int row = 0; row < length; row++) {
		for (int col = 0; col < width; col++) {
			delete map[row][col];
		}
		delete[] map[row];
	}
	delete[] map;
}

/********************************************
*					Getters					*
********************************************/
Square*** Map::getMap() {
	return map;
}

int Map::getLength() {
	return length;
}

int Map::getWidth() {
	return width;
}

std::string Map::getRoomName() {
	return roomName;
}

Map *Map::getNorth() {
	return north;
}

Map *Map::getEast() {
	return east;
}

Map *Map::getSouth() {
	return south;
}

Map *Map::getWest() {
	return west;
}
Map *Map::getNorth2() {
	return north2;
}

/********************************************
*					Setters					*
********************************************/
void Map::setMap(Square*** m) {
	map = m;
}

void Map::setLength(int l) {
	length = l;
}

void Map::setWidth(int w) {
	width = w;
}

void Map::setRoomName(std::string name) {
	roomName = name;
}

void Map::setNorth(Map *n) {
	north = n;
}

void Map::setEast(Map *e) {
	east = e;
}

void Map::setSouth(Map *s) {
	south = s;
}

void Map::setWest(Map *w) {
	west = w;
}

void Map::setNorth2(Map *n2) {
	north2 = n2;
}

/********************************************
*					Other					*
********************************************/
void Map::mapCreation() {
	//Create map
	map = new Square**[length];
	for (int i = 0; i < length; i++) {
		map[i] = new Square*[width];
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == length - 1 || j == 0 || j == width - 1) {
				map[i][j] = new Wall;
			}
			else {
				map[i][j] = new Floor;
			}
		}
	}
}

void Map::testDisplay() {
	for (int row = 0; row < length; row++) {
		for (int col = 0; col < width; col++) {
			std::cout << map[row][col]->getSymbol() << ' ';
		}
		std::cout << '\n';
	}
}

void Map::placeDoor(int x, int y) {
	delete map[x][y];
	map[x][y] = new Door();
}

void Map::placeTeleporter(int x, int y) {
	delete map[x][y];
	map[x][y] = new Teleporter();
}

void Map::placeItem(int x, int y, char symbol, std::string name) {
	delete map[x][y];
	map[x][y] = new Item(symbol, name);
}


void Map::placeScenery(int x, int y, char symbol) {
	delete map[x][y];
	map[x][y] = new Scenery(symbol);
}
