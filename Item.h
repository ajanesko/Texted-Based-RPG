#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "Square.h"

class Item : public Square {
private:
	std::string itemName;
public:
	//Constructor
	Item();
	Item(char, std::string);
	//Getters
	std::string getItemName();
	void getAction();
	//Setters
	void setItemName(std::string);
};


#endif