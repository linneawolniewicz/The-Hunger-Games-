#include <iostream> 
#include <string>
#include "equipment.h"
using namespace std;

Equipment::Equipment() //Default constructor 
{
    itemName = "";
    itemType = "";
    amount = 0;
}

//getters
string Equipment::getItemName()
{
	return itemName; 
}

string Equipment::getItemType() {
    return itemType;
}

int Equipment::getAmount() {
    return amount;
}

//setters
void Equipment::setName(string name) {
	itemName = name;
}

void Equipment::setAmount(int num) {
    amount = num;
}

void Equipment::setItemType(string type) {
    itemType = type;
}


