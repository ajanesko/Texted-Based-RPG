#ifndef TELEPORTER_H
#define TELEPORTER_H

#include <iostream>
#include <string>

#include "Square.h"

class Teleporter : public Square {
private:
	bool itemRequired;
	std::string itemNeeded;
public:
	//Constructor
	Teleporter();				//Regular teleporter
	Teleporter(std::string);	//Locked teleporter
	//Other
	void interact(std::string);
	void getAction();
};

#endif