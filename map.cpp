#include <string>
#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include "character.h"
#include "Equipment.h"
#include "Map.h"
using namespace std; 

//default constructor
Map::Map() { 
    for(int i = 0; i < 8; i ++) {
        for (int j = 0; j < 3; j ++) {
		    tiles[i][j] = "";
    	}
    }
    return;
}

//parameterized constructor
Map::Map(string MapTiles[8][3]) {
    tiles[1][0], tiles[5][0], tiles[8][0], tiles[0][1], tiles[3][1], tiles[7][1], tiles[2][2], tiles[5][2], tiles[8][2] = "E";
    tiles[2][0], tiles[4][0], tiles[7][0], tiles[1][1], tiles[5][1], tiles[6][2] = "P";
    tiles[3][0], tiles[4][1], tiles[6][1], tiles[1][2], tiles[3][2], tiles[7][2] = "T";
    tiles[6][0], tiles[2][1], tiles[8][1], tiles[0][2], tiles[4][2] = "C";
    return;
}

string Map::getTile(int x, int y) {
	return tiles[x][y];
}

void Map::setTile(int x, int y, string setValue) {
	tiles[x][y] = setValue;
	return;
}

void Map::trap(Character person) {
    srand(time(0));
    //generate random number between 1 and 99 (inclusive)
    int randomNum = rand()%(99 - 1 + 1) + 1;

    // if agility is less than 5, 70% trap happens
    if(person.getScores(2) < 5) {
        cout << "There is a 70% chance that you will fall into a TRAP!" << endl;

        if(randomNum >= 70) {
            cout << "You succeeded to dodge the trap! Congratulations!" << endl;
            return;
        } else {
            cout << "You fall into the trap! Dun dun dun..." << endl;
        }
    //agility is greater than 5, only 40% chance trap happens
    } else {
        cout << "There is a 40% chance that you will fall into a TRAP!" << endl;

        if(randomNum >= 40) {
            cout << "You succeeded to dodge the trap! Congratulations!" << endl;
            return;
        } else {
            cout << "You fall into the trap! Dun dun dun..." << endl;
        }
    }

    //generate random number between 1 and 3 (inclusive)
    int randomNum = rand()%(3 - 1 + 1) + 1;
	switch(randomNum) {
		case 1: cout << "You fall in lava! Ouch!" << endl;
			person.setHealth = person.getHealth - 3;
			break;
		case 2: cout << "You fell into a pit of snakes! Hiss!" << endl;
			person.setHealth = person.getHealth - 2;
			break;
		case 3: cout << "All of a sudden, you realize you were standing on ICE! And it cracks…" << endl;
            person.setHealth = person.getHealth - 2;
            break;
    }
    return;	
}

void Map::puzzle(Character person) {
	cout << "You have landed in a puzzle!" << endl;

	//generate random number between 1 and 3 (inclusive)
    srand(time(0));
    int randomNum = rand()%(3 - 1 + 1) + 1;

    string input;

	switch(randomNum) {
		case 1: 
			cout << "There are three people (Alexander, Alice and Laura), one of whom is a knight, one a knave, and one a spy. The knight always tells the truth, the knave always lies, and the spy can either lie or tell the truth. Alexander says: 'Laura is a knave.' Alice says: 'Alexander is a knight.' Laura says: 'I am the spy.' Who is the spy? (Enter in lowercase)" << endl;
			cin >> input;
			if (input == "alice") {return;}
			else {
                cout << "You lose! It was alice who was the spy." << endl;
                person.setHealth = person.getHealth - 3;
            } 
			break;
		case 2:
			cout << "The day before two days after the day before tomorrow is Saturday. What day is it today? (Enter all lowercase)" << endl;
			cin >> input;
            if (input == "friday") {return;}
 			else{
                cout << "You lose! The day is friday." << endl;
                person.setHealth = person.getHealth - 3;
             }
			break;
		case 3:
			cout << "A girl meets a lion and unicorn in the forest. The lion lies every Monday, Tuesday and Wednesday and the other days he speaks the truth. The unicorn lies on Thursdays, Fridays and Saturdays, and the other days of the week he speaks the truth. 'Yesterday I was lying,' the lion told the girl. 'So was I,' said the unicorn. What day is it? (Enter in lowercase)" << endl;
			cin >> input;
			if (input == "thursday") {return;}
			else {
                cout << "You lose! The day is thursday." << endl;
                person.setHealth = person.getHealth - 3;
            }
			break;
	return;
	}
}

void Map::character(Character person1) {
	Character person2;
    //find other character at this location, person2
    for (int i = 0; i < game.getNumCharacters(); i ++;) {
        Character findingPerson2 = game.getCharacter(i);
        if (findingPerson2.getLocation(0) == person1.getLocation(0) && findingPerson2.getLocation(1) == person1.getLocation(1)) {
            person2 = game.getCharacter(i);
        }
    }
    
    cout << "You have run into another character! Do you choose to fight or sneak around them? (F/S)" << endl;
    string input;
    cin >> input;
    
    if (input == "F") {
        game.fight(person1, person2);
    } else { 
        game.sneak(person1, person2);
    }
    return;
}

void Map::equipment(Character person) {
    //generate random number between 0 and 9 (inclusive)
    srand(time(0));
    int index = rand()%(9 - 0 + 1) + 0;

    //create Equipment object at this tile (it's a random one)
    Equipment tileItem = game.getEquipment(index);

    //increase number of items person now has, if it exceeds Equipment size don't add item
    if (person.getNumItems() < person.getEquipmentSize()) {
        person.setEquipment(tileItem, person.getNumItems());
        person.setNumItems(person.getNumItems() + 1);

        //update scores and health accordingly
        if(tileItem.getItemType() == "sword") { //tile item is a sword, increase strength
            person.setScore(0, tileItem.getAmount());
        } else if (tileItem.getItemType() == "dagger") { //tile item is a dagger, increase agility
            person.setScore(2, tileItem.getAmount());
        } else { //tile item is food, increase health
            person.setHealth(person.getHealth() + tileItem.getAmount());
        }

        cout << "Congratulations! You have picked up an item. here are it's statistics." << endl;
        tileItem.printEquipment(index);
    } else {
        cout << "You already have too many items! You want to pick it up, but must drop the item at this tile." << endl;
        return;
    }

    return;
}

