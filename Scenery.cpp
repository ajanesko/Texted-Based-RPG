#include "Scenery.h"

/********************************************
*				Constructor 				*
********************************************/
Scenery::Scenery(char symbol) : Square(symbol, false) {

}

void Scenery::getAction() {
	std::cout << "Nothing is here.\n";
}