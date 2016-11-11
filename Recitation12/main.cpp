/* 
 * File:   main.cpp
 * Author: Jacob Abbott
 * cs 1124 recitation 1 2
 * Created on November 20, 2015, 8:18 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void display(Node* toDisplay){
    while(toDisplay->link != nullptr){
        cout << toDisplay->data << "  ";
        toDisplay = toDisplay->link;
    }
    cout << toDisplay->data << endl;
}

void  spliceInto(Node* splicingIndex, Node* head2){
    if(head2 == nullptr){
        return;
    }
    Node* end = splicingIndex->link; 
    if(head2 != nullptr)
        splicingIndex->link = head2;
    while( head2->link != nullptr ){
    	head2 = head2->link;
    }
    head2->link = end;
}

Node* isSubList(Node* totalList, Node* subList){
    Node* searchNode = new Node(subList->data, subList->link);
    while(totalList != nullptr){
        if(totalList->data == subList->data){
            searchNode->link = totalList->link;
            while(subList->link != nullptr){
                totalList = totalList->link;
                subList = subList->link; 
                //cout << totalList->data << subList->data << "check";
                if(totalList->data != subList->data)
                    return nullptr;
            }
            return searchNode;
        }
        else
        totalList = totalList->link;
    }
    return nullptr;
}
int main() {
    Node* List1 = new Node ( 5 , new Node ( 7 ,new Node ( 9 ,new Node ( 1 ,nullptr))));
    Node* List2 = new Node ( 6, new Node ( 3 ,new Node(2, nullptr)));
    cout << "L1: ";
    display(List1);
    cout << "L2: ";
    display(List2);
    cout << "target: ";
    display(List1->link);
    cout << "splicing L2 at target in L1" << endl;
    spliceInto(List1->link, List2);
    cout << "L1: ";
    display(List1);
    //display(List2);
    
    cout << "=============program 2==============" << endl;
    Node* List3 = new Node ( 1 , new Node ( 2 ,new Node ( 3 ,new Node ( 2 ,new Node( 3 , new Node ( 2 ,new Node ( 4 ,new Node ( 5 ,new Node(6, nullptr)))))))));
    cout << "Original List: ";
    display(List3);
    
    cout << "attempting to match: 1" << endl;
    if (isSubList(List3, new Node ( 1, nullptr)) == nullptr)
        cout << "match failed"<< endl;
    else
        display(isSubList(List3, new Node ( 1, nullptr)));
    
    cout << "attempting to match: 3 9" << endl;
    if (isSubList(List3, new Node( 3, new Node(9, nullptr))) == nullptr)
        cout << "match failed"<< endl;
    else
        display(isSubList(List3, new Node( 3, new Node(9, nullptr))));  
    
    cout << "attempting to match: 2 3" << endl;
    if (isSubList(List3, new Node( 2, new Node(3, nullptr))) == nullptr)
        cout << "match failed"<< endl;
    else
        display(isSubList(List3, new Node( 2, new Node(3, nullptr))));    
    
    cout << "attempting to match: 2 4 5 6" << endl;
    if (isSubList(List3, new Node( 2, new Node(4,new Node(5, new Node(6, nullptr))))) == nullptr)
        cout << "match failed"<< endl;
    else
        display(isSubList(List3, new Node( 2, new Node(4,new Node(5, new Node(6, nullptr))))));  
    return 0;
}

