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
#include <vector>
using namespace std;

class Lord;

class Protector {
public:
    Protector(const string& myName, double myStrength) : 
        name(myName), strength(myStrength), master(nullptr) {}
    virtual 
    void defend() const = 0;
    bool isFree() const {
        return !master; 
    }
    bool isAlive() const {
        return strength != 0; 
    }
    void setMaster(Lord* newMaster) {
        master = newMaster; 
    }
    double getStrength() {
        return strength; 
    }
    void decreaseStrength(double value) {
        strength -= value;
        if (strength < 0) strength = 0;
    }
    
protected:
    string name;
    double strength;
    Lord* master;
};


class Noble {
public:
    Noble(const string& myName) : name(myName) {
        bool isDead = false;
    }
 //=========================================accessors   
    string getName() const {
        return name; 
    }
    virtual 
    double getStrength() const = 0;
    virtual 
    void decreaseStrength(double value) = 0;
    bool getDead(){
        return isDead;
    }
    void setDead(){
        isDead = true;
    }
//==========================================battle
    void battle(Noble& foe) {
        cout << getName() << " battles " << foe.getName() << endl;
        if (isDead && foe.getDead()){
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        }else if (isDead){
            cout << getName() << " is already dead, " << foe.getName() << endl;
        }else if (foe.getDead()){
            cout << foe.getName() << " is already dead, " << getName() << endl;
        } else if (getStrength() > foe.getStrength()) {
            double ratio = foe.getStrength()/getStrength();
            decreaseStrength(ratio);
            foe.decreaseStrength(foe.getStrength());
            foe.setDead();
            cout << getName() << " defeats " << foe.getName() << endl;
        } else{
            double ratio = getStrength()/foe.getStrength();
            decreaseStrength(getStrength());
            foe.decreaseStrength(ratio);
            isDead = true;
            cout << foe.getName() << " defeats " << getName() << endl;
        } 
        
    }
    
protected:
    string name;
    bool isDead;
};


class Lord : public Noble {
public:
    Lord(const string& myName) : Noble(myName) {}
    void hires(Protector& protector) {
        if (protector.isFree()) {
            protector.setMaster(this);
            protectors.push_back(&protector);
        }
    }
    double getStrength() const {
        double strength = 0;
        for (Protector* protector : protectors)
            strength += protector->getStrength();
        return strength;
    }
    void decreaseStrength(double value) {
        for (Protector*& protector : protectors) {
            if (protector->isAlive()) {
                protector->defend();
                protector->decreaseStrength(value);
            }
        }
    }
    
private:
    vector<Protector*> protectors;
};


class NobleFighter : public Noble {
public:
    NobleFighter(const string& myName, double myStrength) : Noble(myName), strength(myStrength) {}
    double getStrength() const {
        return strength; 
    }
    void decreaseStrength(double value) {
        strength -= value;
    }
    
private:
    double strength;
};


class Wizard : public Protector {
public:
    Wizard(const string& myName, double myStrength) : Protector(myName, myStrength) {}
    void defend() const {
        cout << "POOF! " << endl;
    }
};


class Warrior : public Protector {
public:
    Warrior(const string& myName, double myStrength) : Protector(myName, myStrength) {}
    virtual void defend() const = 0;
};

void Warrior::defend() const {
    cout << name << " says: Take that in the name of my lord, " << master->getName() << endl;
}


class Archer : public Warrior {
public:
    Archer(const string& myName, double myStrength) : Warrior(myName, myStrength) {}
    void defend() const {
        cout << "TWANG! ";
        Warrior::defend();
    }
};


class Swordsman : public Warrior {
public:
    Swordsman(const string& myName, double myStrength) : Warrior(myName, myStrength) {}
    void defend() const {
        cout << "CLANG! ";
        Warrior::defend();
    }
};


int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    NobleFighter randy("Randolf the Elder", 250); 	
    joe.battle(randy);	
    joe.battle(sam);	
    Lord janet("Janet");	
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);	
    janet.hires(stout);	
    NobleFighter barclay("Barclay the Bold", 300);	
    janet.battle(barclay);	
    janet.hires(samantha);	
    Archer pethora("Pethora", 50);	
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);	
    sam.battle(barclay);	
    joe.battle(barclay);
}