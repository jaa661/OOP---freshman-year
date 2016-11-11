/*
 * Jacob Abbott
 * 1124 c++ recitation
 * recitation 9 separate compilation
 */


#include <fstream>
#include "Registrar.h"
#include <iostream>
#include <sstream>
using namespace BrooklynPoly;
using namespace std;

void readFile(string filename, Registrar& registrar);

int main() {

    Registrar registrar;
/*
    cout << "No courses or students added yet\n";
    //cout << registrar << endl;  // or 
    registrar.printReport();
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    //cout << registrar << endl;  // or 
    registrar.printReport();

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    //cout << registrar << endl;  // or 
    registrar.printReport();

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
   // cout << registrar << endl;  // or 
    registrar.printReport();

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    //cout << registrar << endl;  // or 
    registrar.printReport();

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    //cout << registrar << endl;  // or 
    registrar.printReport();

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    //cout << registrar << endl;  // or 
    registrar.printReport();
   
    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  // or registrar.printReport()

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  // or registrar.printReport()

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  // or registrar.printReport()
    *//*

    cout << "Purge for start of next semester\n";
    registrar.purge();
    //cout << registrar << endl;  // or 
    registrar.printReport();
         */
         
    string fileName = "input.txt";
   readFile(fileName, registrar);
}


void readFile(string filename, Registrar& registrar){
     ifstream ifs(filename);                     
    if (!ifs){
      cerr << " ahhhh shucks. the file could not be opened\n";
      exit(1);}
     string line;
    while (getline(ifs, line)) {
        istringstream ifs2(line);
	string word;
	ifs2 >> word;
	if (word == "PrintReport") {
            registrar.printReport();
        } else if (word == "AddCourse") {
            string courseTitle;
            if(ifs2 >> courseTitle)
             registrar.addCourse(courseTitle);
            else
                cout << "not an acceptable parameter"<<endl;
        } else if (word == "AddStudent") {
            string studentName;
            if(ifs2 >> studentName)
                registrar.addStudent(studentName);
            else
                cout << "not an acceptable parameter"<<endl;
        } else if (word == "EnrollStudentInCourse") {
            string studentName;
            string courseTitle;
            if(ifs2 >> studentName >> courseTitle)
                registrar.enrollStudentInCourse(studentName, courseTitle);
            else
                cout << "not an acceptable parameter"<<endl;
        } else if (word == "CancelCourse") {
            string courseTitle;
            if(ifs2 >> courseTitle)
                registrar.cancelCourse(courseTitle);
            else
                cout << "not an acceptable parameter"<<endl;
        } else if (word == "Purge") {
            registrar.purge();
        } else {
            cerr<<word<< " is not an acceptable command!"<< endl;
        }
    }
}