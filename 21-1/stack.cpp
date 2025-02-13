// ********************************************************** //
// This program is an implementation of the member functions  //
// & values of the Stack class located in Stack.h             //
// massimoginella12@gmail.com                                 //
// ********************************************************** //

#include <iostream>
#include <string>
#include "stack.h"


// function that uses the linked list object 'mylist' to
// push string input values to the top of the stack data structure
void Stack::push(std::string input) {
    mylist.insert_front(input);
}


// function that uses the linked list object 'mylist' to 
// remove values from the top of the stack data structure
std::string Stack::pop() {
    return mylist.remove_front();
}


// function that uses the linked list object 'mylist' and 
// linked list member variable 'is_list_empty' to check
// for an empty list and subsequently, an empty stack
bool Stack::is_empty() {
    return mylist.is_list_empty;
}


// destructor for the Stack class
Stack::~Stack(){}
