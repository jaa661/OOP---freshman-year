/* HW04
* Jacob Abbott 
* cs 1124
* The purpose of this homework assignment is to practice  
* coding with dynamic memory. We will be editing Hw03
* to keep track of the nobles, the unemployed warriors,
* and to create new warriors on the heap.
*/

#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Warrior {
public:
    Warrior(const string& myName, const double myStrength) : name(myName), strength(myStrength) {
            employed = false;
	}
    
    //============================accessors
    bool Employment() const { 
        return employed; 
    }
    
    void display() const { 
        cout << name << ": " << strength << endl; 
    }
    
    double getStrength() const { 
        return strength; 
    }
   
    string getName() const {
        return name; 
    }   
    
    //===========================mutators
    void setEmployment(bool hired) { 
        employed = hired; 
    }
    
        void damageTaken(double ratio) {
		strength = strength*ratio;
    }//new health will be old times ratio which is 1-(weak/strong)
private:
	string name;
	double strength;
	bool employed;
};

class Noble {
public:
    Noble(const string& name) : name(name) {
        dead = false;
    }
    
    void hire(Warrior* warrior) {
 
        if (warrior->Employment()) {
            cout << "This warrior is already employed" << endl;
	}
	else {
            army.push_back(warrior);
		warrior->setEmployment(true);
        }
    }// hires a warrior to a nobles army
    
    size_t findWarrior(const Warrior* warrior) {
        for (size_t i = 0; i < army.size(); i++) {
            if (army[i]->getName() == warrior->getName()) return i;
        }
	return -1;
    }//used for matching names to warriors
    
    void fire(Warrior* warrior) {
        int index = findWarrior(warrior);
	if (index == -1) {
            cout << "This warrior does not work for this noble" << endl;
	}
        else{
	cout <<warrior->getName() << ", You're fired! " <<  "-- " << name << "." << endl;
        
        	army[index] = army.back();  //remember this
		army.pop_back();
		warrior->setEmployment(false);
        }
        //warrior->damageTaken(0);     kills fired warrior
    }//eliminates a warrior from an army
     //I thought that we were told if a warrior was fired he was killed
     //unsure if this still applies, but I will assume it does not
    
    void display() const {
	cout << name << " has an army of " << army.size() << endl;
        for (Warrior* warrior : army) {
            cout << "     ";
            warrior->display();
        }
    }
    
    string getName() const {
	return name;
    }
    
    bool deadOrAlive() const {
	return dead;
    }
    
    void kill(bool status) {
        dead = status;
    }
    double getStrength() const {
        double strength = 0;
        for (Warrior* warrior : army) {
        	strength += warrior->getStrength();
	}
	return strength;
    }
    
    void dealDamage(double ratio) {
	for (Warrior* warrior : army) {
		warrior->damageTaken(ratio);
            }
    }
    
    void battle(Noble* enemy) {
	cout << name << " battles " << enemy->getName() << endl;
	if ((deadOrAlive()) &&(enemy->deadOrAlive())) {
            cout << " Oh no! They're both already dead!" << endl;
        }//if both are dead
        
        else if (enemy->deadOrAlive()) {
            cout << "he's already dead " << name << endl;
        }// if enemy is dead
        
        else if (deadOrAlive()) {
            cout << "he's already dead " << enemy->getName() << endl;
        }// if i am dead
        
        else if (getStrength() > enemy->getStrength()) {
            double ratio = (enemy->getStrength()/getStrength());
            dealDamage(1 - ratio);
            enemy->dealDamage(0);
            enemy->kill(true);
            cout << name << " defeats " << enemy->getName() << endl;
	}// if I am stronger
        
        else if (getStrength() < enemy->getStrength()) {
            double ratio = (getStrength()/enemy->getStrength());
            dealDamage(0);
            kill(true);
            enemy->dealDamage(1 - ratio);
            cout << enemy->getName() << " defeats " << name << endl;
	}//if the enemy is stronger
        
        else {
            dealDamage(0);
            enemy->dealDamage(0);
            enemy->kill(true);
            kill(true);
            cout << "Mutual Annihilation: " << name << " and " << enemy->getName() << " die at each other's hands" << endl;
		}
	}//if we have the same health
    
private:
	string name;
        bool dead;
	vector<Warrior*> army;
};

//====prototyping=========================
int findWarrior(vector<Warrior*> warriors, const string& warrior);
int findNoble(vector<Noble*> nobles, const string& noble);
bool noAvailableWarriors(vector<Warrior*> warriors);

//======================================================================main
int main() {
    ifstream ifs("nobleWarriors.txt");                     
    if (!ifs){
      cerr << " ahhhh shucks. the file nobleWarriors.txt could not be opened\n";
      exit(1);} 
    vector<Warrior*> warriors;
    vector<Noble*> nobles;
    string command;   
    
 while(ifs >> command){
     
     if(command == "Noble"){
         string name;
         ifs >> name;
         bool checkname = true;
         for (Noble* tempNoble : nobles){
             if(name == tempNoble->getName()){
                 cout << "ooh... sorry but a noble with this name already exists."<<endl;
                 checkname = false;}}
         if (checkname)
             nobles.push_back(new Noble(name));
         
     }
     else if(command == "Warrior"){
         string name;
         int strength;
         bool checkname = true;
         ifs >> name >> strength;
         for (Warrior* tempWarrior : warriors)
             if(name == tempWarrior->getName()){
                 cout << "ooh... sorry but a warrior with this name already exists."<<endl;
                 checkname = false;}
         if (checkname)
             warriors.push_back(new Warrior(name, strength));
     }
     else if(command == "Hire"){
         string noble, warrior;
         ifs >> noble >> warrior;
         if ((findNoble(nobles, noble) >= 0)&&(findWarrior(warriors, warrior) >= 0)){
             nobles[findNoble(nobles, noble)]->hire(warriors[findWarrior(warriors, warrior)]);
         }
         else 
             if (findNoble(nobles, noble) > 0)
                cout << "I'm sorry but that Warrior doesn't exist" << endl;
             else
                cout << "I'm sorry but that Noble doesn't exist" << endl;
     }
     
     else if(command == "Fire"){
         string noble, warrior;
         ifs >> noble >> warrior;
         if ((findNoble(nobles, noble) >= 0)&&(findWarrior(warriors, warrior) >= 0)){
         nobles[findNoble(nobles, noble)]->fire((warriors[findWarrior(warriors, warrior)]));
         }
         else 
             if (findNoble(nobles, noble) > 0)
                cout << "I'm sorry but that Warrior doesn't exist" << endl;
             else
                cout << "I'm sorry but that Noble doesn't exist" << endl;

     }
     
     else if(command == "Status"){
         cout << "Status\n===========\nNobles:\n";
         if (nobles.size() == 0)
             cout << "NONE\n";
         else{  
             for (Noble* tempNoble : nobles){
             tempNoble->display();
             }
         }
         cout << "Unemployed Warriors:\n";
             if(!noAvailableWarriors(warriors)){
                 for (Warrior* tempWarrior : warriors){
                    if (tempWarrior->Employment() == false)
                        tempWarrior->display();
                 }
             }
             else{
                 cout << "NONE\n";
         }
     }
     
     else if(command == "Battle"){
         string firstNoble;
         string secondNoble;
         ifs >> firstNoble >> secondNoble;
         nobles[findNoble(nobles, firstNoble)]->battle((nobles[findNoble(nobles, secondNoble)]));
     }
     else if(command == "Clear"){
         for (Warrior* tempWarrior : warriors)
             delete tempWarrior;
         warriors.clear();
         
         for (Noble* tempNoble : nobles)
             delete tempNoble;
         nobles.clear();
     }
     else{
         cout << "command not recognized\n";
         cout << command;}
 } 
}

int findNoble(vector<Noble*> nobles, const string& noble) {
        for (int i = 0; i < nobles.size(); i++) {
            if (nobles[i]->getName() == noble) return i;
        }
	return -1;
    }

bool noAvailableWarriors(vector<Warrior*> warriors){
    bool out = true;
    for(Warrior* tempWarrior : warriors){
        if(tempWarrior->Employment() == false)
            out = false;
    }
    return out;
}

int findWarrior(vector<Warrior*> warriors, const string& warrior) {
        for (int i = 0; i < warriors.size(); i++) {
            if (warriors[i]->getName() == warrior) return i;
        }
	return -1;
    }
//=================================================================end main