#include <vector>
#include <iostream>
#include "Course.h"
#include "Student.h"

Course::Course(string& myName) : name(myName){};

void Course::display() const {
    cout << "Course: " << name << endl;
    cout << "Students in this course: " << endl;
    for (Student* tempStudent : students){
        cout << tempStudent->getName();
        cout << endl;
    }
    }
    
string Course::getName(){
        return name;
    }  
void Course::addStudent(Student* student){
    students.push_back(student);
}