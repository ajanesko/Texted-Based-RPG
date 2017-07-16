#include "Wall.h"

/********************************************
*				Constructors				*
********************************************/
Wall::Wall() : Square('~', false) {

}

void Wall::getAction() {
	std::cout << "Nothing is here.\n";
}