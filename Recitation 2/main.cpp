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

void openFile(ifstream& ifs);
void fillMolecules(ifstream& ifs, vector<vector<string> >& molecules);
void printMolecules(const vector<vector<string> >& molecules);

int main() {
    
    vector<vector<string> > molecules;
    ifstream ifs;
    
    openFile(ifs);
    fillMolecules(ifs, molecules);
    printMolecules(molecules);
    
}

void openFile(ifstream& ifs){
   
    ifs.open("chemicals.txt");                     // declare the input stream 
    if (!ifs){
      cerr << " ahhhh shucks. the file chemicals.txt could not be opened\n";
      exit(1);}                                        // check to see if the stream can be accessed
}


void fillMolecules(ifstream& ifs, vector<vector<string> >& molecules){
    
    string name;
    string formula;
   
    while(ifs >> name >> formula ){
        vector<string> molecule;
        
        molecule.push_back(name);
        molecule.push_back(formula);
        molecules.push_back(molecule);
    }
}

void printMolecules(const vector<vector<string> >& molecules){
    
    for(size_t i = 0; i < molecules.size(); i++){
      cout << molecules[i][1] << " ";
      cout << molecules[i][0] << endl;
    }
    cout << "=====================" << endl;
    
    for( vector<string> molecule : molecules){
      cout << molecule[1] << " ";
      cout << molecule[0] << endl;
    }
    
}