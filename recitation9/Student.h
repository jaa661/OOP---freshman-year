/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.h
 * Author: Jacob Abbott
 *
 * Created on October 30, 2015, 8:48 AM
 */

#ifndef Student_H
#define Student_H

#include <string>
#include <vector>
#include "Course.h"

using namespace std;
class Course;

class Student {
public:
    Student(string& myName) : name(myName) {}
    
    //============================accessors   
    void display() const; 
    void addCourse(Course* course);
    string getName();   
    
    //===========================mutators

private:
    string name;
    std::vector<Course*> courses;
};
#endif /* Student_H */
