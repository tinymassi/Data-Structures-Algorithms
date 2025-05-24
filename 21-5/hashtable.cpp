// ********************************************************* //
// This cpp file details the code associated with the member //
// functions of the hashtable class located in hashtable.h   //
// massimoginella12@gmail.com                                //
// ********************************************************* //

// FIXED COMPILE-TIME WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "hashtable.h"


// constructor for the hashtable class. sets table_size to user input
// specification or defaults to 100 if no user input is given.
hashTable::hashTable(int table_size) : m(table_size) {
    if (table_size > 0) {
        table = new std::vector<std::pair<int, std::string>> [m];
    }
}


// receives some data and inserts it into the hash table
void hashTable::insert(int key, std::string data){
    if (key < 0) {
        return;
    }

    table[hash(key)].push_back(make_pair(key, data));
}


// clears the entire hash table 
void hashTable::clear() {
    int bucket_size = 0;
    for (int i = 0; i < m; i++) {
        if (table[i].size() > 0) {
            bucket_size = table[i].size();
            for (int k = 0; k < bucket_size; k++) {
                table[i].pop_back();
            }
        }
    }
}


// receives a key and deletes the associated data attached
// to that key in the hash table
void hashTable::delete_(int key){
    if (key < 0) {
        return;
    }

    int data_index = find(hash(key), key);

    if (data_index != -1) {
        std::swap(table[hash(key)][data_index], table[hash(key)].back());
        table[hash(key)].pop_back();
    }
}


// receives a key and searches the hash table for the data associated 
// with that key. It then returns "" if the key is not in the table or
// returns the string if the key is associated with some data
std::string hashTable::search(int key){
    if (key < 0) {
        return "";
    }

    std::string return_str = "";
    int data_index = find(hash(key), key);

    if (data_index != -1) {
        return_str = table[hash(key)][data_index].second;
    }
    
    return return_str;
}


// returns all the data in the hash table through a vector of strings
std::vector<std::string> hashTable::all_entries() {
    std::string key_str = "";
    std::string data = "";
    std::string zero_pad = "";
    std::vector<std::string> table_contents;

    for (int i = 0; i < m; i++) {
        if (table[i].size() > 0) {
            for (size_t k = 0; k < table[i].size(); k++) {
                key_str = std::to_string(table[i][k].first);
                data = table[i][k].second;
    
                for (size_t j = 0; j < (9 - key_str.length()); j++) {
                    zero_pad += '0';
                }

                key_str = zero_pad + key_str;

                table_contents.push_back(key_str + " " + data);
                key_str = "";
                data = "";
                zero_pad = "";
            }
        }
    }

    return table_contents;
}


// helper function for search and delete that indexes through 
// a bucket in the hash table given an index and key to search for
// the function then will return the bucket index of the key or -1 
// if no key is found.
int hashTable::find(int index, int key){ 
    
    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == key) {
            return i;
        }
    }

    return -1;
}


// calculates the index at which a key value pair will be stored in
// the hash table.
int hashTable::hash(int key){
    return floor(m * (key * c - floor(key * c)));
}



hashTable::~hashTable() {
    delete[] table;
}