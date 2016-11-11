/* 
 * Recitation 4
 * Jacob Abbott 
 * cs 1124
 *
 * Created on September 25, 2015, 8:06 AM
 */

#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/*
 * 
 */

class Sandwich {
public:
    Sandwich(int tomatoAmount = 2, int cheeseAmount = 1, double mustardAmount = .05, double mayoAmount = 1) 
            : tomatoes(tomatoAmount), cheese(cheeseAmount), mustard(mustardAmount), mayo(mayoAmount), bread(2) {}
    void display() const {
        cout << "This sandwich contains:" << endl;
        cout << bread << " slices of bread"<< endl;
        cout << cheese << " slices of cheese"<< endl;
        cout << tomatoes << " slices of tomatoes"<< endl;
        cout << mayo << " ounces of mayo"<< endl;
        cout << mustard<< " ounces of mustard"<< endl << endl;
    } // display the contents of this sandwich
//=============accessors=================
    double getMustard() const{
        return mustard;
    }
    double getMayo() const{
        return mayo;
    }
    int getBread() const{
        return bread;
    }
    int getTomatoes() const{
        return tomatoes;
    }
    int getCheese() const{
        return cheese;
    }
//=============mutators=================
    void setMustard(int mustardInput){
        mustard = mustardInput;
    }
    void setMayo(int mayoInput){
        mayo = mayoInput;
    }
    //void setBread(int breadInput){
    //    bread = breadInput;
    //}
    void setCheese(int cheeseInput){
        cheese = cheeseInput;
    }
    void setTomatoes(int tomatoesInput){
        tomatoes = tomatoesInput;
    }
//=======private
private:
   const int bread;
    int cheese;
    int tomatoes;
    double mayo;
    double mustard;
};

class SandwichTruck {
public:
    SandwichTruck(){}
    SandwichTruck(const vector<Sandwich>& contents) : truckContents(contents){}
    void checkBeforeLeaving() const {
        //for(size_t i = 0; i < truckContents.size(); i++){
        //    truckContents[i].display();
        //}  I just wrote this for practice
        for(Sandwich currentSandwich : truckContents){
            currentSandwich.display();
        }
    } // display each sandwich contained in the truck
//=============mutators=================
    void insertSandwich(Sandwich incomingSandwich){
        truckContents.push_back(incomingSandwich);
    } // mutators for sandwiches in the truck

//=======private
private:
    vector<Sandwich> truckContents;
};
int main() {
    SandwichTruck bobsBurgers;
    
   //scenario!!!
    Sandwich customer1;
    bobsBurgers.insertSandwich(customer1);
    
    Sandwich customer2;
    customer2.setMustard(0);
    bobsBurgers.insertSandwich(customer2);
    
    Sandwich customer3(2, 2);
    bobsBurgers.insertSandwich(customer3);

    Sandwich customer4;
    bobsBurgers.insertSandwich(customer4);
    
    bobsBurgers.checkBeforeLeaving();
    cout << "customer 2 has " << customer2.getMustard() 
            << " ounces of mustard on their sandwich" << endl;

    return 0;
}

