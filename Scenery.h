#ifndef SCENERY_H
#define SCENERY_H

#include <string>

#include "Square.h"

class Scenery : public Square {
private:

public:
	//Constructor
	Scenery(char);
	void getAction();
};


#endif