#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

#include "Square.h"
#include "Wall.h"
#include "Floor.h"
#include "Door.h"
#include "Teleporter.h"
#include "Item.h"
#include "Scenery.h"

class Map {
private: 
	Square ***map;
	int length,
		width;
	std::string roomName;
	Map *north;
	Map *north2;
	Map *east;
	Map *south;
	Map *west;
public:
	//Constructors
	Map();
	Map(int, int, std::string);
	~Map();
	//Getters
	Square*** getMap();
	int getLength();
	int getWidth();
	std::string getRoomName();
	Map *getNorth();
	Map *getNorth2();
	Map *getEast();
	Map *getSouth();
	Map *getWest();
	//Setters
	void setMap(Square***);
	void setLength(int);
	void setWidth(int);
	void setRoomName(std::string);
	void setNorth(Map *n);
	void setNorth2(Map *n);
	void setEast(Map *e);
	void setSouth(Map *s);
	void setWest(Map *w);
	//Other
	void mapCreation();
	void testDisplay();
	void placeDoor(int, int);
	void placeTeleporter(int, int);
	void placeItem(int, int, char, std::string);
	void placeScenery(int, int, char);
};

#endif