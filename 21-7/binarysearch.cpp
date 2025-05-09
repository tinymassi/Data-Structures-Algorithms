/* 
    This program is the function implementation of the BinarySearch class
    locted in binarysearch.h. This code is responsible for generating a binary
    search tree and supports a variety of functions that allow the user to 
    maniuplate said tree through inserting nodes, traversal, deletion, and 
    more.
                                               
    author: massimoginella12@gmail.com                                         
*/

#include <utility>
#include "binarysearch.h"

// public wrapper for private search function with bounds checks
bool BinarySearch::search_pub(int k) {
    if (search(root, k) == nullptr) {
        return false;
    }

    return true;
}

// search function takes the tree root and a key value k
// returns the node if found, and nullptr if not.
Node* BinarySearch::search(Node* n, int k) {
    while (n != nullptr && n->key != k) {
        if (k < n->key) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    return n;
}



// public wrapper for private insert function (probably not necessary)
void BinarySearch::insert_pub(int k) {
    insert(k);
}

// takes a key k, creates a node 'new_node' and inserts it into the tree
void BinarySearch::insert(int k) {
    Node* new_node = new Node(k);
    Node* prev = nullptr;
    Node* temp = root;

    while (temp != nullptr) {
        prev = temp;
        if (k < temp->key) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    new_node->parent = prev;

    if (prev == nullptr) {
        root = new_node;
        return;
    }

    if (k < prev->key) {
        prev->left = new_node;
    } else {
        prev->right = new_node;
    }

}



// public wrapper for private delete function with bounds checks
void BinarySearch::delete_pub(int k) {
    if (!search_pub(k)) {
        return;
    }

    Delete(search(root, k));
}

// takes a node n that is meant to be deleted, and based on three
// scenarios (no children, two children, one child), deletes the 
// node n from the tree
void BinarySearch::Delete(Node* n) {
    Node* target = nullptr;
    Node* x = nullptr;

    if (n->left == nullptr || n->right == nullptr) {
        target = n;
    } else {
        target = successor(n);
    }

    if (target->left != nullptr) {
        x = target->left;
    } else {
        x = target->right;
    }

    if (x != nullptr) {
        x->parent = target->parent;
    }

    if (target->parent == nullptr) {
        root = x;
    } else if (target == target->parent->left) {
        target->parent->left = x;
    } else {
        target->parent->right = x;
    }

    if (target != n) {
        n->key = target->key;
    }

    delete target;
}



// public wrapper function for private min function with bounds checks
std::pair<bool, int> BinarySearch::min_pub() {
    if (isEmpty()) {
        return std::make_pair(false, -1);
    }

    return std::make_pair(true, min(root)->key);
}

// takes a node n (root) and moves down the left children of the tree to 
// find the smallest value and returns the node containing it.
Node* BinarySearch::min(Node* n) {
    while (n->left != nullptr) {
        n = n->left;
    }

    return n;
}



// public wrapper function for private max function with bounds checks
std::pair<bool, int> BinarySearch::max_pub() {
    if (isEmpty()) {
        return std::make_pair(false, -1);
    }

    return std::make_pair(true, max(root)->key);
}

// takes a node n (root) and moves down the right children of the tree to
// find the largest value and returns the node containing it.
Node* BinarySearch::max(Node* n) {
    while (n->right != nullptr) {
        n = n->right;
    }

    return n;
}



// public wrapper function for private predecessor function with bounds checks
std::pair<bool, int> BinarySearch::predecessor_pub(int k) {
    if (!search_pub(k)) {
        return std::make_pair(false, -1);
    }
    
    Node* temp = search(root, k);
    temp = predecessor(temp);

    if (temp != nullptr) {
        return std::make_pair(true, temp->key);
    }

    return std::make_pair(false, -2);
}

// takes a node n of which to find its predecessor and returns a node temp
// considered the predecessor of the node n. if no predecessor, temp = nullptr.
Node* BinarySearch::predecessor(Node* n) {
    if (n->left != nullptr) {
        return max(n->left);
    }

    Node* temp = n->parent;

    while (temp != nullptr && n == temp->left) {
        n = temp;
        temp = temp->parent;
    }
    
    return temp;
}



// public wrapper function for private successor function with bounds checks
std::pair<bool, int> BinarySearch::successor_pub(int k) {
    if (!search_pub(k)) {
        return std::make_pair(false, -1);
    }
    
    Node* temp = search(root, k);
    temp = successor(temp);

    if (temp != nullptr) {
        return std::make_pair(true, temp->key);
    }

    return std::make_pair(false, -2);
}

// takes a node n of which to find its successor and returns a node temp
// considered the successor of the node n. if no successor, temp = nullptr.
Node* BinarySearch::successor(Node* n) {
    if (n->right != nullptr) {
        return min(n->right);
    }

    Node* temp = n->parent;

    while (temp != nullptr && n == temp->right) {
        n = temp;
        temp = temp->parent;
    }

    return temp;
}



// public wrapper function for private inOrder function.
std::vector<int> BinarySearch::inOrder_pub() {
    traversal_data.clear(); 
    inOrder(root);
    return traversal_data;
}

// takes a node r (root) and traverses the tree in inOrder fashion
// (left, root, right). Fills the vector traversal_data with node keys
// in the order in which it traverses the tree.
void BinarySearch::inOrder(Node* r) {
    if (r == nullptr) {
        return;
    }

    inOrder(r->left);
    traversal_data.push_back(r->key);
    inOrder(r->right);
}



// public wrapper function for private preOrder function.
std::vector<int> BinarySearch::preOrder_pub() {
    traversal_data.clear();
    preOrder(root);
    return traversal_data;
}

// takes a node r (root) and traverses the tree in preOrder fashion
// (root, left, right). Fills the vector traversal_data with node keys
// in the order in which it traverses the tree
void BinarySearch::preOrder(Node* r) {
    if (r == nullptr) {
        return;
    }

    traversal_data.push_back(r->key);
    preOrder(r->left);
    preOrder(r->right);
}



// public wrapper function for private postOrder function.
std::vector<int> BinarySearch::postOrder_pub() {
    traversal_data.clear();
    postOrder(root);
    return traversal_data;
}

// takes a node r (root) and traverses the tree in postOrder fashion
// (left, right, root). Fills the vector traversal_data with node keys
// in the order in which it traverses the tree
void BinarySearch::postOrder(Node* r) {
    if (r == nullptr) {
        return;
    }

    postOrder(r->left);
    postOrder(r->right);
    traversal_data.push_back(r->key);
}



// function that returns if the tree is empty or not (AKA if root = nullptr)
bool BinarySearch::isEmpty() {
    if (root == nullptr) {return true;}
    return false;
}



// takes a node (root) and traverses the tree in postOrder fashion and deletes
// nodes as it traverses in the order left, right, and root.
void BinarySearch::erase_tree(Node* r) {
    if (r == nullptr) {
        return;
    }

    erase_tree(r->left);
    erase_tree(r->right);
    delete r;
}



// destructor uses the erase_tree function to clean up allocated memory when 
// program is done running.
BinarySearch::~BinarySearch() {
    erase_tree(root);
}