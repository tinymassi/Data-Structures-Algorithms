// **************************************************************** //
// This header file contains the declaration of the MazeGenerator   //
// class and all its public and private counterparts. The code for  //
// each function can be found in maze.cpp. The MazeGenerator class  //
// randomly generates a maze of size nxn provided by user input     //
// upon declaration of a MazeGenerator object.                      //
//                                                                  //
// author: massimoginella12@gmail.com                               //
// **************************************************************** //

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>


class MazeGenerator {
    public:
    MazeGenerator(int dimension);
    void generate_maze();
    void print_maze();
    
    private:
    std::vector<int> shuffle(std::vector<int> maze_indexes);
    std::pair<int, int> get_walls(int cell, int neighbor);
    int get_neighbor(int cell);
    bool is_neighbor_valid(int cell, int neighbord_index);
    std::vector<int> maze;
    std::vector<int> shuffled_indexes;
    const int maze_dim = 0;
    const static std::string lookup[16];
};


#endif