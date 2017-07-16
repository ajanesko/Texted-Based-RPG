#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "Player.h"

enum input_t { w = 'w', a = 'a', s = 's', d = 'd', x = 'x', e = 'e', not_input };

class Game {
private:
	Map *testRoom;
	Map *testRoom2;
	Map *entryRoom;
	Map *greenRoom;
	Map *idolRoom1;
	Map *idolRoom2;
	Map *yellowRoom1;
	Map *yellowRoom2;
	Map *teleRoom1;
	Map *teleRoom2;
	Map *teleRoom3;
	Map *teleRoom4;
	Map *teleRoom5;
	Map *teleRoom6;
	Map *teleRoom7;
	Map *teleRoom8;
	Map *teleRoom9;
	Map *finalRoom;
	Player *p;
	Map *currentRoom;
	char inventory[3];
	int invenSize;
	bool gameOver = false;
	bool lost = false;
public:
	//Constructor
	Game();
	~Game();
	void createTestRoom();
	void createTestRoom2();
	void createEntryRoom();
	void createGreenRoom();
	void createIdolRoom1();
	void createIdolRoom2();
	void createYellowRoom1();
	void createYellowRoom2();
	void createTeleRoom1();
	void createTeleRoom2();
	void createTeleRoom3();
	void createTeleRoom4();
	void createTeleRoom5();
	void createTeleRoom6();
	void createTeleRoom7();
	void createTeleRoom8();
	void createTeleRoom9();
	void createFinalRoom();
	void displayCurrentRoom();
	void setCurrentRoom(Map*);
	void playerMovement(char);
	char getInput();
	void gamePlay();
	void playerAction();
	void printIntroduction();
	void printControls();
	bool allIdols();
};


#endif