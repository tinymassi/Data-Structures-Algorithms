/*
    This header file contains the declaration of BinarySearch
    class and all its public and private counterparts. The code for
    each function can be found in binarysearch.cpp. The BinarySearch
    class allows the user to create a binary search tree and supports
    a variety of functions as can be seen below.

    author: massimoginella12@gmail.com
*/


#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <utility>
#include <vector>

struct Node {
    int key{};
    Node* parent;
    Node* left;
    Node* right;

    Node(int data) {
        key = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearch {

    public:
        BinarySearch() : root(nullptr) {}
        bool search_pub(int k);
        void insert_pub(int k);
        void delete_pub(int k);
        std::pair<bool, int> min_pub();
        std::pair<bool, int> max_pub();
        std::pair<bool, int> predecessor_pub(int k);
        std::pair<bool, int> successor_pub(int k);
        std::vector<int> inOrder_pub();
        std::vector<int> preOrder_pub();
        std::vector<int> postOrder_pub();
        ~BinarySearch();
    
    
    private:
        Node* search(Node* n, int k);
        void insert(int k);
        void Delete(Node* n);
        Node* min(Node* n); 
        Node* max(Node* n);
        Node* predecessor(Node* n);
        Node* successor(Node* n);
        void inOrder(Node* r);
        void preOrder(Node* r);
        void postOrder(Node* r);
        bool isEmpty();
        void erase_tree(Node* r);
        std::vector<int> traversal_data;
        Node* root;
};



#endif