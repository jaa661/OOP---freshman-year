/* HW01
* Jacob Abbott 
* cs 1124
* The purpose of this homework assignment is to practice functions,structs, and
* vectors. I have to create a game like program that is controlled by an input
* file. warriors will be made, pitted against each other, and analyzed.
* 
*/

#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Warrior {
    string name;
    int strength;
};

void makeWarrior(vector<Warrior>& warriors, const string& name, int strength);
void startBattle(vector<Warrior>& warriors, const string& firstName, const string& secondName);
void getStatus(const vector<Warrior>& warriors);


//======================================================================pregame
int main() {
      
 ifstream ifs("warriors.txt");                     
    if (!ifs){
      cerr << " ahhhh shucks. the file warriors.txt could not be opened\n";
      exit(1);}          
 vector<Warrior> warriors;
 string command;   
 
 while(ifs >> command){
     if(command == "Warrior"){
         string name;
         int strength;
         ifs >> name >> strength;
         makeWarrior(warriors, name, strength);
         
     }
     else if(command == "Status"){
         getStatus(warriors);
         
     }
     else if(command == "Battle"){
         string firstWarrior;
         string secondWarrior;
         ifs >> firstWarrior >> secondWarrior;
         startBattle(warriors, firstWarrior, secondWarrior);
     }
 }
    
    
    
    return 0;
}

//=============================================================================
// create a warrior with a passed in name and strength
void makeWarrior(vector<Warrior>& warriors, const string& name, int strength){
    Warrior currentWarrior;
    currentWarrior.name = name;
    currentWarrior.strength = strength;
    warriors.push_back(currentWarrior);
}
//=============================================================================
// get and print out the names and strength of the warriors
void getStatus(const vector<Warrior>& warriors){
    cout << "there are: " << warriors.size() << " warriors" << endl;
    Warrior currentWarrior;
    for (currentWarrior : warriors){
        cout << "Warrior: " << currentWarrior.name <<", strength: ";
        cout << currentWarrior.strength << endl;

    }
    
    
}
//=============================================================================
// initiate a battle between 2 passed in names
void startBattle(vector<Warrior>& warriors, const string& firstName, const string& secondName){
    cout << firstName << " battles " << secondName << endl;
    int index = 0;
    int firstWarriorIndex;
    int secondWarriorIndex;
    
    while ( firstName != warriors[index].name){
        index ++;
    }
    firstWarriorIndex = index;  // find the index of the first warrior
    
    index = 0;  // reset the index to search again
    while (secondName != warriors[index].name){
        index ++;
    }
    secondWarriorIndex = index; 
    
    if((warriors[firstWarriorIndex].strength == 0)&&(warriors[secondWarriorIndex].strength == 0)){
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }// if both are dead
    
    else if(warriors[firstWarriorIndex].strength == warriors[secondWarriorIndex].strength){
        cout << "Mutual Annihilation: "<< warriors[firstWarriorIndex].name << " and " ;
        cout << warriors[secondWarriorIndex].name <<" die at each other's hands" << endl;
        warriors[firstWarriorIndex].strength = 0;
        warriors[secondWarriorIndex].strength = 0;
    }// if they have the same strength
    
    else if(warriors[firstWarriorIndex].strength == 0){
        cout << "he's dead, " << warriors[secondWarriorIndex].name << endl;
    }// if one of them is dead
    
    else if(warriors[secondWarriorIndex].strength == 0){
        cout << "he's dead, " << warriors[firstWarriorIndex].name << endl;
    }// if the other one of them is dead
    
    else if((warriors[firstWarriorIndex].strength > 0)
            &&(warriors[secondWarriorIndex].strength > 0)){
        
        if( warriors[firstWarriorIndex].strength > warriors[secondWarriorIndex].strength)
            cout<< warriors[firstWarriorIndex].name << " defeats " 
                    << warriors[secondWarriorIndex].name << endl;
        else         
            cout<< warriors[secondWarriorIndex].name << " defeats " 
                    << warriors[firstWarriorIndex].name << endl;

        warriors[firstWarriorIndex].strength = warriors[firstWarriorIndex].strength - 
                warriors[secondWarriorIndex].strength;
        warriors[secondWarriorIndex].strength = warriors[secondWarriorIndex].strength - 
                (warriors[firstWarriorIndex].strength + warriors[secondWarriorIndex].strength);
    
    }//standard battle 
    
    if(warriors[firstWarriorIndex].strength < 0)
        warriors[firstWarriorIndex].strength = 0;
    if(warriors[secondWarriorIndex].strength < 0)
        warriors[secondWarriorIndex].strength = 0;
    //make sure neither warrior has a strength less than 0 after calculations
}
