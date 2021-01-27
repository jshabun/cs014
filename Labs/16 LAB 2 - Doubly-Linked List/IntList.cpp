#include <iostream>
using namespace std;

#include "IntList.h"

// Initializes an empty list with dummy head and dummy tail.
IntList::IntList() {
    /* dummyHead = 0;
    dummyTail = 0;
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead; */
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

// Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList() {
    while (!empty()) {
        pop_back();
    }
}

// Inserts a data value (within a new node) at the front end of the list. This must be an O(1) operation.
void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);

    temp->next = dummyHead->next;
    temp->prev = dummyHead;
    dummyHead->next->prev = temp;
    dummyHead->next = temp;
}

// Removes the node at the front end of the list (the node after the dummy head). Does nothing if the list is already empty. 
// This must be an O(1) operation.
void IntList::pop_front() {
    if (!empty()) {
        IntNode* temp = dummyHead->next->prev;
        delete dummyHead->next;
        dummyHead->next = temp;
        temp->prev = dummyHead;
    }
}

// Inserts a data value (within a new node) at the back end of the list. This must be an O(1) operation.
void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    IntNode* temp2;
    temp2 = dummyTail->prev;
    dummyTail->prev = temp;
    temp->next = dummyTail;
    temp->prev = temp2;
    temp2->next = temp;
}

// Removes the node at the back end of the list (the node before the dummy tail). Does nothing if the list is already empty. 
// This must be an O(1) operation.
void IntList::pop_back() {
    if (!empty()) {
        IntNode* temp = dummyTail->prev;

        dummyTail->prev = temp->prev;
        temp->prev->next = dummyTail;
        delete temp;
        // temp = nullptr;
    }
}

// Returns true if the list does not store any data values (it only has dummy head and dummy tail), otherwise returns false.
bool IntList::empty() const {
    if (dummyHead->next == dummyTail) {
        return true;
    } else {
        return false;
    }
}

// A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. 
// This function does NOT send to the stream a newline or space at the end.
ostream & operator<<(ostream &out, const IntList &rhs) {
    if (!rhs.empty()) {
        IntNode* temp = rhs.dummyHead->next;
        while (temp->next != rhs.dummyTail) {
            out << temp->data << " ";
            temp = temp->next;
        }
        out << temp->data;
    }
    return out;
}

// prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space. 
// This function does NOT output a newline or space at the end.
void IntList::printReverse() const {
    for (IntNode *temp = dummyTail; temp != nullptr; temp=temp->prev) {
        cout << temp->data;

        if (temp->prev != 0) {
            cout << " ";
        }
    }
}