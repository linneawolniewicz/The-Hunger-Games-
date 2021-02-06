#include <iostream> 
#include "character.h"
#include "equipment.h"
using namespace std;
 
Character::Character()
{
    name = ""; 
    district = 0; 
    health = 10;
    
    for (int i = 0; i < 4; i++)
    {
        scores[i] = 0; 
    }
    
    for (int i = 0; i < 2; i++)
    {
        location[i] = 0; 
    }
    
    equipmentSize = 3; 
    
    //blank equipment array 
}
 
Character::Character(string name_, int district_, int scores_[], int health_, int location[], int equipmentSize, Equipment equipment[])
{
    name = name_; 
    district = district_; 
    health = health_;
    
    scores[0] = 0; 
    scores[1] = 0; 
    scores[2] = 0; 
    scores[3] = 0;
    
    location[0] = 0; 
    location[1]= 0; 
    
    equipmentSize = 3;
    
    //blank equipment array
}
 
string Character::getName()
{
    return name; 
}
 
int Character::getDistrict()
{
    return district; 
}
 
int Character::getScores(int index)
{
    return scores[index];
}
 
int Character::getHealth()
{
    return health; 
}
 
int Character::getLocation(int index) {
    return location[index];
}
 
int Character::getNumItems() {
    return numItems;
}
 
int Character::getEquipmentSize() {
    return equipmentSize;
}
 
Equipment Character::getEquipment(int index) {
    return equipment[index];
}
 
///////////////////////////////////////
 
void Character::setName(string name_)
{
    name = name_; 
}
 
void Character::setDistrict(int district_)
{
    district = district_; 
}
 
void Character::setHealth(int amount)
{
    health = amount;  
}
 
void Character::setLocation(int index, int newCoordinate) 
{
    location[index] = newCoordinate; 
}
 
void Character::setScore(int index, int amount)
{
    scores[index] = amount;
}
 
void Character::setNumItems(int number) {
    numItems = number;
}
 
void Character::setEquipmentSize(int number) {
    equipmentSize = number;
}
 
void Character::setEquipment(Equipment item, int index) {
    equipment[index] = item;
}


