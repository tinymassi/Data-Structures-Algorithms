// ********************************************************* //
// This program is an implementation of the member functions //
// & values of the LinkedList class located in LinkedList.h  //
// massimoginella12@gmail.com                                //
// ********************************************************* //

#include <string>
#include <iostream>
#include "linkedlist.h"


// constructor for the LinkedList class
LinkedList::LinkedList() {}


// function that removes & replaces the head of the doubly linked list
// returns the string value stored at the old head
std::string LinkedList::remove_front() {
    std::string return_string = "";

    if (head == tail) {
        return_string = head->data;
        delete head;
        head = tail = nullptr;
        is_list_empty = true;
    } else if (head != nullptr) { 
        return_string = head->data;
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;     
    }


    return return_string;
}


// function that removes & replaces the tail of the doubly linked list
// returns the string value stored at the old tail
std::string LinkedList::remove_rear() {
    std::string return_string = "";
           
    if (head == tail) {
        return_string = head->data;
        delete head;
        head = tail = nullptr;
        is_list_empty = true;
    } else if (tail != nullptr) {
        return_string = tail->data;
        Node* temp = tail; 
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    return return_string;
}


// function that replaces the head of the linked list with
// a new head that stores data of type std::string
void LinkedList::insert_front(std::string input){
    Node* temp = new Node;
    temp->data = input;
    is_list_empty = false;


    if (head == nullptr && tail == nullptr) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;

        head = temp;
    }
}


// function that replaces the tail of the linked list with
// a new tail that stores data of type std::string
void LinkedList::insert_back(std::string input){
    Node* temp = new Node;
    temp->data = input;
    is_list_empty = false;


    if (head == nullptr && tail == nullptr) {
        head = temp;
        tail = temp;    
    } else {
        temp->prev = tail;
        tail->next = temp;    
    
        tail = temp;
    }
}


// funtion that traverses the linked list and prints
// the data stored in each node
void LinkedList::print_list() {
    Node* temp = head;
    
    while(temp) {
        std::cout << " " << temp->data << " ";
        temp = temp->next;
    }

    return;
}


// destructor function that traverses the list and 
// deletes every node to free memory
LinkedList::~LinkedList(){
    print_list(); 
    while(head) {
       remove_front();
    }
}
