// ******************************************************************* //
// This header file contains the intMinHeap class.                     //
// All the member variables and functions utilized in intMinHeap.cpp   //
// are created/initialized here. This class is responsible for the     //
// creation of a minimum heap data structure that accepts integers as  //
// values and uses an array for node organization.                     //
// massimoginella12@gmail.com                                          //
// ******************************************************************* //

#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <utility>


class intMinHeap {

    public:

        intMinHeap(int);                        // empty heap with this capacity
        ~intMinHeap();                          // clean up allocated memory
        std::pair<int *, int> heapsort();       // return sorted array and size from heap
        std::string toString();                 // return a string with the heap values a as a comman separated list    
        bool heapinsert(int);                   // add element to heap; return success
                                                // min functions should return 0 in empty heaps
        int minimum();                          // return value of A[root]
        int extractmin();                       // return and remove A[root]
        void decreasekey(int i, int k);         // A[i] decreased to k
        bool isEmpty();                         // check if heap is empty?
        bool isFull();                          // check if heap is full??

    private:

        int minOf3(int, int, int);              // with bounds check! same as index of min??
        int left(int);
        int right(int);
        int parent(int);
        void buildheap();                       // convert array to a heap
        void heapify(int i);                    // heapify at position i
        void swap(int i, int n);                // swaps values at indexes i and n
        int *A;                                 // array of integers - data
        int capacity;                           // max size of array A
        int size;                               // data size in array

};

#endif
