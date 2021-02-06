#ifndef CHARACTER_H
#define CHARACTER_H
 
#include <iostream> 
#include "equipment.h"
using namespace std; 
 
class Character 
{
    public: 
        Character(); //Default constructor 
        Character(string name_, int district, int scores_[], int health_, int location[], int numItems, Equipment equipment[]); //Parameterized constructor
        
        //getters
        string getName(); 
        int getDistrict(); 
        int getScores(int index); //0=strength, 1=charm, 2=agility, 3=intellect
        int getHealth();
        int getLocation(int index); //x = 0, y = 1 
        int getNumItems();
        int getEquipmentSize();
        Equipment getEquipment(int index); 
        
        //setters
        void setName(string name_); 
        void setDistrict(int district_);
        void setHealth(int amount); //sets health equal to amount
        void setLocation(int index, int newCoordinate); //index: x=0, y=1; newCoordinate replaces old value for that index
        void setScore(int index, int amount); //index: which ability
        void setNumItems(int number);
        void setEquipmentSize(int number);
        void setEquipment(Equipment item, int index);
 
        
    private: 
        //determine data member name
        string name;
        
        //determine data member scores array 
        int district;
        int scores[4]; //0=strength, 1=charm, 2=agility, 3=intellect
        
        //determine data member health
        int health;
        
        //determine data member location
        int location[2]; //x,y
        
        //determines data member equipmentSize
        int numItems; 
        int equipmentSize;
        Equipment equipment[5]; 
}; 
 
#endif



