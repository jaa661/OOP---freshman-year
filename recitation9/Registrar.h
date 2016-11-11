
/* 
 * File:   Registrar.h
 * Author: Jacob Abbott
 *
 * Created on October 30, 2015, 8:42 AM
 */



#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"

using namespace std;
namespace BrooklynPoly{

   // ostream& operator<<();
    
class Registrar {
public:
    Registrar() {}
    
    //friend ostream& operator<<(ostream&, Registrar);
    
    //============================accessors   
    void printReport() const;  
    
    //===========================mutators
    void addStudent(string name);
    void addCourse(string name);
    void cancelCourse(string name);
    void enrollStudentInCourse(string studentName, string courseName);
    void purge();
    
private:
    std::vector<Student*> students;
    std::vector<Course*> courses;
};
#endif /* REGISTRAR_H */
}
