/* HW06
* Jacob Abbott 
* cs 1124
* This program will use cyclic association and separate compilation
* to run the warrior program previously made. 
*/

#include "Noble.h"
#include "Warrior.h"
using namespace std;

namespace WarriorCraft {
    Noble::Noble(const string& name) : name(name) {}
    
    void Noble::hire(Warrior& warrior) {
        if (warrior.Employment()) {
            cout << "This warrior is already employed" << endl;
	}
	else {
            army.push_back(&warrior);
		warrior.setEmployment(true);
                warrior.setEmployer(this);
        }
    }// hires a warrior to a nobles army if free
    size_t Noble::findWarrior(Warrior*& warrior) {
        for (size_t i = 0; i < army.size(); i++) {
            if (army[i] == warrior) return i;
        }
	return -1;
    }//used for matching names to warriors
    void Noble::runaway(Warrior* warrior) {
        int index = findWarrior(warrior);
        army[index] = army[army.size()];
	army.pop_back();
	warrior->setEmployment(false);
        //warrior->damageTaken(0);
    }//eliminates a warrior from an army, (also kills him) not anymore
    void Noble::fire(Warrior* warrior) {
        int index = findWarrior(warrior);
        if (index == -1) {
            cout << "This warrior does not work for this noble" << endl;
         }
        else{
            cout <<warrior->getName() << "You're fired! " <<  "!  -- " << name << "." << endl;
        
        	army[index] = army[army.size()];
		army.pop_back();
		warrior->setEmployment(false);
        }
        //warrior->damageTaken(0);
    }//eliminates a warrior from an army, also kills him
    void Noble::display(ostream& os) const {
	os << name << " has an army of " << army.size() << endl;
		for (Warrior* warrior : army) {
			os << "    " << *warrior << endl;
		}
    }
    ostream& operator<<(ostream& os, const Noble& noble) {
        noble.display(os);
        return os;
    }
    std::string Noble::getName() {
	return name;
    }  
    double Noble::getStrength() const {
        double strength = 0;
        for (Warrior* warrior : army) {
        	strength += warrior->getStrength();
	}
	return strength;
    } //returns the total strength of 
    void Noble::dealDamage(double ratio) {
	for (Warrior* warrior : army) {
		warrior->damageTaken(ratio);
            }
    }
    
    void Noble::battle(Noble& enemy) {
	cout << name << " battles " << enemy.getName() << endl;
	if ((getStrength() == 0) &&(enemy.getStrength() == 0)) {
            cout << "Oh no! They're both already dead!" << endl;
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
    
}