#include <string>
#include <iostream> 
#include <string>
#include <fstream>
#include "Character.h"
#include "Equipment.h"
#include "Map.h"
#include "Game.h"
using namespace std; 

//default constructor
Game::Game() {
    numCharacters = 0;
}

//parameterized constructor
Game::Game(int numPeople) {
    numCharacters = numPeople;

    //assigns all 10 items in the game into the array, they are static and do not change
    items[0].setName("The Silencer");
    items[0].setItemType("sword");
    items[0].setAmount(3);

    items[1].setName("The Lightbringer");
    items[1].setItemType("dagger");
    items[1].setAmount(2);

    items[2].setName("Freshly baked Rosemary Roll");
    items[2].setItemType("food");
    items[2].setAmount(4);

    items[3].setName("Bloodied Steel Greatsword");
    items[3].setItemType("sword");
    items[3].setAmount(5);

    items[4].setName("Soul Reaper");
    items[4].setItemType("dagger");
    items[4].setAmount(4);

    items[5].setName("Shepherd's Pie");
    items[5].setItemType("food");
    items[5].setAmount(2);

    items[6].setName("Vindictive Shortsword");
    items[6].setItemType("sword");
    items[6].setAmount(2);

    items[7].setName("The Annihilator");
    items[7].setItemType("dagger");
    items[7].setAmount(5);

    items[8].setName("Braised Lamb");
    items[8].setItemType("food");
    items[8].setAmount(4);

    items[9].setName("Twilight Longsword");
    items[9].setItemType("sword");
    items[9].setAmount(2);
}

//getters
Character Game::getCharacter(int index) {
    return characters[index];
}

int Game::getNumCharacters() {
    return numCharacters;
}

Equipment Game::getEquipment(int index) {
    return items[index];
}

//setters
void Game::setCharacter(Character person, int index) {
    characters[index] = person;
}

void Game::setNumCharacters(int number) {
    numCharacters = number;
}

void Game::printEquipment(int index) { //prints all equipment and info
	cout << "Item: " << items[index].getItemName() << " Points: " << items[index].getAmount() << endl; 
}

string Game::fight(Character person1, Character person2) {
    string winner;
    
    double fightScorePerson1 = 2*person1.getScores(0) + 0.75*person1.getScores(1) + 0.5*person1.getScores(2) + 0.25*person1.getScores(3);
    double fightScorePerson2 = 2*person2.getScores(0) + 0.75*person2.getScores(1) + 0.5*person2.getScores(2) + 0.25*person2.getScores(3);

    //person1 wins, then person2 dies
    if (fightScorePerson1 > fightScorePerson2) {
        winner = person1.getName();
        person2.setHealth(0);
    //person2 wins, then person1 dies
    } else if (fightScorePerson1 < fightScorePerson2) {
        winner = person2.getName();
        person1.setHealth(0);
    //it's a tie, they both lose health but no one dies
    } else {
        cout << "It's a tie! No one dies, but you both lose health... You'll have to fight someday again to win!" << endl;
        person1.setHealth(person1.getHealth() - 5);
        person2.setHealth(person2.getHealth() - 5);
        return "";
    }
    
    game.setNumCharacters(game.getNumCharacters() - 1);
    return winner;
}

void Game::move(Character person) {
	cout << "Would you like to move? (Y/N)" << endl;
	string input;
    cin >> input;
    if (input == Y) {
    	cout << "Would you like to move N, E, S, or W? (N, E, S, W)" << endl;
    	cin >> input;

        srand(time(0));
        //generate random number between 1 and 3 (inclusive)
        int randomNum = rand()%(3 - 1 + 1) + 1;

        if (input == "N") {
            if (person.getLocation(1) - randomNum >= 0) { //if move is still in bounds
                //update location
                person.setLocation(1, person.getLocation(1) - randomNum);
                //get tile at new location
                string tile = map.getTile(person.getLocation(0), person.getLocation(1));
                //call corresponding map function
                if (tile == "T") {
                    map.trap(person);
                } else if (tile == "P") {
                    map.puzzle(person);
                } else if (tile == "C") {
                    map.character(person);
                } else {
                    map.equipment(person);
                }
            } else { //move was out of bounds
                cout << "That move is not valid. Pick a new direction (E, S, W)" << endl;
                cin >> input;
            }
        } else if (input == "E") {
            if (person.getLocation(0) + randomNum <= 8) { //if move is still in bounds
                //update location
                person.setLocation(0, person.getLocation(0) + randomNum);
                //get tile at new location
                string tile = map.getTile(person.getLocation(0), person.getLocation(1));
                //call corresponding map function
                if (tile == "T") {
                    map.trap(person);
                } else if (tile == "P") {
                    map.puzzle(person);
                } else if (tile == "C") {
                    map.character(person);
                } else {
                    map.equipment(person);
                }
            } else { //move was out of bounds
                cout << "That move is not valid. Pick a new direction (S, W), or move next turn!" << endl;
                cin >> input;
            }
        } else if (input == "S") {
            if (person.getLocation(1) + randomNum <= 2) { //if move is still in bounds
                //update location
                person.setLocation(1, person.getLocation(1) + randomNum);
                //get tile at new location
                string tile = map.getTile(person.getLocation(0), person.getLocation(1));
                //call corresponding map function
                if (tile == "T") {
                    map.trap(person);
                } else if (tile == "P") {
                    map.puzzle(person);
                } else if (tile == "C") {
                    map.character(person);
                } else {
                    map.equipment(person);
                }
            } else { //move was out of bounds
                cout << "That move is not valid. Move West (W), or move next turn!" << endl;
                cin >> input;
            }
        } else if (input == "W") {
            if (person.getLocation(0) - randomNum <= 8) { //if move is still in bounds
                //update location
                person.setLocation(0, person.getLocation(0) - randomNum);
                //get tile at new location
                string tile = map.getTile(person.getLocation(0), person.getLocation(1));
                //call corresponding map function
                if (tile == "T") {
                    map.trap(person);
                } else if (tile == "P") {
                    map.puzzle(person);
                } else if (tile == "C") {
                    map.character(person);
                } else {
                    map.equipment(person);
                }
            } else { //move was out of bounds
                cout << "That move is not valid. Move next turn!" << endl;
                cin >> input;
            }
        }
    } 
    return;
}

bool Game::sneak(Character person1, Character person2) {
    bool success;

    //sneak score determined by person1's agility and intellect, must be less than person2's intellect to succeed
    double sneakScore = 2*person1.getScores(2) + + 0.25*person1.getScores(3);

    if (sneakScore < person2.getScores(3)) {
        return true;
    } else {
        return false;
    }
}

/*
* This function takes in string and splits it into pieces stored in an array,
* according to the provided separator
* Parameters: 
* split - a string to be split
* separator - a character determining where we separate the string
* splitString - an array of string where split pieces will be stored
* size - the size of the array
* Returns:
* Maximum value from each row
*/

int split(string split, char separator, string splitString[], int size)
{
    int number = 0;
    string test = "";
    bool check = false;
    
    for (int i = 0; i < split.length(); i ++)
    {
        if (split[i] != separator) 
        {
            test = test + split[i];
        }
        else if (split[i] == separator && test != "" && number < size)
        {
            splitString[number] = test;
            number ++;
            test = "";
        }
        if (number >= size)
        {
            check = true;
        }
        
    }
    
    if (test != "" && number < size)
    {
        splitString[number] = test;
        number ++;
    }
    
    if (check == true)
    {
        number = -1;
    }

    return number;
}

void Game::readCharacters(string fileName) {
    ifstream myFile(fileName);
    string str = "";
    int characterNum = 0;

    if (myFile.fail()) {
        return;
    } else {
        while (getline(myFile, str)) { //for each line(or character)
            if (str != "") {
                string splitString[11]; //split the line
                int count = split(str, ',', splitString, 11)
                //assign values to fill all the characters in the game
                game.characters[characterNum].setName(splitString[0]);
                game.characters[characterNum].setDistrict(stoi(splitString[1]));
                game.characters[characterNum].setHealth(stoi(splitString[2]));
                game.characters[characterNum].setLocation(0, stoi(splitString[3]));
                game.characters[characterNum].setLocation(1, stoi(splitString[4]));
                game.characters[characterNum].setScore(stoi(0, splitString[5]));
                game.characters[characterNum].setScore(stoi(1, splitString[6]));
                game.characters[characterNum].setScore(stoi(2, splitString[7]));
                game.characters[characterNum].setScore(stoi(3, splitString[8]));
                game.characters[characterNum].setNumItems(stoi(splitString[9]));
                game.characters[characterNum].setEquipmentSize(stoi(splitString[10]));
            }
            characterNum += 1;
        }
    }
    return;
}

string Game::printStats(Character person, int numDays, int numKilled) {
    string fileName = "statistics.txt";

    ofstream myfile;
    myfile.open(fileName);

    myfile << "Congratulations, "<< person.getName() << " of District " << person.getDistrict() << ". You are done playing the Hunger Games.\n";
    myfile << "Here are you game statistics! And if you decide to play again... may the odds be ever in your favor!\n";
    myfile << "You killed " << numKilled << " people,\n";
    myfile << "You survived " << numDays << "days.\n";
    myfile << "Your final strength score: " << person.getScores(0) << "\n";
    myfile << "Your final charm score: " << person.getScores(1) << "\n";
    myfile << "Your final agility score: " << person.getScores(2) << "\n";
    myfile << "Your final intellect score: " << person.getScores(3) << "\n";
    myfile << "You finished with " << person.getNumItems() << " items. They are printed below.\n";
    for (int i = 0; i < person.getNumItems(); i ++) {
        myfile << (person.getEquipment(i)).getItemName() << "\n";
    }
    myfile.close()

    return fileName;
}





