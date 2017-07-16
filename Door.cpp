#include "Door.h"

/********************************************
*				Constructors				*
********************************************/
Door::Door() : Square('#', true){
	doorX = 0;
	doorY = 0;
	itemRequired = false;
	itemNeeded = "";
}
//Locked door that requires item
Door::Door(int x, int y, int nRx, int nRy, std::string item) : Square('#', false) {
	doorX = x;
	doorY = y;
	nextRoomX = nRx;
	nextRoomY = nRy;
	itemRequired = true;
	itemNeeded = item;
}
//Unlocked door
Door::Door(int x, int y, int nRx, int nRy) : Square('#', true) {
	doorX = x;
	doorY = y;
	nextRoomX = nRx;
	nextRoomY = nRy;
	itemRequired = false;
	itemNeeded = "";
}

/********************************************
*					Getters					*
********************************************/
int Door::getDoorX() {
	return doorX;
}

int Door::getDoorY() {
	return doorY;
}

int Door::getNextRoomX() {
	return nextRoomX;
}

int Door::getNextRoomY() {
	return nextRoomY;
}

bool Door::isItemRequired() {
	return itemRequired;
}

std::string Door::getItemNeeded() {
	return itemNeeded;
}

/********************************************
*					Setters					*
********************************************/
void Door::setDoorX(int x) {
	doorX = x;
}

void Door::setDoorY(int y) {
	doorY = y;
}

void Door::setNextRoomX(int x) {
	nextRoomX = x;
}

void Door::setNextRoomY(int y) {
	nextRoomY = y;
}

void Door::setItemRequired(bool iR) {
	itemRequired = iR;
}

void Door::setItemNeeded(std::string item) {
	itemNeeded = item;
}

/********************************************
*					Other					*
********************************************/
void Door::getAction() {
	if (reachable) {

	}
}