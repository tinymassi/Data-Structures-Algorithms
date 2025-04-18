// ********************************************************** //
// This main function creates a UI as well as uses the member // 
// functions of the hashTable class.                          //
// massimoginella12@gmail.com                                 //
// ********************************************************** //

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "hashtable.h"


// Splits the input string into components int key and string data
std::pair<int, std::string> split_input(std::string line) {
    std::string num_str = "";
    std::string data = "";

    for (size_t i = 0; i < line.length(); i++) {
        if (i < 9) {
            num_str += line[i];
        } else if (i > 9) {
            data += line[i];
        }
    }

    int key = std::stoi(num_str);

    return std::make_pair(key, data);
}


int main() {

    hashTable table  = 178000;

    std::string instruction = "";
    std::string file_name = "";
    std::string line = "";

    std::vector<std::string> table_copy;

    std::pair<int, std::string> values;

    bool not_done = true;
 
    while (not_done) {
        std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
        std::getline(std::cin , instruction);

        if (instruction == "1") {
            std::cout << "read hash table - filename? ";
            std::getline(std::cin, file_name);
            std::ifstream file(file_name + ".txt");
            while(std::getline(file, line)) {
                values = split_input(line);
                table.insert(values.first, values.second);
            }

        } else if (instruction == "2") {
            std::cout << "input new record: " << std::endl;
            std::getline(std::cin, line);
            values = split_input(line);
            table.insert(values.first, values.second);

        } else if (instruction == "3") {
            std::cout << "delete record - key? ";
            std::getline(std::cin, line);
            if (table.search(std::stoi(line)) != "") {
                std::cout << "Delete: " << line << " " << table.search(std::stoi(line)) << std::endl;
                table.delete_(std::stoi(line));
            } else {
                std::cout << "Delete not found: " << line << std::endl;
            }

        } else if (instruction == "4") {
            std::cout << "search for record - key? ";
            std::getline(std::cin, line);
            if (table.search(std::stoi(line)) != "") {
                std::cout << "Found: " << line << " " << table.search(std::stoi(line)) << std::endl;
            } else {
                std::cout << "Search not found: " << line << std::endl;
            }

        } else if (instruction == "5") {
            std::cout << "clearing hash table." << std::endl;
            table.clear();

        } else if (instruction == "6") {
            std::cout << "write hash table - filename? ";
            std::getline(std::cin, file_name);
            std::ofstream file(file_name + ".txt");
            table_copy = table.all_entries();
            for (size_t i = 0; i < table_copy.size(); i++) {
                file << table_copy[i] << std::endl;
            }

        } else if (instruction == "7") {
            not_done = false;

        } else {
            std::cout << "Invalid entry. Please enter digit 1 - 7." << std::endl;
        }

        line = "";
    }

    return 0;
}