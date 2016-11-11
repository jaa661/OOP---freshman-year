/* 
 * File:   main.cpp
 * Author: Jacob Abbott
 * cs 1124 recitation 1 2
 * Created on December 4, 2015, 8:12 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
	int data;
	Node* link;
};

class Sequence{
public:
    Sequence(): head(nullptr), current(head){}
    ~Sequence(){
        clear();
    }
    Sequence(const Sequence& rhs) {
        head = nullptr;
        current = head;
        if (rhs.head) {
            head = new Node(rhs.head->data);
            current = head;
            Node* nextNode = rhs.head->link;
            while (nextNode) {
                current->link = new Node(nextNode->data);
                current = current->link;
                nextNode = nextNode->link;
            }
        }
    }
    //=====================big three
    
    void reset() {
        current = head;
    }
    
    void add(int i) {
        if (current != nullptr) {
            Node* next = current->link;
            current->link = new Node(i);
            current = current->link;
            if (next) current->link = next;
        } else {
            head = new Node(i);
            current = head;
        }
    }
    
    void remove() {
        Node* check = head;
        check->link = head->link;
        if (head == current) {
            head = head->link;
            delete current;
            current = head;
        } else if(current == nullptr){
          //does nothing
        }else {
            while (check->link != current) {           
                check = check->link;
            }
            check->link = current->link;
            delete current;
            current = check;
        }
    }
    
    int data(){
        if(current != nullptr)
            return current->data;
        else 
            return 0;
    }
    
    void next(){
        if(current->link != nullptr)
            current = current->link;
    }
    
    bool valid() { 
        return current; 
    }
    
    void clear() {
        if (head){
            while(head->link){
                current = head->link;
                delete head;
                head = current;
            }
             head = nullptr;
            current = head;
        }
        else{}
    }
    
    void display(char spacingChar = ' ', ostream& os = cout) {
        Node* displayNode = head;
        while (displayNode) {
            os << displayNode->data;
            if (displayNode->link) 
                os << spacingChar;
            displayNode = displayNode->link;
        }
        os << endl;
    }
    
private:
    Node* head;
    Node* current;
};

int main() {
  Sequence s;
  for (int i = 0; i < 6; ++i) s.add(i);
  s.display();
  cout << "==========\n";
  s.reset();
  for (int i = 0; i < 3; ++i) s.next();
  s.add(42);
  s.display();
  cout << "==========add\n";
  s.reset();
  for (int i = 0; i < 2; ++i) s.next();
  s.remove();
  s.display();
  cout << "==========remove\n";
  Sequence t = s;
  t.display();
  cout << "==========copy control\n";
  s.clear();
  s.display();
  cout << "==========clear\n";
  return 0;
}