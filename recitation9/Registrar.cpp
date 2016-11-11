#include <vector>
#include <iostream>
#include "Registrar.h"
#include "Student.h"
#include "Course.h"

using namespace BrooklynPoly;
        
    //ostream& operator<<(ostream& os , Registrar registrar){
        //registrar.printReport();
        
    //}

    void Registrar::printReport() const{
        if (courses.size() == 0){
            cout <<"there are no courses curently";
            cout << endl;
        }
        else 
            for(Course* tempcourse : courses)
            tempcourse->display();
        cout << endl;
        
    }  
    void Registrar::addStudent(string name) {
       Student* newStudent = new Student(name);
        students.push_back(newStudent);
    }
    
    void Registrar::addCourse(string name) {
        Course* newCourse = new Course(name);
        courses.push_back(newCourse);
    }
    
    void Registrar::cancelCourse(string name) {
        for(size_t i = 0;i < courses.size();i++) {
         if(courses[i]->getName() == name){
             courses[i] = courses[courses.size()-1];
             courses.pop_back();
         }
        }
    }
    void Registrar::enrollStudentInCourse(string studentName, string courseName) {
        for(Course* tempcourse : courses){
            if (tempcourse->getName() == courseName){
                for(Student* tempStudent : students){
                    if (tempStudent->getName() == studentName){
                         tempStudent->addCourse(tempcourse);
                         tempcourse->addStudent(tempStudent);
                        }
                    else
                        cout <<"the student could not be enrolled"<<endl;
                }
            }
        }
    }
    void Registrar::purge() {
        for(Course* tempcourse : courses)
            delete tempcourse;
        for(Student* tempStudent : students)
            delete tempStudent;
        students.clear();
        courses.clear();
    }
    
