#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>

class Square {
protected:
	char symbol;
	bool reachable;
	bool playerOn;
private:

public:
	//Constructors
	Square(char, bool);
	//Getters
	char getSymbol();
	bool isReachable();
	bool isPlayerOn();
	//Setters
	void setSymbol(char);
	//Virtual
	virtual void getAction() = 0;
};

#endif