// ************************************************************* //
// This program is used to demonstrate the functionality of the  //
// intMinHeap class.                                             //
// massimoginella12@gmail.com                                    //
// ************************************************************* //

#include <iostream>
#include <utility>
#include "intMinHeap.h"

int main() {
    
    intMinHeap myHeap(2400000);

    std::string line = "";

    while (std::getline(std::cin, line)) {
        if (line == "0") {

            std::cout << myHeap.toString() << std::endl;

        } else if (line == "-1") {

            if (myHeap.isEmpty()) {    
                std::cerr << "Heap is empty. Nothing to extract."  << std::endl;
            } else {
                std::cout << "extract min: " << myHeap.extractmin() << std::endl;
            }

        } else if (line == "-2") {
            // FIXED BY REMOVING THE OUTPUT "HEAP IS EMPTY, NOTHING TO SORT IF HEAP SIZE IS 0"
            std::pair <int *, int> sorted_heap = myHeap.heapsort();
            std::cout << "sorted array: [";
            for (int i = 0; i < (sorted_heap.second); i++) {
                if (i == sorted_heap.second - 1) {
                    std::cout << sorted_heap.first[i];
                } else {
                    std::cout << sorted_heap.first[i] << ", ";
                }
            }
            std::cout << "]" << std::endl;      
            delete[] sorted_heap.first; 

        } else if (line != " " && !line.empty()){
            
            if (!myHeap.heapinsert(std::stoi(line))) {
                std::cerr << "Heap is full. Cannot insert." << std::endl;
            } else {
                std::cout << "insert: " << line << std::endl;
            }

        }
    } 
    return 0;
}

