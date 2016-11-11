/*
  Recitation 10
  CS1124
 * Jacob Abbott
 
  Focus: Copy Control.  Uses dynamic array of pointers.
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary)
	: title(aTitle), salary(aSalary) {cout << "Position()";}
    string getTitle() const {return title;}
    double getSalary() const {return salary;}
    void changeSalaryTo(double d) {salary = d;}
private:
    string title;
    double salary;
}; // class Position

class Entry {
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone,
	  Position& aPosition) 
	: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
    cout << "Entry()";}
    string getName(){
        return name;
    }
    unsigned getPhone(){
        return phone;
    }
    friend ostream& operator<<( ostream& os, const Entry& e ) {
        os << e.name << ' ' << e.room << ' ' << e.phone << endl;
        return os;
    } // operator <<
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
public:
    Directory()
	: capacity(2), size(0), entries(new Entry*[2] )
    {
            cout << "Directory()" << endl;
        // Should we do this?  What do you think?
        for (size_t i = 0; i < capacity; i++) {
            entries[i] = nullptr;
        } // for
    } // Directory()
        
    ~Directory(){
        cout << "~Directory()" << endl;
        for (size_t i = 0; i < size; i++) {
            delete entries[i];
        }
        delete[] entries;
    }//destructor
    
    Directory(const Directory& d):size(d.size),capacity(d.capacity){
        cout << "Directory(d)" << endl;
        //size = d.size;
        //capacity = d.capacity;
        entries = new Entry* [capacity];
        for (size_t i = 0; i < size; i++) {
            entries[i] = new Entry(*d.entries[i]);
        }
    }//copy constructor
    
    Directory& operator = (const Directory& d) {
        cout << "=" << endl;
        if (this != &d) {
            for (size_t i = 0; i < size; i++) {
               delete entries[i];
            }
            delete[] entries;
            size = d.size;
            capacity = d.capacity;
            entries = new Entry*[capacity];
            for (size_t i = 0; i < size; i++) {
                entries[i] =  new Entry(*d.entries[i]);
            }
        }
        return *this;
    }//assignment operator 
    
    friend ostream& operator <<(ostream& os, const Directory& d) {
	for (size_t i = 0; i < d.size ; i++)
            os << *d.entries[i];
	return os;
	}
    unsigned operator[](const string& name){
        for (size_t i = 0; i < size; i++) {
            if (entries[i]->getName() == name) 
                return entries[i]->getPhone();
        }
        cerr << "Error: entry with name: " << name << " not found." << endl;
        return 0;
    }
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if( size == capacity )	{
            // something is missing!!!  Add it!
            Entry** originalEntries = entries;
            entries = new Entry*[ capacity *= 2 ];
            for (size_t i = 0; i < size; i++) {
                entries[i] = originalEntries[i];
            }
            delete [] originalEntries;
        }
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
private:	
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

class SubDirectory : public Directory {
public:
    SubDirectory(){ cout <<"Subdirectory()" << endl;}
    ~SubDirectory(){ cout <<"~Subdirectory()" << endl;}
    string getTitle() const {return title;}
    double getSalary() const {return salary;}
    void changeSalaryTo(double d) {salary = d;}
private:
    string title;
    double salary;
};

void doNothing(Directory dir) { cout << dir; }

int main() {
	
    cout << "========================="<<endl;
    SubDirectory s;
   
} // main

