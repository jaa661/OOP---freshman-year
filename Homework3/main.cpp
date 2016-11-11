/* HW03
* Jacob Abbott 
* cs 1124
* The purpose of this homework assignment is to practice classes 
* and association. I have to create a game-like program
* that is controlled by a series of commands in the main.
* Nobles will control armies of warriors and fight each other.
* The program should be Object Oriented.
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
    Noble(const string& name) : name(name) {}
    
    void hire(Warrior& warrior) {
 
        if (warrior.Employment()) {
            cout << "This warrior is already employed" << endl;
	}
	else {
            army.push_back(&warrior);
		warrior.setEmployment(true);
        }
    }// hires a warrior to a nobles army
    
    size_t findWarrior(const Warrior& warrior) {
        for (size_t i = 0; i < army.size(); i++) {
            if (army[i] == &warrior) return i;
        }
	return -1;
    }//used for matching names to warriors
    
    void fire(Warrior& warrior) {
        int index = findWarrior(warrior);
	if (index == -1) {
            cout << "This warrior does not work for this noble" << endl;
	}
        else{
	cout <<warrior.getName() << "You're fired! " <<  "!  -- " << name << "." << endl;
        
        	army[index] = army[army.size()];
		army.pop_back();
		warrior.setEmployment(false);
        }
        warrior.damageTaken(0);
    }//eliminates a warrior from an army, also kills him
    
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
    
    void battle(Noble& enemy) {
	cout << name << " battles " << enemy.getName() << endl;
	if ((getStrength() == 0) &&(enemy.getStrength() == 0)) {
            cout << " Oh no! They're both already dead!" << endl;
        }//if both are dead
        
        else if (enemy.getStrength() == 0) {
            cout << "he's already dead " << name << endl;
        }// if enemy is dead
        
        else if (getStrength() == 0) {
            cout << "he's already dead " << enemy.getName() << endl;
        }// if i am dead
        
        else if (getStrength() > enemy.getStrength()) {
            double ratio = (enemy.getStrength()/getStrength());
            dealDamage(1 - ratio);
            enemy.dealDamage(0);
            cout << name << " defeats " << enemy.getName() << endl;
	}// if I am stronger
        
        else if (getStrength() < enemy.getStrength()) {
            double ratio = (getStrength()/enemy.getStrength());
            dealDamage(0);
            enemy.dealDamage(1 - ratio);
            cout << enemy.getName() << " defeats " << name << endl;
	}//if the enemy is stronger
        
        else {
            dealDamage(0);
            enemy.dealDamage(0);
            cout << "Mutual Annihilation: " << name << " and " << enemy.getName() << " die at each other's hands" << endl;
		}
	}//if we have the same health
    
private:
	string name;
	vector<Warrior*> army;
};

//====prototyping=========================

//======================================================================main
int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}
//=================================================================end main