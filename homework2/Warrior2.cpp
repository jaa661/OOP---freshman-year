/* HW02
* Jacob Abbott 
* cs 1124
* The purpose of this homework assignment is to practice data hiding, 
* encapsulation, and delegation. I have to create a game like program
* that is controlled by an input file. warriors will be made, 
* pitted against each other, and analyzed. Now, each warrior has a weapon
* 
*/

#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Weapon {
public:
    Weapon(){}
    Weapon(const string& name, int strength) : myName(name), myStrength(strength){}

    void displayWeapon() const {
        cout << " " << myName << ", " << myStrength << endl;
    } // display the weapons statistics
    //======accessors
        string getName() const {
        return myName;
    } // display the warrior
    
    int getStrength() const {
        return myStrength;
    } // display the warrior
    
//=============mutators=================
    void setStrength(int strength){
         myStrength = strength;
    } // display the warrior
    

private:
    string myName;
    int myStrength;
    
};

class Warrior {
public:
    Warrior(){}
    Warrior(const string& name, Weapon& weapon, int index) : myName(name), 
           myWeapon(weapon), position(index){}
    void displayWarrior() const {
        cout << "Warrior: " << myName << ", weapon:";
        myWeapon.displayWeapon();
    } // display the warrior
       
    //=======accessors
    string getName() const {
        return myName;
    } // display the warrior
    
    int getPosition() const {
        return position;
    } // display the warrior
    
    int getWeaponStrength() const {
        return myWeapon.getStrength();
    } // display the warrior
    
    Weapon getWeapon() {
        return myWeapon;
    } // display the warrior
    
//=============mutators=================
    void setWeaponStrength(int newStrength) {
        myWeapon.setStrength(newStrength);
    } // display the warrior

private:
    string myName;
    Weapon myWeapon;
    int position;
    
};

//====prototyping
void makeWarrior(vector<Warrior>& warriors, const string& name, const string& weaponName, int strength);
void startBattle(vector<Warrior>& warriors, const string& firstName, const string& secondName);
void getStatus(const vector<Warrior>& warriors);
int findWarrior(const vector<Warrior>& warriors, const string& firstName);


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
         string weaponName;
         int strength;
         
         ifs >> name >> weaponName >> strength;
         makeWarrior(warriors, name, weaponName, strength);
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
void makeWarrior(vector<Warrior>& warriors, const string& name, const string& weaponName, int strength){
    Weapon currentWeapon(weaponName, strength);
    Warrior currentWarrior(name, currentWeapon, (warriors.size()));
    warriors.push_back(currentWarrior);
}
//=============================================================================
// get and print out the names and strength of the warriors
void getStatus(const vector<Warrior>& warriors){
    cout << "there are: " << warriors.size() << " warriors" << endl;
    Warrior currentWarrior;
    for (Warrior currentWarrior : warriors){
        currentWarrior.displayWarrior();
    }    
}
//=============================================================================
// initiate a battle between 2 passed in names
void startBattle(vector<Warrior>& warriors, const string& firstName, const string& secondName){
    cout << firstName << " battles " << secondName << endl;
    int firstWarriorIndex;
    int secondWarriorIndex;
    
    firstWarriorIndex = findWarrior(warriors, firstName);
    secondWarriorIndex = findWarrior(warriors, secondName);
    
    if((warriors[firstWarriorIndex].getWeaponStrength() == 0)&&(warriors[secondWarriorIndex].getWeaponStrength() == 0)){
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }// if both are dead
    
    else if(warriors[firstWarriorIndex].getWeaponStrength() == warriors[secondWarriorIndex].getWeaponStrength()){
        cout << "Mutual Annihilation: "<< firstName << " and " ;
        cout << secondName <<" die at each other's hands" << endl;
        warriors[firstWarriorIndex].setWeaponStrength(0);
        warriors[secondWarriorIndex].setWeaponStrength(0);
    }// if they have the same strength
    
    else if(warriors[firstWarriorIndex].getWeaponStrength() == 0){
        cout << "he's dead, " << secondName << endl;
    }// if one of them is dead
    
    else if(warriors[secondWarriorIndex].getWeaponStrength() == 0){
        cout << "he's dead, " << firstName << endl;
    }// if the other one of them is dead
    
    else if((warriors[firstWarriorIndex].getWeaponStrength() > 0)
            &&(warriors[secondWarriorIndex].getWeaponStrength() > 0)){
        
        if( warriors[firstWarriorIndex].getWeaponStrength() > warriors[secondWarriorIndex].getWeaponStrength())
            cout<< firstName << " defeats " 
                    << secondName << endl;
        else         
            cout<< secondName << " defeats " 
                    << firstName << endl;

        warriors[firstWarriorIndex].setWeaponStrength(warriors[firstWarriorIndex].getWeaponStrength() - 
                warriors[secondWarriorIndex].getWeaponStrength());
        warriors[secondWarriorIndex].setWeaponStrength(warriors[secondWarriorIndex].getWeaponStrength() - 
                (warriors[firstWarriorIndex].getWeaponStrength() + warriors[secondWarriorIndex].getWeaponStrength()));
       
    
    }//standard battle 
    
    if(warriors[firstWarriorIndex].getWeaponStrength() < 0)
        warriors[firstWarriorIndex].setWeaponStrength(0);
    if(warriors[secondWarriorIndex].getWeaponStrength() < 0)
        warriors[secondWarriorIndex].setWeaponStrength(0);
    //make sure neither warrior has a strength less than 0 after calculations
}
//=============================================================================
//use this to identify which warrior is in
int findWarrior(const vector<Warrior>& warriors, const string& name){
    int index = 0;
    for (Warrior currentWarrior : warriors){
        if (currentWarrior.getName() == name)
            index = currentWarrior.getPosition();
    }
      return index;
}
