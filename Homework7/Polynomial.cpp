//
//  Polynomial.cpp
//  hw7
//

#include "Polynomial.h"
#include <math.h>
#include <vector>
using namespace std;

namespace polyMath {
    Node::Node(unsigned degree, int coefficient) : coefficient(coefficient), degree(degree), next(nullptr) {}
    
    Polynomial::Polynomial(vector<int>& a) {
        headPtr = new Node(0, a[0]);
        Node* tempNode = headPtr;
        for (unsigned i = 1; i <= (a.size() - 1); ++i) {
            tempNode->next = new Node(i, a[(i)]);
            tempNode = tempNode->next;
        }
    }
    Polynomial::Polynomial(){
    }
    
    Polynomial::~Polynomial() {}
    
    Polynomial::Polynomial(const Polynomial& rhs) {
        headPtr = nullptr;
        if (rhs.headPtr) {
            headPtr = new Node(rhs.headPtr->degree, rhs.headPtr->coefficient);
            Node* current = headPtr;
            Node* nextNode = rhs.headPtr->next;
            while (nextNode) {
                current->next = new Node(nextNode->degree, nextNode->coefficient);
                current = current->next;
                nextNode = nextNode->next;
            }
        }
    }
    
    bool Polynomial::operator==(const Polynomial& rhs) {
        if (getDegree() != rhs.getDegree()) return false;
        Node* currentL = headPtr;
        Node* currentR = rhs.headPtr;
        while (currentL) {
            if ((currentL->degree != currentR->degree) || (currentL->coefficient != currentR->coefficient)) return false;
            currentL = currentL->next;
            currentR = currentR->next;
        }
        return true;
    }
    
    bool Polynomial::operator!=(const polyMath::Polynomial &rhs) {
        return !(*this == rhs);
    }
    
    unsigned Polynomial::getDegree() const {
        Node* tempNode = headPtr;
        unsigned degree = 0;
        while (tempNode) {
            degree = tempNode->degree;
            tempNode = tempNode->next;
        }
        return degree;
    }
    
    Polynomial& Polynomial::operator=(const Polynomial& rhs) {
        reset();
        headPtr = nullptr;
        Node *current = headPtr;
        if (rhs.headPtr) {
            headPtr = new Node(rhs.headPtr->degree, rhs.headPtr->coefficient);
            current = headPtr;
            Node* nextNode = rhs.headPtr->next;
            while (nextNode) {
                current->next = new Node(nextNode->degree, nextNode->coefficient);
                current = current->next;
                nextNode = nextNode->next;
            }
        }
        return *this;
    }
    
    Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
        *this = *this+rhs;
        return *this;
    }
    
    ostream& operator<<(ostream& os, const Polynomial& p) {
        displayNode(os, p.headPtr);
        return os;
    }
    
    void displayNode(ostream& os, const Node* node) {
        if (!node) 
            return;
        if (node->coefficient != 0) {
            if (node->coefficient < 0)
                os << " - ";
            if (node->coefficient > 0  &&  node->degree != 0)
                os << " + ";
            if ((abs(node->coefficient) != 1) || (node->degree == 0)) 
                os << abs(node->coefficient);
            if (node->degree > 1) os << "x^" << node->degree;
            else if (node->degree == 1) os << "x";
        }
        displayNode(os, node->next);
    }
    
    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
        Polynomial temp = lhs;
        Node* tempNode1;
        Node* tempNode2;
        if (rhs.getDegree() > lhs.getDegree()) {
            temp = rhs;
            tempNode2 = lhs.headPtr;
        } else
            tempNode2 = rhs.headPtr;
        tempNode1 = temp.headPtr;  
        while (tempNode1 && tempNode2) {
            tempNode1->coefficient += tempNode2->coefficient;
            tempNode1 = tempNode1->next;
            tempNode2 = tempNode2->next;
        }
        return temp;
    }
    
    void Polynomial::reset() {
        if (!headPtr) return;
        Node* nodeToClear = headPtr;
        while (nodeToClear) {
            Node* nextNodeToClear = nodeToClear->next;
            delete nodeToClear;
            nodeToClear = nextNodeToClear;
        }
        headPtr = nullptr;
    }
    
    int Polynomial::evaluate(int x) {
        int value = 0;
        Node* tempNode = headPtr;
        while (tempNode) {
            value += tempNode->coefficient*pow(x, tempNode->degree);
            tempNode = tempNode->next;
        }
        return value;
    }
}