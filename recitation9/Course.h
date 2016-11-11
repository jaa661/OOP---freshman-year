/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Course.h
 * Author: pierules53
 *
 * Created on October 30, 2015, 8:48 AM
 */



#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <string>

using namespace std;
class Course {
public:
    Course(string& myName);
    
    //============================accessors   
    void display() const; 
    void addStudent(Student* student);
    string getName();   
    
    //===========================mutators

private:
    vector<Student*> students;
    string name;
};


#endif /* COURSE_H */

