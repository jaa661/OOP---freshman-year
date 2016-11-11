/* Rec6
* Jacob Abbott 
* cs 1124
* 
*/

#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Student {
public:
    Student(const string& name) : myName(name){
        for(int i = 0; i < 13; i++){
            myGrades.push_back(-1);
        }
    }
    //======accessors=============
    void display() const {
        cout << "Student: " << myName << "; Grades: ";
                for (int grade : myGrades){
                    cout << grade << " ";
                }
        cout << endl;
    } // display the student and their grades
    
        string getName() const {
        return myName;
    } // return the students name
    
    int getGrade(int week) const {
        return myGrades[week];
    } // return a given week's grade
    
    //=============mutators========
    void setGrade(int grade, int week){
         myGrades[week] = grade;
    } // set a certain grade
private:
    string myName;
    vector<int> myGrades;
};

class Timeslot {
public:
    Timeslot(const string& weekday, int time) : day(weekday), hour(time){}
    //======accessors=============
    void display(){
        cout << day << " ";
        if (hour > 12){
            hour = hour - 12;
            cout << hour << "PM" << endl;
        }
        else 
            cout << hour << "AM" << endl;

    } // display the Timeslot
    
    //=============mutators========

private:
    string day;
    int hour;
};


class Section {
public:
    Section(const string& name, const string& day, int hour) 
           : myName(name), timeslot(day, hour){}
    //======accessors=============
   void displaySection(){
        cout << "Section: " << myName << "; ";
        timeslot.display();
        cout << endl;
    }
           
    void display() {
        cout << "Section: " << myName << "; ";
        timeslot.display();
        for (Student* currentstudent : myStudents){
            currentstudent->display();
        }
        cout << endl;
    }
    
    void reset(){
        for( Student* currentstudent : myStudents){
            delete currentstudent;
        }
        myStudents.clear();
    }
    
    void loadStudentsFromFile(string filename){
    ifstream ifs(filename);                     
    if (!ifs){
      cerr << " ahhhh shucks. the file warriors.txt could not be opened\n";
      exit(1);}   
    string command;
    while(ifs >> command){
    //load students
    }
    }
    
    void displayStudents() const {
        for (Student* currentstudent : myStudents){
            cout<< currentstudent->getName() << ", ";
        }
        cout << endl;
    } // display the weapons statistics
    
    void displayStudentGrades() const {
        for (Student* currentstudent : myStudents){
            currentstudent->display();
        }
    } // display the weapons statistics
    
        int displaySlot(){
        timeslot.display();
    } // display a given week's grade
        
        string getName() const {
        return myName;
    } // return the name of the section
   
    int findStudent(vector<Student*>& myStudents, const string& name){
        int index = 0;
        for (Student* currentStudent : myStudents){
            if (currentStudent->getName() == name)
              return index;
            index++;
        }
      return 0;
    }
    
    void addStudent(string name){
        Student* newStudent = new Student(name);
        myStudents.push_back(newStudent);
    }
    void addGrades(string name, int grade, int week){
        for(size_t i = 0; i < myStudents.size(); i++){
            if (myStudents[i]->getName() == name)
                myStudents[i]->setGrade(grade, week);
        }
    } // set a certain weeks grade for a given student
    
private:
    string myName;
    vector<Student*> myStudents;
    Timeslot timeslot;
};

class LabWorker {
public:
    LabWorker(const string& name) : myName(name), mySection(NULL){}
    //======accessors=============
    void displayGrades() const {
        cout << myName << " has ";
        mySection->display();
        cout << endl;
    } // display moe and his section
     
    void display() const {
        mySection->displayStudentGrades();
    } // display the section grades
    
    void addSection(Section &section){
        mySection = &section;
    } // change the section
    
    void addGrade(string name, int grade, int week){
        mySection->addGrades(name, grade, week);
    } // set a certain weeks grade for a given student

private:
    string myName;
    Section* mySection;
    
};


//====prototyping==========

//======================================================================main
int main() {
      
 // lab workers
   LabWorker moe( "Moe" );
   LabWorker jane( "Jane" );
   
   // sections and setup and testing
   Section secA2( "A2", "Tuesday", 16 );
   //secA2.loadStudentsFromFile( "A2.txt" );
   secA2.addStudent("John");
   secA2.addStudent("George");
   secA2.addStudent("Paul");
   secA2.addStudent("Ringo");

   cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
   secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
   moe.addSection( secA2 );
   moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked
  
   Section secB3( "B3", "Thursday", 11 );
   //secB3.loadStudentsFromFile( "B3.txt" );
   secB3.addStudent("Thorin");
   secB3.addStudent("Dwalin");
   secB3.addStudent("Balin");
   secB3.addStudent("Kili");
   secB3.addStudent("Fili");
   secB3.addStudent("Dori");
   secB3.addStudent("Nori");
   secB3.addStudent("Ori");
   secB3.addStudent("Oin");
   secB3.addStudent("Gloin");
   secB3.addStudent("Bifur");
   secB3.addStudent("Bofur");
   secB3.addStudent("Bombur");

   cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
   secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
   jane.addSection( secB3 );
   jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


   // setup is complete, now a real world scenario can be written in the code
   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

   // week one activities  
   cout << "\nModeling week: 1\n";
   moe.addGrade( "John", 7, 1 );  
   moe.addGrade( "Paul", 9, 1 );  
   moe.addGrade( "George", 7, 1 );  
   moe.addGrade( "Ringo", 7, 1 );  
   cout << "End of week one\n";
   moe.displayGrades();

   // week two activities
   cout << "\nModeling week: 2\n";
   moe.addGrade( "John", 5, 2 );  
   moe.addGrade( "Paul", 10, 2 );  
   moe.addGrade( "Ringo", 0, 2 );  
   cout << "End of week two\n";
   moe.displayGrades();

   //test that reset works  // NOTE: can we check that the heap data was dealt with?
   cout << "\ntesting reset()\n";
   secA2.reset();
   secA2.display();
   moe.displayGrades();

 
    
    
    
    return 0;
}
