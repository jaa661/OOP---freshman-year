//
//  main.cpp
//  Recitation 14
//
//  Created by Jacob Abbott on 12/11/15.
//  Copyright © 2015 Computer Science 1124. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
    int data;
    Node* link;
};

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

void binaryInt(int x){
    if (x >= 1 ){
        if (x%2 == 0){
            binaryInt(x/2);
            cout<<"0";
            }
        else{
            binaryInt(x/2);
            cout << "1";
            }
    }
}

Node* listSum(Node* headA, Node* headB){
    if (headA != nullptr){
        Node* newNode = new Node((headA->data + headB->data), listSum(headA->link, headB->link));
        //cout << (headA->data  + headB->data);
        return newNode;
    }
    else
        return nullptr;
}

void q(int n) {
    if (n > 1) {
        cout << 'a';
        q(n/2);
        cout << 'b';
        q(n/2);
    }
    cout << 'c';
}

int max(TNode* root, int maxInt = INT_MIN) {
    if (!root) return maxInt;
    if (root->data > maxInt) maxInt = root->data;
    maxInt = max(root->left, maxInt);
    maxInt = max(root->right, maxInt);
    
    return maxInt;
}

int sumString(char cString[]) {
    //cout << int(cString[0])<<endl;
    if (cString[0] == '\0')
        return 0;
    return cString[0] + sumString(cString+1);
}

int binarySearch(char targetList[],char target, int min, int max) {
    int middle = (min + max)/2;
    if (target == targetList[middle]) return middle;
    else if (target > targetList[middle])
        return binarySearch(targetList, target, middle+1, max);
    else
        return binarySearch(targetList, target,  min, middle -1);
}

void displayList(Node* head){
    if(head != nullptr){
        cout << head->data << ", ";
        displayList(head->link);
    }
}

int main() {

    cout << "=====first function=====" << endl;
    cout << "binaryInt(10);" << endl;
    binaryInt(10);
    cout << endl;
    cout << "binaryInt(73);" << endl;
    binaryInt(73);
    cout << endl;
    cout << "binaryInt(3);" << endl;
    binaryInt(3);
    cout << endl;
    
    cout << "=====second function=====" << endl;
    cout << "listSum(headA, headB)" << endl;
    Node* headA = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    Node* headB = new Node(4, new Node(7, new Node(3, new Node(1, new Node(6)))));
    cout << "The sum of the lists was compiled"<<endl;
    cout << "List A: ";
    displayList(headA);
    cout<< endl;
    cout << "List B: ";
    displayList(headB);
    cout<< endl;
    cout << "List C: ";
    displayList(listSum(headA, headB));
    cout<< endl;
    
    cout << "=====third function=====" << endl;
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << "max(&f)" << endl;
    cout << max(&f) << endl;
    
    cout << "=====fourth function=====" << endl;
    char cString[15] = "I love C++";
    cout << "sumString(some cstring)" << endl;
    cout << sumString(cString) << endl;
    
    cout << "=====fifth function=====" << endl;
    char searchList[15] = "abcdefghijklmn";
    cout << "the list is... abcdefghijklmn"<<endl;
    cout << "e is at index... " << binarySearch(searchList, 'e', 0, 14) << endl;
    cout << "i is at index... " << binarySearch(searchList, 'i', 0, 14) << endl;
    cout << "k is at index... " << binarySearch(searchList, 'k', 0, 14) << endl;
    
    cout << "=====sixth function=====" << endl;
    
    cout << "q(5)...";
    q(5);
    cout<<endl;
    cout << "q(10)...";
    q(10);
    cout<<endl;
    

    return 0;
}
