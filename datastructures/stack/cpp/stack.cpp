#include "stack.h"
#include <cstdio>

// Desc: Constructor
stack::stack() : head(NULL), tail(NULL) {}

// Desc: Destructor
stack::~stack() {
    node * curr = head;
    while(curr != NULL){
        node * next = curr->next;
        delete curr;
        curr = next;
  }
}

// Desc: Adds new element to the top
void stack::push(int x) {

    // create new node
    node * newNode = new node;
    newNode->data = x;
    newNode->next = NULL;

    // if empty stack, update head and tail 
    if (head == NULL) {
    head = newNode;
    tail = newNode;
    }

    // if not empty stack, append newNode onto tail
    else {
    tail->next = newNode;
    tail = newNode;
    }
}

// Desc: Removes the top element
void stack::pop() {
    if (!isEmpty()) {

        // case for single node in ll
        if (head == tail){
            head = NULL;
            tail = NULL;
        }

        // case for more than one node in ll
        else {
            node * curr = head;
            node * prev;

            // find end node
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }

            // update tail to prev, disconnect and delete curr
            tail = prev;
            prev->next = NULL;
            delete curr;
        }
    }
}

// Desc: Returns a copy of the topmost element
int stack::peek() const {
    return !isEmpty() ? tail->data : -9999;
}

// Desc: Returns true if stack is empty
bool stack::isEmpty() const {
    return head == NULL;
}