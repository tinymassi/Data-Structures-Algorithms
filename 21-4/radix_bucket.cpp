// ********************************************************************* //
// This program is a combination of the radix and bucket sort algorithm. //
// The algorithm takes an vector A containing unsorted  ints. It uses    //
// radix sort by grabbing the ithi digit on a value in A and stores it   //
// in a respective bucket. The values of A are then organized based      //
// on their positons in the bucket vector. After a certain number        //
// of iterations, A will contain sorted values. Radix bucket sort works  //
// satisfies O(n) time complexity.                                       //
// massimoginella12@gmail.com                                            //
// ********************************************************************* //


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>


void radix_bucket_sort(std::vector<int>& A, int n, int d, int k);
int ith_digit(int num, int i);


// utilizes a hybrid between radix sort and bucket sort to organize 
// integer values in a vector 'A' of size n. d = digit size, 
// k = bucket size (based on the base of number i.e base 2, 10, etc...)
void radix_bucket_sort(std::vector<int>& A, int n, int d, int k) {
    std::vector<int> bucket[k];
    int r = 0;
    int bucket_size = 0;
    int A_index = 0;

    for (int i = 0; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            r = ith_digit(A[j], i);
            bucket[r].push_back(A[j]); 
        }
        
        for (int j = 0; j < k; j++) {
            bucket_size = bucket[j].size();
            for (int q = 0; q < bucket_size; q++) { 
                A[A_index] = bucket[j][q]; 
                A_index++;
            }
            for (int q = 0; q < bucket_size; q++) {
                bucket[j].pop_back();
            }
        }
        A_index = 0;
    }
}


// function that grabs the ith digit of an integer 'num'
int ith_digit(int num, int i) {
    return (num/static_cast<int>(pow(10, i))) % 10;
}


// main function that accepts integer inputs and calls 
// radix bucket sort to organize said inputs
int main() {
    
    std::vector<int> inputs = {};
    int input = 0;    

    while (std::cin >> input ) {
        inputs.push_back(input);
    }

    radix_bucket_sort(inputs, inputs.size(), 9, 10);
    
    for (size_t i = 0; i < inputs.size(); i++) {
        std::cout << std::setw(9) << std::setfill('0') << inputs[i] << std::endl;
    }
  

    return 0;
}