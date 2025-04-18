// ****************************************************************** //
// This header file contains the creation of the hashTable class.     //
// The code for each of these functions can be found in hashtable.cpp //
// massimoginella12@gmail.com                                         //
// ****************************************************************** //


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>

class hashTable {
public:
  hashTable(int=100); // build a table
  void insert(int key, std::string data);
  void clear();
  void delete_(int key);
  std::string search(int key);
  std::vector<std::string> all_entries();
private:
  int find(int index, int key); // helper search fn
  int hash(int key); // hash value for record
  const int m = 0; // size of table
  const double c = 0.618034;
  std::vector<std::pair<int, std::string>>* table;
};


#endif 