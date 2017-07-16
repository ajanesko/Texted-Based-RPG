#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Map.h"

class Player {
private:
	int playerX,
		playerY,
		health;
	Map *playerLocation;
public:
	//Constructors
	Player();
	Player(Map*, int, int, int);
	//Getters
	int getPlayerX();
	int getPlayerY();
	int getPlayerHealth();
	Map* getPlayerLocation();
	//Setters
	void setPlayerX(int);
	void setPlayerY(int);
	void setPlayerHealth(int);
	void setPlayerLocation(Map*);
};

#endif