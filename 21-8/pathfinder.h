/*
This header file contains the initialization of the 'pathfinder' class.
Within the class are a number of public and private functions. The purpose
of this class is to receive a 2D vector of hex integers representing a maze
and to solve said maze and print the path taken to solve it via the use of a
breadth first search algorithm. The code and documentation for each function
in this class can be found in the pathfinder.cpp program.

author: massimoginella12@gmail.com
*/

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <utility>
#include <map>

class pathfinder {

    public:
        pathfinder();
        void find_path(std::vector<std::vector<int>> maze);
        ~pathfinder();

    private:
        void print_path(std::map<std::pair<int, int>, std::pair<int, int>> parent);
        std::pair<int, int> get_neighbor(std::pair<int, int> cell, int i);
        bool is_neighbor_valid(std::pair<int, int> neighbor);
        bool check_wall(int cell_val, int i);

        std::vector<int> h_nudges;
        std::vector<int> v_nudges;
        int maze_width;
        int maze_height;


};


#endif