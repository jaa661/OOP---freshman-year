#include "Course.h" 
#include "Student.h"
#include <iostream>

void Student::display() const{
    cout << "Student name" << name << endl;
    cout << "Courses this semester:\n";
    for(Course* tempCourse : courses){
        tempCourse->display();
    }
} 
string Student::getName(){
    return name;
} 
void Student::addCourse(Course* course){
    courses.push_back(course);
}
    
