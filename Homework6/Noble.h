/* HW06
* Jacob Abbott 
* cs 1124
* This program will use cyclic association and separate compilation
* to run the warrior program previously made. 
*/

#ifndef hw06_Noble
#define hw06_Noble

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
    class Warrior;
    
    class Noble {
    public:
        Noble(const std::string& name);
        
        void hire(Warrior& warrior);
        size_t findWarrior(Warrior*& warrior);
        void fire(Warrior* warrior);
        void runaway(Warrior* warrior);
        void display(std::ostream& os) const;
        std::string getName();
        double getStrength() const; 
        void dealDamage(double value);
        void battle(Noble& foe);
        
        
        
    private:
        std::string name;
        std::vector<Warrior*> army;
    };
    
    std::ostream& operator<<(std::ostream& os, const Noble& noble);
}

#endif /* defined(hw06_Noble) */
