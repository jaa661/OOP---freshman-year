/* 
 * HW00
 * Jacob Abbott 
 * cs 1124
 *
 * Created on September 11, 2015, 7:59 AM
 */

#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Molecule {
    vector<string> formulaName;
    int carbonAtoms;
    int hydrogenAtoms;
};

void openFile(ifstream& ifs);
void fillMolecules(ifstream& ifs, vector<Molecule>& molecules);
void printMolecules(const vector<Molecule>& molecules);
int findMax(const vector<Molecule>& molecules);
int checkDuplicate(const vector<Molecule>& molecules, int numC, int numH);

int main() {
    
    vector<Molecule> molecules;
    ifstream ifs;
    
    openFile(ifs);
    fillMolecules(ifs, molecules);
    printMolecules(molecules);
    
}

void openFile(ifstream& ifs){
   
    ifs.open("hydrocarbons.txt");                     // declare the input stream 
    if (!ifs){
      cerr << " ahhhh shucks. the file hydrocarbons.txt could not be opened\n";
      exit(1);}                                        // check to see if the stream can be accessed
}


void fillMolecules(ifstream& ifs, vector<Molecule>& molecules){
    
    string name;
    char characterHolder;
    int  carbonHolder;
    int  hydrogenHolder;
    
    while(ifs >> name >> characterHolder >> carbonHolder >> characterHolder >> hydrogenHolder){
        Molecule currentHydrocarbon;
        
           if(checkDuplicate(molecules, carbonHolder, hydrogenHolder) < molecules.size()){             
            molecules[checkDuplicate(molecules, carbonHolder, hydrogenHolder)].formulaName.push_back(name);
          }
           else{
               currentHydrocarbon.carbonAtoms = carbonHolder;
            currentHydrocarbon.hydrogenAtoms = hydrogenHolder;
            currentHydrocarbon.formulaName.push_back(name);
            molecules.push_back(currentHydrocarbon);
          }
     
            }
            
        }
        
    
    


void printMolecules(const vector<Molecule>& molecules){
    
    for(size_t i = 0; i < findMax(molecules); i++){
        for(size_t i2 = 0; i2 < molecules.size(); i2++){
           if (molecules[i2].carbonAtoms == i){
              cout << "C" << molecules[i2].carbonAtoms << "H" //cont.
                    << molecules[i2].hydrogenAtoms << endl;    //cont.
                for(size_t i3 = 0; i3 < molecules[i2].formulaName.size(); i3++){
                    cout << molecules[i2].formulaName[i3] << endl;
                }
                 cout << endl;   
           }
        }
    }
    
    
}

int findMax(const vector<Molecule>& molecules){
    int max = 0;
    for(size_t i = 0; i < molecules.size(); i++){
        if (molecules[i].carbonAtoms > max)
            max = molecules[i].carbonAtoms;
    }
    return max;
}

int checkDuplicate(const vector<Molecule>& molecules, int numC, int numH){
    for(size_t i = 0; i < molecules.size(); i++){
            if ((molecules[i].carbonAtoms == numC)&&(molecules[i].hydrogenAtoms == numH))
                return i; 
}
   return molecules.size(); 
}
