// ************************************************************* //
// This program is an implementation of the quicksort algorithm  //
// that utilizes far-right pivot as well as median of 3 pivot.   //
// Median of 3 is used in the case that the input container has  //
// a size of over 500.                                           //
// Input: Positive integers with leading zeros (9 digits total)  //
// Output: Sorted vector.                                        //
// massimoginella12@gmail.com                                    //
// ************************************************************* //

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>


void quicksort(std::vector<int>& A, int p, int r);
int partition(std::vector<int>& A, int p, int r);
int median_of_3(std::vector<int>& A, int p, int r);
void sort_it(std::vector<int>& A, int p, int r);

// picks a pivot, then swaps data less than the pivot.
// returns a new starting point for the next iteration
// of quicksort.
int partition (std::vector<int>& A, int p, int r) {
    if (A.size() > 500) {
        int median = median_of_3(A, p, r); 
        std::swap(A[median], A[r]);
    }
    
    int x = A[r];
    int i = p - 1;
    
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);           
        }
    }
    
    std::swap(A[i+1], A[r]);
    return i + 1;
}

// recursive function that retrieves a split point from partition
// and continues to break the container into smaller pieces as it 
// continues to get sorted.
void quicksort (std::vector<int>& A, int p, int r) {
    int q = 0;

    if (p < r) {
        q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
    return;
}


// if the size of the container is greater than 500,
// the median_of_3 function is called in which the 
// pivot is chosen based on the median of 3 indexes in
// the container.
int median_of_3 (std::vector<int>& A, int p, int r) {
    int mid = (p + r) / 2;
    int median = 0;    

    if (A[p] > A[mid]) {
    
        if (A[mid] > A[r]) {
            median = mid;
        } else if (A[p] > A[r]) {
            median = r;
        } else {
            median = p;
        }

    } else {
        
        if (A[p] > A[r]) {
            median = p;
        } else if (A[mid] > A[r]) {
            median = r;
        } else {
            median = mid;
        }

    }

    return median;
}


// wrapper function that calls quicksort
void sort_it (std::vector<int>& A, int p, int r) {
    quicksort(A, p, r);
    return;
}


int main() {
    
    std::vector<int> inputs = {};
    std::string line = "";    

    while (std::getline(std::cin, line)) {
        inputs.push_back(std::stoi(line));
    }

    sort_it(inputs, 0, inputs.size() - 1);
    
    std::vector<std::string> sorted_inputs = {};
    
    for (size_t i = 0; i < inputs.size(); i++) {
        sorted_inputs.push_back(std::to_string(inputs[i]));
    }
  
    std::string str = "";
    for (size_t i = 0; i < sorted_inputs.size(); i++) {
        str = sorted_inputs[i];
        for (size_t j = 0; j < (9 - str.length()); j++) {
            sorted_inputs[i] = "0" + sorted_inputs[i];
        }
        std::cout << sorted_inputs[i] << std::endl;
    }

    return 0;
}