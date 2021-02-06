#include <string>
#include <iostream> 
#include <string>
#include "character.h"
#include "Equipment.h"
#include "Map.h"
using namespace std; 

class Game {
    public: 
        Game(); //Default constructor
        Game(int numCharacters); //parameterized constructor
        
       //getters
        Character getCharacter(int index);
        int getNumCharacters();
        
        //setters
        void setCharacter(Character person, int index);
        void setNumCharacters(int number);
        
        int Game::Map(int x, int y);
        string Game::fight(Character person1, Character person2);
        void Game::announceDeath(Character person);
        void Game::move(Character person);
        void Game::sneak(Character person1, Character person2);
        void Game::readCharacters(string filename);
        string Game::printStats(Character person, int numDays, int numKilled);
    
    private: 
        int numCharacters;
        Character characters[6];
        Equipment items[10];
}; 
