#include "Square.h"

/********************************************
*				Constructor					*
********************************************/
Square::Square(char s, bool reach) {
	symbol = s;
	reachable = reach;
}

/********************************************
*					Getters					*
********************************************/
char Square::getSymbol() {
	return symbol;
}

bool Square::isReachable() {
	return reachable;
}

bool Square::isPlayerOn() {
	return playerOn;
}

/********************************************
*					Setters					*
********************************************/
void Square::setSymbol(char s) {
	symbol = s;
}