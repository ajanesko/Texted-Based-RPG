#include "Player.h"


/********************************************
*				Constructors				*
********************************************/
Player::Player() {
	playerLocation = NULL;
	playerX = 0;
	playerY = 0;
	health = 0;
}

Player::Player(Map* m, int x, int y, int h) {
	playerLocation = m;
	playerX = x;
	playerY = y;
	health = h;
}

/********************************************
*					Getters					*
********************************************/
int Player::getPlayerX() {
	return playerX;
}

int Player::getPlayerY() {
	return playerY;
}

int Player::getPlayerHealth() {
	return health;
}

Map* Player::getPlayerLocation() {
	return playerLocation;
}

/********************************************
*					Setters					*
********************************************/

void Player::setPlayerX(int x) {
	playerX = x;
}

void Player::setPlayerY(int y) {
	playerY = y;
}

void Player::setPlayerHealth(int h) {
	health = h;
}

void Player::setPlayerLocation(Map* m) {
	playerLocation = m;
}