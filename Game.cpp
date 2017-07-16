#include "Game.h"

Game::Game() {
	//CREATE ROOMS
	//Test Rooms
	createTestRoom();
	createTestRoom2();
	//Entry Rooms
	createEntryRoom();
	createGreenRoom();
	//Item Rooms
	createIdolRoom1();
	createIdolRoom2();
	//Beginning Teleporter Rooms
	createYellowRoom1();
	createYellowRoom2();
	//Teleporter Rooms
	createTeleRoom1();
	createTeleRoom2();
	createTeleRoom3();
	createTeleRoom4();
	createTeleRoom5();
	createTeleRoom6();
	createTeleRoom7();
	createTeleRoom8();
	createTeleRoom9();
	//Final Room
	createFinalRoom();

	p = new Player(entryRoom, 7, 9, 500);
//	p = new Player(yellowRoom1, 7, 14, 200);
	for (int i = 0; i < invenSize; i++) {
		inventory[i] = '_';
	}
	//ROOM LAYOUT
	testRoom->setNorth(testRoom2);
	testRoom2->setNorth(greenRoom);
	//Idol Room 1
	idolRoom1->setEast(greenRoom);
	//Idol Room 2
	idolRoom2->setWest(greenRoom);
	//Green Room
	greenRoom->setEast(idolRoom2);
	greenRoom->setSouth(entryRoom);
	greenRoom->setNorth(yellowRoom1);
	greenRoom->setNorth2(yellowRoom2);
	greenRoom->setWest(idolRoom1);
	//Entry Room
	entryRoom->setNorth(greenRoom);
	//Yellow Room 1
	yellowRoom1->setNorth(teleRoom7);
	yellowRoom1->setSouth(greenRoom);
	//Yellow Room 2
	yellowRoom2->setNorth(teleRoom9);
	yellowRoom2->setSouth(greenRoom);
	//Teleporter Room 1
	teleRoom1->setNorth(teleRoom3);
	teleRoom1->setWest(greenRoom);
	//Teleporter Room 2
	teleRoom2->setNorth(finalRoom);
	//Teleporter Room 3
	teleRoom3->setEast(greenRoom);
	teleRoom3->setWest(teleRoom2);
	//Teleporter Room 4
	teleRoom4->setEast(teleRoom5);
	teleRoom4->setWest(greenRoom);
	//Teleporter Room 5
	teleRoom5->setNorth(teleRoom1);
	teleRoom5->setSouth(teleRoom8);
	//Teleporter Room 6
	teleRoom6->setWest(teleRoom5);
	//Teleporter Room 7
	teleRoom7->setNorth(teleRoom4);
	//Teleporter Room 8
	teleRoom8->setSouth(greenRoom);
	//Teleporter Room 9
	teleRoom9->setNorth(teleRoom6);
	teleRoom9->setWest(teleRoom8);
}

Game::~Game() {
	delete entryRoom;
	delete greenRoom;
	delete idolRoom1;
	delete idolRoom2;
	delete yellowRoom1;
	delete yellowRoom2;
	delete teleRoom1;
	delete teleRoom2;
	delete teleRoom3;
	delete teleRoom4;
	delete teleRoom5;
	delete teleRoom6;
	delete teleRoom7;
	delete teleRoom8;
	delete teleRoom9;
	delete finalRoom;
	delete currentRoom;
}

void Game::createTestRoom() {
	testRoom = new Map(11, 11, "Test Room");

	testRoom->mapCreation();
	testRoom->placeDoor(1, 4);
	testRoom->placeTeleporter(4, 4);
	testRoom->placeItem(2, 2, '!', "Key 1");
	testRoom->placeItem(5, 5, '&', "Key 2");
	testRoom->placeItem(6, 6, '$', "Key 3");
	testRoom->placeScenery(1, 9, '<');
	testRoom->placeScenery(2, 9, '<');
	testRoom->placeScenery(3, 9, '<');
}

void Game::createTestRoom2() {
	testRoom2 = new Map(15, 15, "Test Room2");

	testRoom2->mapCreation();
	testRoom2->placeDoor(1, 4);
}

void Game::createEntryRoom() {
	entryRoom = new Map(9, 19, "Entry Room");
	entryRoom->mapCreation();
	//Door
	entryRoom->placeDoor(1, 9);
	//Scenery
	entryRoom->placeScenery(1, 1, '=');
	entryRoom->placeScenery(1, 2, '=');
	entryRoom->placeScenery(1, 3, '=');
	entryRoom->placeScenery(1, 4, '=');
	entryRoom->placeScenery(2, 2, '=');
	entryRoom->placeScenery(3, 1, '=');
	entryRoom->placeScenery(2, 1, '=');
	entryRoom->placeScenery(4, 1, '=');
	entryRoom->placeScenery(5, 1, '=');
	entryRoom->placeScenery(6, 1, '=');
	entryRoom->placeScenery(7, 1, '=');
	entryRoom->placeScenery(7, 2, '=');
	entryRoom->placeScenery(7, 3, '=');
	entryRoom->placeScenery(6, 2, '=');
	entryRoom->placeScenery(7, 4, '=');
	entryRoom->placeScenery(1, 14, '=');
	entryRoom->placeScenery(1, 15, '=');
	entryRoom->placeScenery(1, 16, '=');
	entryRoom->placeScenery(1, 17, '=');
	entryRoom->placeScenery(2, 17, '=');
	entryRoom->placeScenery(3, 17, '=');
	entryRoom->placeScenery(4, 17, '=');
	entryRoom->placeScenery(5, 17, '=');
	entryRoom->placeScenery(6, 17, '=');
	entryRoom->placeScenery(7, 17, '=');
	entryRoom->placeScenery(7, 16, '=');
	entryRoom->placeScenery(7, 15, '=');
	entryRoom->placeScenery(7, 14, '=');
	entryRoom->placeScenery(2, 16, '=');
	entryRoom->placeScenery(6, 16, '=');
}

void Game::createGreenRoom() {
	greenRoom = new Map(14, 29, "Green Room");
	greenRoom->mapCreation();
	//Side doors
	greenRoom->placeDoor(4, 1);		//left
	greenRoom->placeDoor(4, 27);	//right
	//Top doors
	greenRoom->placeDoor(1, 24);	//right
	greenRoom->placeDoor(1, 4);		//left
	//Bottom door
	greenRoom->placeDoor(12, 14);
	//Scenery
	for (int i = 1; i < 6; i++) {
		greenRoom->placeScenery(i, 14, '~');
	}
	for (int i = 2; i < 27; i++) {
		greenRoom->placeScenery(6, i, '~');
	}
	for (int i = 6; i < 12; i++) {
		greenRoom->placeScenery(i, 2, '~');
	}
	for (int i = 6; i < 12; i++) {
		greenRoom->placeScenery(i, 26, '~');
	}
	for (int i = 1; i < 13; i++) {
		greenRoom->placeScenery(2, i, '~');
	}
	for (int i = 16; i < 28; i++) {
		greenRoom->placeScenery(2, i, '~');
	}
}

void Game::createIdolRoom1() {
	idolRoom1 = new Map(14, 11, "Idol Room");
	idolRoom1->mapCreation();
	//Side door
	idolRoom1->placeDoor(4, 9);
	idolRoom1->placeItem(12, 5, '!', "Key 1");
}

void Game::createIdolRoom2() {
	idolRoom2 = new Map(14, 11, "Idol Room");
	idolRoom2->mapCreation();
	//Side door
	idolRoom2->placeDoor(4, 1);
	idolRoom2->placeItem(12, 5, '&', "Key 2");
}

void Game::createYellowRoom1() {
	yellowRoom1 = new Map(14, 19, "Yellow Room");
	yellowRoom1->mapCreation();
	//Door
	yellowRoom1->placeDoor(12, 14);
	//Teleporter
	yellowRoom1->placeTeleporter(1, 9);
}

void Game::createYellowRoom2() {
	yellowRoom2 = new Map(14, 19, "Yellow Room");
	yellowRoom2->mapCreation();
	//Door
	yellowRoom2->placeDoor(12, 4);
	//Teleporter
	yellowRoom2->placeTeleporter(1, 9);
}

void Game::createTeleRoom1() {
	teleRoom1 = new Map(9, 9, "Blue Rooms");
	teleRoom1->mapCreation();
	//Teleporters
	teleRoom1->placeTeleporter(4, 1);
	teleRoom1->placeTeleporter(1, 4);
	//Scenery
	teleRoom1->placeScenery(7, 7, '=');
	teleRoom1->placeScenery(7, 6, '=');
	teleRoom1->placeScenery(7, 5, '=');
	teleRoom1->placeScenery(6, 6, '=');
	teleRoom1->placeScenery(6, 7, '=');
	teleRoom1->placeScenery(5, 7, '=');
	teleRoom1->placeScenery(1, 3, '^');
	teleRoom1->placeScenery(2, 3, '^');
	teleRoom1->placeScenery(3, 3, '^');
	teleRoom1->placeScenery(1, 2, '^');
	teleRoom1->placeScenery(2, 2, '^');
	teleRoom1->placeScenery(3, 2, '^');
	teleRoom1->placeScenery(1, 1, '^');
	teleRoom1->placeScenery(2, 1, '^');
	teleRoom1->placeScenery(3, 1, '^');
	teleRoom1->placeScenery(4, 3, '^');
	teleRoom1->placeScenery(5, 3, '^');
	teleRoom1->placeScenery(6, 3, '^');
	teleRoom1->placeScenery(4, 2, '^');
	teleRoom1->placeScenery(5, 2, '^');
	teleRoom1->placeScenery(6, 2, '^');
	teleRoom1->placeScenery(2, 4, '^');
	teleRoom1->placeScenery(2, 5, '^');
	teleRoom1->placeScenery(2, 6, '^');
	teleRoom1->placeScenery(3, 4, '^');
	teleRoom1->placeScenery(3, 5, '^');
	teleRoom1->placeScenery(3, 6, '^');
}

void Game::createTeleRoom2() {
	teleRoom2 = new Map(9, 9, "Blue Rooms");
	teleRoom2->mapCreation();
	//Door
	teleRoom2->placeDoor(1, 4);
	//Scenery
	teleRoom2->placeScenery(1, 5, '=');
	teleRoom2->placeScenery(1, 6, '=');
	teleRoom2->placeScenery(1, 7, '=');
	teleRoom2->placeScenery(2, 2, '=');
	teleRoom2->placeScenery(2, 3, '=');
	teleRoom2->placeScenery(2, 4, '=');
	teleRoom2->placeScenery(2, 5, '=');
	teleRoom2->placeScenery(2, 6, '=');
	teleRoom2->placeScenery(2, 7, '=');
	teleRoom2->placeScenery(3, 2, '=');
	teleRoom2->placeScenery(3, 3, '=');
	teleRoom2->placeScenery(4, 2, '=');
	teleRoom2->placeScenery(4, 3, '=');
	teleRoom2->placeScenery(4, 5, '=');
	teleRoom2->placeScenery(4, 6, '=');
	teleRoom2->placeScenery(5, 2, '=');
	teleRoom2->placeScenery(5, 3, '=');
	teleRoom2->placeScenery(5, 4, '=');
	teleRoom2->placeScenery(5, 5, '=');
	teleRoom2->placeScenery(5, 6, '=');
	teleRoom2->placeScenery(6, 2, '=');
	teleRoom2->placeScenery(6, 3, '=');
	teleRoom2->placeScenery(6, 4, '=');
	teleRoom2->placeScenery(6, 5, '=');
	teleRoom2->placeScenery(6, 6, '=');
}

void Game::createTeleRoom3() {
	teleRoom3 = new Map(9, 9, "Blue Rooms");
	teleRoom3->mapCreation();
	//Teleporters
	teleRoom3->placeTeleporter(4, 7);
	teleRoom3->placeTeleporter(4, 1);
	//Scenery
	teleRoom3->placeScenery(2, 2, '=');
	teleRoom3->placeScenery(2, 3, '=');
	teleRoom3->placeScenery(3, 2, '=');
	teleRoom3->placeScenery(3, 3, '=');
	teleRoom3->placeScenery(4, 2, '=');
	teleRoom3->placeScenery(4, 3, '=');
	teleRoom3->placeScenery(5, 1, '=');
	teleRoom3->placeScenery(5, 2, '=');
	teleRoom3->placeScenery(5, 3, '=');
	teleRoom3->placeScenery(6, 1, '=');
	teleRoom3->placeScenery(6, 2, '=');
	teleRoom3->placeScenery(6, 3, '=');
	teleRoom3->placeScenery(7, 1, '=');
	teleRoom3->placeScenery(7, 2, '=');
	teleRoom3->placeScenery(7, 3, '=');
	teleRoom3->placeScenery(1, 5, '^');
	teleRoom3->placeScenery(1, 6, '^');
	teleRoom3->placeScenery(1, 7, '^');
	teleRoom3->placeScenery(2, 5, '^');
	teleRoom3->placeScenery(2, 6, '^');
	teleRoom3->placeScenery(2, 7, '^');
	teleRoom3->placeScenery(3, 5, '^');
	teleRoom3->placeScenery(3, 6, '^');
	teleRoom3->placeScenery(3, 7, '^');
	teleRoom3->placeScenery(4, 5, '^');
	teleRoom3->placeScenery(4, 6, '^');
	teleRoom3->placeScenery(5, 5, '^');
	teleRoom3->placeScenery(5, 6, '^');
	teleRoom3->placeScenery(6, 5, '^');
	teleRoom3->placeScenery(6, 6, '^');
}

void Game::createTeleRoom4() {
	teleRoom4 = new Map(9, 9, "Blue Rooms");
	teleRoom4->mapCreation();
	//Teleporters
	teleRoom4->placeTeleporter(4, 7);
	teleRoom4->placeTeleporter(4, 1);
	//Scenery
	teleRoom4->placeScenery(2, 2, '=');
	teleRoom4->placeScenery(2, 3, '=');
	teleRoom4->placeScenery(3, 2, '=');
	teleRoom4->placeScenery(3, 3, '=');
	teleRoom4->placeScenery(4, 2, '=');
	teleRoom4->placeScenery(4, 3, '=');
	teleRoom4->placeScenery(5, 1, '=');
	teleRoom4->placeScenery(5, 2, '=');
	teleRoom4->placeScenery(5, 3, '=');
	teleRoom4->placeScenery(6, 1, '=');
	teleRoom4->placeScenery(6, 2, '=');
	teleRoom4->placeScenery(6, 3, '=');
	teleRoom4->placeScenery(7, 1, '=');
	teleRoom4->placeScenery(7, 2, '=');
	teleRoom4->placeScenery(7, 3, '=');
	teleRoom4->placeScenery(1, 5, '^');
	teleRoom4->placeScenery(1, 6, '^');
	teleRoom4->placeScenery(1, 7, '^');
	teleRoom4->placeScenery(2, 5, '^');
	teleRoom4->placeScenery(2, 6, '^');
	teleRoom4->placeScenery(2, 7, '^');
	teleRoom4->placeScenery(3, 5, '^');
	teleRoom4->placeScenery(3, 6, '^');
	teleRoom4->placeScenery(3, 7, '^');
	teleRoom4->placeScenery(4, 5, '^');
	teleRoom4->placeScenery(4, 6, '^');
	teleRoom4->placeScenery(5, 5, '^');
	teleRoom4->placeScenery(5, 6, '^');
	teleRoom4->placeScenery(6, 5, '^');
	teleRoom4->placeScenery(6, 6, '^');
}

void Game::createTeleRoom5() {
	teleRoom5 = new Map(9, 9, "Blue Rooms");
	teleRoom5->mapCreation();
	//Splitting wall
	for (int i = 0; i < 9; i++) {
		teleRoom5->placeScenery(i, 4, '~');
	}
	//Teleporters
	teleRoom5->placeTeleporter(1, 6);
	teleRoom5->placeTeleporter(7, 6);
	teleRoom5->placeTeleporter(7, 2);
	//Item
	teleRoom5->placeItem(1, 2, '$', "Key 3");
	//Scenery
	teleRoom5->placeScenery(1, 1, '^');
	teleRoom5->placeScenery(2, 1, '^');
	teleRoom5->placeScenery(3, 1, '^');
	teleRoom5->placeScenery(4, 1, '^');
	teleRoom5->placeScenery(5, 1, '^');
	teleRoom5->placeScenery(6, 1, '^');
	teleRoom5->placeScenery(7, 1, '^');
	teleRoom5->placeScenery(1, 7, '^');
	teleRoom5->placeScenery(2, 7, '^');
	teleRoom5->placeScenery(3, 7, '^');
	teleRoom5->placeScenery(4, 7, '^');
	teleRoom5->placeScenery(5, 7, '^');
	teleRoom5->placeScenery(6, 7, '^');
	teleRoom5->placeScenery(7, 7, '^');
	teleRoom5->placeScenery(2, 2, '^');
	teleRoom5->placeScenery(3, 2, '^');
	teleRoom5->placeScenery(4, 2, '^');
	teleRoom5->placeScenery(5, 2, '^');
	teleRoom5->placeScenery(6, 2, '^');
	teleRoom5->placeScenery(2, 6, '^');
	teleRoom5->placeScenery(3, 6, '^');
	teleRoom5->placeScenery(4, 6, '^');
	teleRoom5->placeScenery(5, 6, '^');
	teleRoom5->placeScenery(6, 6, '^');
}

void Game::createTeleRoom6() {
	teleRoom6 = new Map(9, 9, "Blue Rooms");
	teleRoom6->mapCreation();
	//Teleporters
	teleRoom6->placeTeleporter(4, 1);
	//Scenery
	teleRoom6->placeScenery(1, 2, '^');
	teleRoom6->placeScenery(2, 2, '^');
	teleRoom6->placeScenery(3, 2, '^');
	teleRoom6->placeScenery(4, 2, '^');
	teleRoom6->placeScenery(5, 2, '^');
	teleRoom6->placeScenery(6, 2, '^');
	teleRoom6->placeScenery(6, 3, '^');
	teleRoom6->placeScenery(6, 4, '^');
	teleRoom6->placeScenery(6, 5, '^');
	teleRoom6->placeScenery(6, 6, '^');
	teleRoom6->placeScenery(5, 6, '^');
	teleRoom6->placeScenery(4, 6, '^');
	teleRoom6->placeScenery(3, 6, '^');
	teleRoom6->placeScenery(2, 6, '^');
}

void Game::createTeleRoom7() {
	teleRoom7 = new Map(9, 9, "Blue Rooms");
	teleRoom7->mapCreation();
	//Teleporters
	teleRoom7->placeTeleporter(1, 4);
	//Scenery
	teleRoom7->placeScenery(1, 5, '=');
	teleRoom7->placeScenery(1, 6, '=');
	teleRoom7->placeScenery(1, 7, '=');
	teleRoom7->placeScenery(2, 2, '=');
	teleRoom7->placeScenery(2, 3, '=');
	teleRoom7->placeScenery(2, 4, '=');
	teleRoom7->placeScenery(2, 5, '=');
	teleRoom7->placeScenery(2, 6, '=');
	teleRoom7->placeScenery(2, 7, '=');
	teleRoom7->placeScenery(3, 2, '=');
	teleRoom7->placeScenery(3, 3, '=');
	teleRoom7->placeScenery(4, 2, '=');
	teleRoom7->placeScenery(4, 3, '=');
	teleRoom7->placeScenery(4, 5, '=');
	teleRoom7->placeScenery(4, 6, '=');
	teleRoom7->placeScenery(5, 2, '=');
	teleRoom7->placeScenery(5, 3, '=');
	teleRoom7->placeScenery(5, 4, '=');
	teleRoom7->placeScenery(5, 5, '=');
	teleRoom7->placeScenery(5, 6, '=');
	teleRoom7->placeScenery(6, 2, '=');
	teleRoom7->placeScenery(6, 3, '=');
	teleRoom7->placeScenery(6, 4, '=');
	teleRoom7->placeScenery(6, 5, '=');
	teleRoom7->placeScenery(6, 6, '=');
}

void Game::createTeleRoom8() {
	teleRoom8 = new Map(9, 9, "Blue Rooms");
	teleRoom8->mapCreation();
	//Teleporters
	teleRoom8->placeTeleporter(7, 4);
	//Scenery
	teleRoom8->placeScenery(7, 1, '^');
	teleRoom8->placeScenery(6, 1, '^');
	teleRoom8->placeScenery(5, 1, '^');
	teleRoom8->placeScenery(4, 1, '^');
	teleRoom8->placeScenery(3, 1, '^');
	teleRoom8->placeScenery(2, 1, '^');
	teleRoom8->placeScenery(1, 1, '^');
	teleRoom8->placeScenery(1, 2, '^');
	teleRoom8->placeScenery(1, 3, '^');
	teleRoom8->placeScenery(1, 4, '^');
	teleRoom8->placeScenery(1, 5, '^');
	teleRoom8->placeScenery(1, 6, '^');
	teleRoom8->placeScenery(1, 7, '^');
	teleRoom8->placeScenery(2, 7, '^');
	teleRoom8->placeScenery(3, 7, '^');
	teleRoom8->placeScenery(4, 7, '^');
	teleRoom8->placeScenery(5, 7, '^');
	teleRoom8->placeScenery(6, 7, '^');
	teleRoom8->placeScenery(7, 7, '^');
	teleRoom8->placeScenery(7, 2, '^');
	teleRoom8->placeScenery(7, 6, '^');
}

void Game::createTeleRoom9() {
	teleRoom9 = new Map(9, 9, "Blue Rooms");
	teleRoom9->mapCreation();
	//Teleporters
	teleRoom9->placeTeleporter(4, 1);
	teleRoom9->placeTeleporter(1, 4);
	//Scenery
	teleRoom9->placeScenery(7, 7, '=');
	teleRoom9->placeScenery(7, 6, '=');
	teleRoom9->placeScenery(7, 5, '=');
	teleRoom9->placeScenery(6, 6, '=');
	teleRoom9->placeScenery(6, 7, '=');
	teleRoom9->placeScenery(5, 7, '=');
	teleRoom9->placeScenery(1, 3, '^');
	teleRoom9->placeScenery(2, 3, '^');
	teleRoom9->placeScenery(3, 3, '^');
	teleRoom9->placeScenery(1, 2, '^');
	teleRoom9->placeScenery(2, 2, '^');
	teleRoom9->placeScenery(3, 2, '^');
	teleRoom9->placeScenery(1, 1, '^');
	teleRoom9->placeScenery(2, 1, '^');
	teleRoom9->placeScenery(3, 1, '^');
	teleRoom9->placeScenery(4, 3, '^');
	teleRoom9->placeScenery(5, 3, '^');
	teleRoom9->placeScenery(6, 3, '^');
	teleRoom9->placeScenery(4, 2, '^');
	teleRoom9->placeScenery(5, 2, '^');
	teleRoom9->placeScenery(6, 2, '^');
	teleRoom9->placeScenery(2, 4, '^');
	teleRoom9->placeScenery(2, 5, '^');
	teleRoom9->placeScenery(2, 6, '^');
	teleRoom9->placeScenery(3, 4, '^');
	teleRoom9->placeScenery(3, 5, '^');
	teleRoom9->placeScenery(3, 6, '^');
}

void Game::createFinalRoom() {
	finalRoom = new Map(14, 29, "Final Room");
	//Teleporters
	finalRoom->mapCreation();
	//Door
	finalRoom->placeDoor(12, 14);
	//End Game Square
	finalRoom->placeItem(1, 14, '@', "End Game");
	//Scenery
	for (int i = 2; i < 12; i++) {
		finalRoom->placeScenery(i, 26, '=');
	}
	for (int i = 2; i < 27; i++) {
		finalRoom->placeScenery(11, i, '=');
	}
	for (int i = 2; i < 12; i++) {
		finalRoom->placeScenery(i, 2, '=');
	}
	for (int i = 2; i < 27; i++) {
		finalRoom->placeScenery(2, i, '=');
	}
	for (int i = 6; i < 11; i++) {
		finalRoom->placeScenery(i, 13, '=');
	}
	for (int i = 6; i < 11; i++) {
		finalRoom->placeScenery(i, 15, '=');
	}
	finalRoom->placeScenery(6, 14, '=');
	finalRoom->placeItem(11, 14, ' ', "blank");
}

void Game::displayCurrentRoom() {
	Map *temp = p->getPlayerLocation();

	for (int row = 0; row < temp->getLength(); row++) {
		for (int col = 0; col < temp->getWidth(); col++) {
			if (row == p->getPlayerX() && col == p->getPlayerY()) {
				std::cout << "O ";
			}
			else {
				std::cout << temp->getMap()[row][col]->getSymbol() << ' ';
			}
		}
		std::cout << '\n';
	}
	std::cout << "Location: " << temp->getRoomName() << '\n';
	std::cout << "    Keys: " << inventory[0] << ' ' << inventory[1] << ' ' << inventory[2] << '\n';
}

void Game::setCurrentRoom(Map *m) {
	currentRoom = m;
}

void Game::playerMovement(char c) {
	Square ***temp = p->getPlayerLocation()->getMap();
	int x = p->getPlayerX();
	int y = p->getPlayerY();

	if (c == 'w') {
		if (temp[x - 1][y]->isReachable()) {
			p->setPlayerX(x - 1);
		}
	}
	else if (c == 'a') {
		if (temp[x][y - 1]->isReachable()) {
			p->setPlayerY(y - 1);
		}
	}
	else if (c == 's') {
		if (temp[x + 1][y]->isReachable()) {
			p->setPlayerX(x + 1);
		}
	}
	else if (c == 'd') {
		if (temp[x][y + 1]->isReachable()) {
			p->setPlayerY(y + 1);
		}
	}
}

char Game::getInput() {
	char input = not_input;
	bool valid = false;
	char ch;

	std::cout << "Input: ";
	std::cin >> ch;

	while (!valid) {
		while (!std::cin >> ch) {
			std::cout << "Must enter a character.\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

		while (input == not_input) {
			switch (toupper(ch)) {
			case 'W':
				input = 'w';
				valid = true;
				break;
			case 'A':
				input = 'a';
				valid = true;
				break;
			case 'S':
				input = 's';
				valid = true;
				break;
			case 'D':
				input = 'd';
				valid = true;
				break;
			case 'X':
				input = 'x';
				valid = true;
				break;
			case 'E':
				input = 'e';
				valid = true;
				break;
			default:
				input = not_input;
				ch = -1;
			}
		}
	}

	return static_cast<char>(input);
}

void Game::gamePlay() {
	int health = p->getPlayerHealth();
	printControls();
	std::cin.ignore();
	printIntroduction();
	std::cin.ignore();
	displayCurrentRoom();
	std::cout << "  Health: " << health << "\n\n\n";

	while (!gameOver) {
		char i = getInput();

		switch (i) {
		case 'w':
			playerMovement(i);
			break;
		case 'a':
			playerMovement(i);
			break;
		case 's':
			playerMovement(i);
			break;
		case 'd':
			playerMovement(i);
			break;
		case 'e':
			playerAction();
			break;
		case 'x':
			gameOver = true;
			lost = true;
			break;
		default:
			gameOver = true;
		}

		health--;

		if (health <= 0) {
			gameOver = true;
			lost = true;
		}

		for (int i = 0; i < 20; i++) {
			std::cout << '\n';
		}



		if (p->getPlayerLocation()->getRoomName() == "Green Room") {
			std::cout << "               Whispering Voice: Collect all of\n";
			std::cout << "               the and place them on the shrine.\n";
		}

		if (p->getPlayerLocation()->getRoomName() == "Yellow Room") {
			std::cout << "      Whispering Voice: These are teleporters that take you\n";
			std::cout << "     into the blue rooms. Don't get lost in the maze of rooms.\n";
		}

		displayCurrentRoom();
		std::cout << "Health: " << health << "\n\n\n";
	}

	if (gameOver == true && lost == false) {
		std::cout << "       Character: Finally, I've placed all of the idols on the shrine...\n";
		std::cin.ignore();
		std::cout << "           Whipsering Voice: All of the items have been collected,\n";
		std::cout << "           you shall receive the answers you've been looking for.\n";
		std::cin.ignore();
		std::cout << "          The wall behind the shrine slowly becomes reflective...\n";
		std::cin.ignore();
		std::cout << "             Whispering Voice: Watch as your truth unfolds.\n";
		std::cout << "       Three little, blue men standing one on top of the other, jump down.\n";
		std::cout << "          Character: ...I ... I'm just three blue men stacked up?\n";
	}
	else if (gameOver == true && lost == true) {
		std::cout << "You have quit the game, thanks for playing.\n         Better luck next time.\n";
	}
}

void Game::playerAction() {
	int x = p->getPlayerX();
	int y = p->getPlayerY();
	int roomX = p->getPlayerLocation()->getWidth();
	int roomY = p->getPlayerLocation()->getLength();
	char symbol = p->getPlayerLocation()->getMap()[x][y]->getSymbol();
	//If square player is on is a door
	if (symbol == '#') {
		//Door functions
		Map *temp = p->getPlayerLocation();
		if (x == 1) {
			if (temp->getRoomName() == "Green Room") {
				if (y == 4) {
					//North pointer
					currentRoom = p->getPlayerLocation()->getNorth();
					p->setPlayerLocation(currentRoom);
					p->setPlayerX(currentRoom->getLength() / 2);
					p->setPlayerY(currentRoom->getWidth() / 2);
				}
				else {
					//North2 pointer
					currentRoom = p->getPlayerLocation()->getNorth2();
					p->setPlayerLocation(currentRoom);
					p->setPlayerX(currentRoom->getLength() / 2);
					p->setPlayerY(currentRoom->getWidth() / 2);
				}
			}
			else {
				//North pointer
				currentRoom = p->getPlayerLocation()->getNorth();
				p->setPlayerLocation(currentRoom);
				p->setPlayerX(currentRoom->getLength() / 2);
				p->setPlayerY(currentRoom->getWidth() / 2);
			}
		}
		else if (x == (roomY - 2)) {
			//South pointer
			currentRoom = p->getPlayerLocation()->getSouth();
			p->setPlayerLocation(currentRoom);
			p->setPlayerX(currentRoom->getLength() / 2);
			p->setPlayerY(currentRoom->getWidth() / 2);
		}
		else if (y == 1) {
			//West pointer
			currentRoom = p->getPlayerLocation()->getWest();
			p->setPlayerLocation(currentRoom);
			p->setPlayerX(currentRoom->getLength() / 2);
			p->setPlayerY(currentRoom->getWidth() / 2);
		}
		else if (y == (roomX - 2)) {
			//East pointer
			currentRoom = p->getPlayerLocation()->getEast();
			p->setPlayerLocation(currentRoom);
			p->setPlayerX(currentRoom->getLength() / 2);
			p->setPlayerY(currentRoom->getWidth() / 2);
		}
		else {
			//For testing
		}
	}
	//If square player is on is a teleporter
	else if (symbol == '*') {
		Map *temp = p->getPlayerLocation();
		if (x == 1) {
			//North pointer
			currentRoom = p->getPlayerLocation()->getNorth();
			p->setPlayerLocation(currentRoom);
			p->setPlayerX(currentRoom->getLength() / 2);
			p->setPlayerY(currentRoom->getWidth() / 2);
		}
		else if (x == (roomY - 2)) {
			//South pointer
			currentRoom = p->getPlayerLocation()->getSouth();
			p->setPlayerLocation(currentRoom);
			p->setPlayerX(currentRoom->getLength() / 2);
			p->setPlayerY(currentRoom->getWidth() / 2);
		}
		else if (y == 1) {
			//West pointer
			currentRoom = p->getPlayerLocation()->getWest();
			p->setPlayerLocation(currentRoom);
			p->setPlayerX(currentRoom->getLength() / 2);
			p->setPlayerY(currentRoom->getWidth() / 2);
		}
		else if (y == (roomX - 2)) {
			//East pointer
			currentRoom = p->getPlayerLocation()->getEast();
			p->setPlayerLocation(currentRoom);
			p->setPlayerX(currentRoom->getLength() / 2);
			p->setPlayerY(currentRoom->getWidth() / 2);
		}
	}
	//If square player is on is an item
	else if (symbol == '!' || symbol == '$' || symbol == '&') {
		inventory[invenSize] = symbol;
		p->getPlayerLocation()->getMap()[x][y]->setSymbol(' ');
		invenSize++;
		std::cout << "You picked up the " << symbol << " key.\n";

	}
	else if (symbol == '@') {
		if (allIdols()) {
			gameOver = true;
		}
		else {
			std::cout << "Make sure you collect all of the idols.\n";
		}
		
	}
	else {
		p->getPlayerLocation()->getMap()[p->getPlayerX()][p->getPlayerY()]->getAction();
	}
}

void Game::printIntroduction() {
	std::cout << "      Character: I know not of how my existence came to be,\n";
	std::cout << "      that I am just here, standing in the darkness, alone.\n";
	std::cout << "       long have I been here ? It's a question that runs my\n";
	std::cout << "       mind constantly, yet I have no answer.And what if had\n";
	std::cout << "     an answer ? Where would that get me ? I would still be ...\n";
	std::cin.ignore();
	std::cout << "Whispering Voice: ...your answers and more are just beyond this door...\n";
	std::cin.ignore();
	std::cout << "                   Character: Who's there?\n";
	std::cin.ignore();
	std::cout << "A small bead of light sclices through the darkness and illuminates a door.\n";
	std::cout << "         Character: (internal) Has that door always been there?\n";
	std::cout << "          I try and think back, but its not important. What's\n";
	std::cout << "      important now and finding out what, and who, on the other side.";
}

void Game::printControls() {
	std::cout << "                      The Blue Inside\n\n";
	std::cout << "                     Movement Controls\n";
	std::cout << "                         W = foward\n";
	std::cout << "                         S = back\n";
	std::cout << "                         A = left\n"; 
	std::cout << "                         D = right\n\n";
	std::cout << "                    Interaction Controls\n";
	std::cout << "                         E = action\n\n";
	std::cout << "                        Exit Controls\n";
	std::cout << "                         X = exit\n\n";
	std::cout << "                        Symbol Key\n"; 
	std::cout << "                         O = player\n"; 
	std::cout << "                         ~ = wall\n"; 
	std::cout << "                         # = door\n";
	std::cout << "                         * = teleporter\n";
	std::cout << "                       !, $, & = idols\n\n";
	std::cout << "                        Instructions\n";
	std::cout << "             You are need to collect all three to\n";
	std::cout << "              place on the shrine to win the game.\n\n";
	std::cout << "                    Press enter to continue.";
}

bool Game::allIdols() {
	bool idol1 = false,
		 idol2 = false,
		 idol3 = false;
	char toFind1 = '!',
		 toFind2 = '$',
		 toFind3 = '&';

	for (int i = 0; i < 3; i++) {
		if (inventory[i] == toFind1) {
			idol1 = true;
		}
		else if (inventory[i] == toFind2) {
			idol2 = true;
		}
		else if (inventory[i] == toFind3) {
			idol3 = true;
		}
	}

	if (idol1 && idol2 && idol3) {
		return true;
	}
	else {
		return false;
	}
}