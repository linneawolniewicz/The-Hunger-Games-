#include <string>
#include <iostream> 
#include <string>
#include <fstream>
#include "character.h"
#include "equipment.h"
#include "map.h"
#include "game.h"

using namespace std; 

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

int main()
{
    Game game(5);
    Map map(1);  
    Character tribute;
    Character characters[4];
    int option = 0; 
    int i = 0; 
    
    ifstream myFile("statistics.txt"); //read file in with character information 
    int characterNum = 0; 
    string str = "";
 
    if (myFile.fail()) 
    {
        cout << "Error opening file." << endl; 
    } 
    else 
    {
    while (getline(myFile, str)) //for each line(or character)
    { 
        if (str != "") 
        {
            string splitString[11]; //split the line
            int count = split(str, ',', splitString, 11);
            //assign values to fill all the characters in the game
            characters[characterNum].setName(splitString[0]);
            characters[characterNum].setDistrict(stoi(splitString[1]));
            characters[characterNum].setHealth(stoi(splitString[2]));
            characters[characterNum].setLocation(0, stoi(splitString[3]));
            characters[characterNum].setLocation(1, stoi(splitString[4]));
            characters[characterNum].setScore(0, stoi(splitString[5]));
            characters[characterNum].setScore(1, stoi(splitString[6]));
            characters[characterNum].setScore(2, stoi(splitString[7]));
            characters[characterNum].setScore(3, stoi(splitString[8]));
            characters[characterNum].setNumItems(stoi(splitString[9]));
            characters[characterNum].setEquipmentSize(stoi(splitString[10]));
        }
    }
    
    do //creates menu 
    {
        cout << "Your name has been drawn at your district's reaping for the next Hunger Games. May the odds be ever in your favor." << endl; 
        cout << "Would you like to choose a character or make your own?" << endl; 
        cout << "Select a numerical option:" << endl; 
        cout << "1. Glimmer, District 1" << endl;
        cout << "2. Cato, District 2" << endl;
        cout << "3. Rue, District 11" << endl;
        cout << "4. Katniss, District 12" << endl;
        cout << "5. Make your own character" << endl; 
        cout << "6. Quit" << endl; 
        cin >> option; 
        
        if (option == 1) //glimmer
        {
            cout << "Here comes your mentor." << endl; 
            cout << "Mentor: 'You have trained all of your life for this Hunger Games... use your strength and knowledge to overpower other tributes.'" << endl;
            i = 0; 
        }
        else if (option == 2) //cato
        {
            cout << "Here comes your mentor." << endl;
            cout << "Mentor: 'You have trained all of your life for this Hunger Games... use your strength and knowledge to overpower other tributes.'" << endl;
            i = 1; 
        }
        else if (option == 3) //rue
        {
            cout << "Here comes your mentor." << endl;
            cout << "Mentor: 'The other tributes underestimate you... use your agility and intellect to your advantage.'" << endl;
            i = 2; 
        }
        else if (option == 4) //katniss
        {
            cout << "Here comes your mentor." << endl;
            cout << "Mentor: 'You have been a hunter all your life and are very good with a bow... make sure to secure a bow at the Cornucopia.'" << endl; 
            i = 3; 
        }
        else if (option == 5) //make your own 
        {
            string name = ""; 
            int district = 0; 
            
            cout << "What is your name?" << endl; 
            cin >> name; 
            tribute.setName(name); 
            cout << "What district are you from?" << endl; 
            cin >> district; 
            tribute.setDistrict(district); 
            tribute.setHealth(10);
            
            if (district > 0 && district < 3)
            {
                tribute.setScore(0,5); 
                tribute.setScore(1,0);
                tribute.setScore(2,0);
                tribute.setScore(3,0);
            }
            else if (district >= 3 && district < 7)
            {
                tribute.setScore(0,0); 
                tribute.setScore(1,5);
                tribute.setScore(2,0);
                tribute.setScore(3,0);
            }
            else if (district >= 7 && district < 10)
            {
                tribute.setScore(0,0); 
                tribute.setScore(1,0);
                tribute.setScore(2,5);
                tribute.setScore(3,0);
            }
            else if (district >= 10 && district < 12)
            {
                tribute.setScore(0,0); 
                tribute.setScore(1,0);
                tribute.setScore(2,0);
                tribute.setScore(3,5);
            }
            
            tribute.setLocation(0,0); //x-coordinate
            tribute.setLocation(1,0); //y-coordinate
            
            tribute.setEquipmentSize(5);
            cout << "Here comes your mentor." << endl;
            cout << "Mentor: 'The other tributes don't know much about you yet... use this to suprise them.'" << endl;
        }
        else if (option == 6) //quit
        {
            cout << "Good bye!" << endl;
            option = -1; 
        }
        else 
        {
            cout << "Invalid option. Pick again." << endl; 
            option = 7; 
        }
        
        if (option > 0 && option < 5)
        {
            tribute.setName(characters[i].getName()); 
            tribute.setDistrict(characters[i].getDistrict()); 
            tribute.setHealth(characters[i].getHealth()); 
            tribute.setScore(0, characters[i].getScores(0));
            tribute.setScore(1, characters[i].getScores(1));
            tribute.setScore(2, characters[i].getScores(2));
            tribute.setScore(3, characters[i].getScores(3));
            tribute.setNumItems(characters[i].getNumItems()); 
            tribute.setEquipmentSize(characters[i].getEquipmentSize());
        }
    }
    while (option != -1);
    
    bool alive = true; 
    int keepPlaying = 0; 
    int days = 0; //each turn is a day
    
    while (alive == true && keepPlaying != 2) //loop that runs the game
    {
        if (days > 0)
        {
            cout << "It is now day " << days << "in the arena." << endl; 
            cout << "Do you wish to continue? Type 1 to continue or 2 to give up." << endl; 
            cin >> keepPlaying; 
        }
        if (keepPlaying != 2)
        {
            alive = game.move(tribute); 
            days++; 
        }
    }
    
    if (alive == false || keepPlaying == 2)
    {
        game.printStats(tribute, days); 
    }
    return 0; 
}}



