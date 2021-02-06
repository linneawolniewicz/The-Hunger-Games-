#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>nnn
using namespace std; 

class Equipment
{
    public: 
        Equipment(); //Default constructor, assigns all ten items in the game to the array
        
        //getters
        string getItemName(); 
        string getItemType();
        int getAmount();  
        Equipment getEquipment(int index);
        
        //setters
        void setName(string name);
        void setAmount(int num);
        void setItemType(string type);

        void printEquipment(int index); //prints info about each item of equipment 
        
    private: 
        static Equipment items[10];
        string itemType;
        string itemName; 
        int amount; 
}; 

#endif


