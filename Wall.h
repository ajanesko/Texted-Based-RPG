#ifndef WALL_H
#define WALL_H

#include "Square.h"

class Wall : public Square {
private:

public:
	//Constructor
	Wall();
	void getAction();
};

#endif