#include <string>
#include <iostream> 
#include "Character.h"
#include "Equipment.h"
using namespace std; 

class Map {
    public: 
        Map(); //Default constructor creates empty Map
        Map(string MapTiles[8][3]); //parameterized constructor fills empty Map exactly like outline Map
        
        //getters
        string getTile(int x, int y);
        
        //setters
        void setTile(int x, int y, string setValue);
                
        void Map::trap(Character person);
        void Map::puzzle(Character person);
        void Map::character(Character person1);
        void Map::equipment(Character person);
       
    private: 
        string tiles[8][3];
}; 



