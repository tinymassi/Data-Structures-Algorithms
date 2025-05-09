/*
    Main program that demonstrates the functionality of  
    the binary search tree class BinarySearch and
    provides a terminal based UI. To run this  
    code, run 'make' in your terminal, then type ./p7. 
    Once the program runs, press enter and you will see 
    your available commands. Have fun!
                                                    
    author: massimoginella12@gmail.com                  
*/  


#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include "binarysearch.h"

void print_traversal(std::vector<int> traversal) {
    for (size_t i = 0; i < traversal.size(); i++) {
        std::cout << traversal[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    BinarySearch tree;

    std::string command{};
    std::string str_data{};
    std::string line{};

    int data{};

    bool input_needed = false;

    std::pair<bool, int> return_val;

    std::vector<int> return_traversal;

    while(std::getline(std::cin, line)) {
        std::istringstream iss(line);
        iss >> command >> str_data;

        if (str_data != "") {
            data = stoi(str_data);
            input_needed = true;
        }

        if (command == "insert" && input_needed) {

            tree.insert_pub(data);
            std::cout << "inserted " << data << "." << std::endl;

        } else if (command == "search" && input_needed) {

            if (tree.search_pub(data)) {
                std::cout << data << " found." << std::endl;
            } else {
                std::cout << data << " not found." << std::endl;
            }

        } else if (command == "predecessor" && input_needed) {

            return_val = tree.predecessor_pub(data);
            if (return_val.first) {
                std::cout << data << " predecessor is " << return_val.second << "." << std::endl;
            } else if (!return_val.first && return_val.second == -1) {
                std::cout << data << " not in tree." << std::endl;
            } else { 
                std::cout << "no predecessor for " << data << "." << std::endl;
            }

        } else if (command == "successor" && input_needed) {

            return_val = tree.successor_pub(data);
            if (return_val.first) {
                std::cout << data << " successor is " << return_val.second << "." << std::endl;
            } else if (!return_val.first && return_val.second == -1) { 
                std::cout << data << " not in tree. " << std::endl;
            } else {
                std::cout << "no successor for " << data << "." << std::endl;
            }

        } else if (command == "delete" && input_needed) { 

            if (tree.search_pub(data)) {
                tree.delete_pub(data);
                std::cout << "deleted " << data << "." << std::endl;
            } else {
                std::cout << "delete " << data << " - not found." << std::endl;
            }

        } else if (command == "min") {

            return_val = tree.min_pub();
            if (return_val.first) {
                std::cout << "min is " << return_val.second << "." << std::endl;
            } else {
                std::cout << "tree empty." << std::endl;
            }

        } else if (command == "max") {

            return_val = tree.max_pub();
            if (return_val.first) {
                std::cout << "max is " << return_val.second << "." << std::endl;
            } else {
                std::cout << "tree empty." << std::endl;
            }

        } else if (command == "inorder") {

            return_traversal = tree.inOrder_pub();
            if (return_traversal.size() == 0) {
                std::cout << "tree empty. nothing to traverse." << std::endl;
            } else {
                std::cout << "inorder traversal: " << std::endl;
                print_traversal(return_traversal);
            }

        } else if (command == "postorder") {

            return_traversal = tree.postOrder_pub();
            if (return_traversal.size() == 0) {
                std::cout << "tree empty. nothing to traverse." << std::endl;
            } else {
                std::cout << "postorder traversal: " << std::endl;
                print_traversal(return_traversal);
            }

        } else if (command == "preorder") {

            return_traversal = tree.preOrder_pub();
            if (return_traversal.size() == 0) {
                std::cout << "tree empty. nothing to traverse." << std::endl;
            } else {
                std::cout << "preorder traversal: " << std::endl;
                print_traversal(return_traversal);
            }

        } else {

            std::cerr << "Command not recognized. Choose from the following: "
            "insert [data], search [data], predecessor [data], successor [data], "
            "delete [data], min, max, inorder, postorder, and preorder." << 
            std::endl;

        }

        input_needed = false;
        str_data = "";
        data = 0;
    }

}