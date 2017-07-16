#ifndef DOOR_H
#define DOOR_H

#include <iostream>
#include <string>

#include "Square.h"

class Door : public Square {
private:
	int doorX,
		doorY,
		nextRoomX,
		nextRoomY;
	bool itemRequired;
	std::string itemNeeded;
public:
	//Constructors
	Door();
	Door(int, int, int, int, std::string);		//Locked door that requires item
	Door(int, int, int, int);					//Unlocked door
	//Getters
	int getDoorX();
	int getDoorY();
	int getNextRoomX();
	int getNextRoomY();
	bool isItemRequired();
	std::string getItemNeeded();
	//Setters
	void setDoorX(int);
	void setDoorY(int);
	void setNextRoomX(int);
	void setNextRoomY(int);
	void setItemRequired(bool);
	void setItemNeeded(std::string);
	//Other
	void getAction();
};

#endif