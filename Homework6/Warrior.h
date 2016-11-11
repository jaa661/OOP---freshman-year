/* HW06
* Jacob Abbott 
* cs 1124
* This program will use cyclic association and separate compilation
* to run the warrior program previously made. 
*/
#ifndef hw06_Warrior
#define hw06_Warrior

#include "Noble.h"
#include <iostream>
#include <string>

namespace WarriorCraft {
//    class Noble;
    
    class Warrior {
    public:
        Warrior(const std::string& name, double strength);
     
        bool Employment() const;
        void setEmployer(Noble* noble);
        void display(std::ostream& os) const;
        double getStrength() const;
        std::string getName() const;
        void setEmployment(bool hired);
        void damageTaken(double ratio);
        void runaway();
        
    private:
	std::string name;
	double strength;
        Noble* employer;
	bool employed;
};
    
    std::ostream& operator<<(std::ostream& os, const Warrior& warrior);
}

#endif /* defined(hw06_Warrior) */
