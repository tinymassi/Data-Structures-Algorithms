// ********************************************************** //
// This program is an implementation of the member functions  //
// & values of the intMinHeap class located in intMinHeap.h   //
// massimoginella12@gmail.com                                 //
// ********************************************************** //

#include <string>
#include <utility>
#include <iostream>
#include "intMinHeap.h"


// constructor for intMinHeap. Initializes heap array, size,  & checks input capacity.
intMinHeap::intMinHeap(int desired_capacity){
    if (desired_capacity < 0) {
        std::cerr << "Capacity cannot be less than 0. Capacity automatically set to 1." << std::endl;
        capacity = 1;
    } else {
        capacity = desired_capacity;
    }
    size = 0;
    A = new int [capacity];
}


// destructor for intMinHeap. Removes allocated memory dedicated to heap array. 
intMinHeap::~intMinHeap(){
    delete[] A;
}


// function that creates a second array, copies heap array into it, and sorts it
// returns sorted array along with its size
std::pair <int *, int> intMinHeap::heapsort(){
    int original_size = size;
    int *A_original = A;
    int *A_sorted = new int [size];
   
    for (int i = 0; i < size; i++) { 
        A_sorted[i] = A[i];
    }
 
    A = A_sorted;

    for (int i = size - 1; i > 0; i--) {
        swap(0, i);
        size--;
        heapify(0);
    }

    size = original_size; 
    A = A_original;
    // FIXED UNECESSARY DELETION OF A_ORIGINAL POINTER

    return std::pair<int *, int> (A_sorted, size);
}


// function that prints the contents of the heap array
// returns a string storing the heap array output
std::string intMinHeap::toString(){
    std::string heap_list = "";    
        
    heap_list = "heap size " + std::to_string(size) + ": ";    

    for (int i = 0; i < size; i++) {
        if (i != (size - 1)) {
            heap_list += std::to_string(A[i]) + ", ";
        } else {
            heap_list += std::to_string(A[i]);
        }
    }

    return heap_list;
}


// function that takes parameter k (input) and stores it into the heap
// returns true if the input was stored, and false if the heap is full
bool intMinHeap::heapinsert(int k){
    if (isFull()) {
        return false;
    }

    size++;
    A[size - 1] = k + 1;
    decreasekey(size - 1, k);
    return true;
}


// function that returns the minimum value (A[0]) of the heap array
// returns the value at A[0] if size > 0, and 0 if size == 0
int intMinHeap::minimum(){
    if (size > 0) {
        return A[0];
    }

    return 0;
}


// function that extracts the minimum value (A[0]) of the heap
// returns the minimum value stored at A[0] or returns 0 if size <= 0
int intMinHeap::extractmin(){
    if (size <= 0) {
        return 0;
    }
    int min = A[0];
    A[0] = A[size - 1];
    size--;
    heapify(0);
    return min;
}


// function that bubbles values up the heap if they are smaller than their parent
// returns nothing
void intMinHeap::decreasekey(int i, int k){
    if (i < 0 || i > (size - 1)) {
        return;
    }
    
    if (A[i] <= k) {
        return;
    }

    A[i] = k;
    
    while (i > 0 && A[parent(i)] > A[i]) {
        swap(i, parent(i));
        i = parent(i);
    } 
}


// function that returns the status of the heaps emptyness
// returns true if heap is empty, and false if not
bool intMinHeap::isEmpty(){
    if (size == 0) {
        return true;
    }

    return false;
}


// function that returns the status of the heaps fullness
// returns true if heap is full, and false if not
bool intMinHeap::isFull(){
    if (size == capacity) {
        return true;
    }
    
    return false;
}


// function that finds the minimum value of A[] at the three indexes i, left child, and right child
// returns the index that contains the minimum value A[min_index]
int intMinHeap::minOf3(int i, int i_left,  int i_right){
    int min_index = i;
 
    if (i_left < size && A[i_left] < A[min_index]) {
        min_index = i_left;
    }
    
    if (i_right < size && A[i_right] < A[min_index]) {
        min_index = i_right;
    }

    return min_index;
}


// function that gets the index of the left child of index i
// returns index of left child
int intMinHeap::left(int i){
    return ((i * 2) + 1);
}


// function that gets the index of the right child of index i
// returns index of right child
int intMinHeap::right(int i){
    return ((i * 2) + 2);
}


// function that gets the parent of index i
// returns the index of parent
int intMinHeap::parent(int i){
    return ((i - 1) / 2);
}

// function that builds a heap out of an un-heapified array A
// returns nothing
void intMinHeap::buildheap(){
    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(i);
    }

    return;
}


// function that bubbles down a value at an index if one child is less than it
// returns nothing
void intMinHeap::heapify(int i){
    int n = minOf3(i, left(i), right(i));
    
    if (n != i) {
        swap(i, n);
        heapify(n);
    }

    return;
}


// WORKS!
void intMinHeap::swap(int i, int k) {
    int temp = A[i];
    A[i] = A[k];
    A[k] = temp;
 
    return;
}
