#include "Item.h"

/********************************************
*				Constructors				*
********************************************/
Item::Item() : Square('!', true) {
	itemName = "";
}

Item::Item(char symbol, std::string name) : Square(symbol, true) {
	itemName = name;
}

/********************************************
*					Getters					*
********************************************/
std::string Item::getItemName() {
	return itemName;
}

void Item::getAction() {

}

/********************************************
*					Setters					*
********************************************/
void Item::setItemName(std::string name) {
	itemName = name;
}