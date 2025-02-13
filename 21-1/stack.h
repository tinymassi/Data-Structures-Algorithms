// ************************************************************ //
// This header file is the creation of the stack class 'Stack'  //
// all the member variables and functions used in stack.cpp     //
// are included here                                            //
// massimoginella12@gmail.com                                   //
// ************************************************************ //

#ifndef STACK_H
#define STACK_H

#include <string>
#include "linkedlist.h"

class Stack {
    public:
    
    Stack() : mylist() {};
    void push(std::string input);
    std::string pop();
    bool is_empty();
    ~Stack();


    private:

    LinkedList mylist;
};


#endif
