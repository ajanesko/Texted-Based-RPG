#include "Teleporter.h"

/********************************************
*				Constructor					*
********************************************/
Teleporter::Teleporter() : Square('*', true) {
	itemRequired = false;
	itemNeeded = "";
}

Teleporter::Teleporter(std::string item) : Square('*', false) {
	itemRequired = true;
	itemNeeded = item;
}

/********************************************
*					Other					*
********************************************/
void Teleporter::interact(std::string playerItem) {
	if (!reachable && itemNeeded != "") {
		if (itemNeeded == playerItem) {
			reachable = true;
			std::cout << "The teleporter has been unlocked!\n";
		}
	}
}

void Teleporter::getAction() {
	std::cout << "This is a teleporter.\n";
}