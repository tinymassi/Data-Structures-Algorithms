// ********************************************************************** //
// This header file is the creation of the linked list class 'LinkedList' //
// all the member variables and functions included in the linkedlist.cpp  //
// are included here                                                      //
// massimoginella12@gmail.com                                             //
// ********************************************************************** //

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class LinkedList {

    public:

        LinkedList();
        std::string remove_front();
        std::string remove_rear();
        void insert_front(std::string input);
        void insert_back(std::string input);
        void print_list();
        bool is_list_empty = true;
        ~LinkedList();

    private:	
    
    struct Node {
        Node* next = nullptr;
        Node* prev = nullptr;
        std::string data = "";
    };    

    Node* head = nullptr;
    Node* tail = nullptr;   
};


#endif
