/* HW06
* Jacob Abbott 
* cs 1124
* This program will use cyclic association and separate compilation
* to run the warrior program previously made. 
*/

#include "Warrior.h"
#include "Noble.h"
using namespace std;

namespace WarriorCraft {
    Warrior::Warrior(const std::string& myName, const double myStrength) : name(myName), strength(myStrength) {
        employed = false;
    }
    
    //============================accessors
    bool Warrior::Employment() const { 
        return employed; 
    }
    void Warrior::setEmployer(Noble* noble) { 
        employer = noble; 
    }
    void Warrior::display(std::ostream& os) const {
        os << name << ": " << strength;
    }
    ostream& operator<<(ostream& os, const Warrior& warrior) {
        warrior.display(os);
        return os;
    }
    double Warrior::getStrength() const { 
        return strength; 
    }
    string Warrior::getName() const {
        return name; 
    }   
    //===========================mutators
    void Warrior::setEmployment(bool hired) { 
        employed = hired; 
    }
    void Warrior::damageTaken(double ratio) {
        strength = strength*ratio;
    }
    void Warrior::runaway() {
        if (Employment()) {
            cout << name << " flees in terror, abandoning his lord, "; 
            cout << employer->getName() << endl;
            employer->runaway(this);
            employer = nullptr;
        }
    }
}