//
//  Polynomial.h
//  hw7
//


#ifndef __hw7__Polynomial__
#define __hw7__Polynomial__

#include <iostream>
#include <vector>
using namespace std;

namespace polyMath {
    struct Node {
        Node(unsigned degree, int coefficient);
        
        int coefficient;
        unsigned degree;
        Node* next;
    };
    
    class Polynomial {
        friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
        friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
    public:
        Polynomial(std::vector<int>& a);
        Polynomial();
        ~Polynomial();
        Polynomial(const Polynomial& rhs);
        Polynomial& operator=(const Polynomial& rhs);
        
        bool operator==(const Polynomial& rhs);
        bool operator!=(const Polynomial& rhs);
        Polynomial& operator+=(const Polynomial& rhs);
        
        void display(Node) const;
        unsigned getDegree() const;
        void reset();
        int evaluate(int x);
        
    private:
        Node* headPtr;
    };
    
    std::ostream& operator<<(std::ostream& os, const Polynomial& p);
    void displayNode(std::ostream& os, const Node* node);
    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
}

#endif /* defined(__hw7__Polynomial__) */
