// ************************************************************************** // 
// This program is the function implementation of the MazeGenerator class     //
// located in maze.h. This code is responsible for generating a maze of size  //
// n x n, and outputting it to the user.                                      //
//                                                                            //
// author: massimoginella12@gmail.com                                         //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <cstdlib>
#include "disjoint.h"
#include "maze.h"
// FIXED ORDER OF .H INCLUDES

// Constructor for MazeGenerator that receives 'n' for an 'n x n' maze
// and creates the maze itself filled with values 11 for the opening, 14 
// for the exit, and 15 for all other cells.
MazeGenerator::MazeGenerator (int n) : maze_dim(n) {
    std::size_t maze_size = n*n - 1;
    
    for (std::size_t i = 0; i < n*n; i++) {
        if (i == 0) {
            maze.push_back(11);                 // put opening in top left
        } else if (i == maze_size) {
            maze.push_back(14);                 // put opening in bottom right
        } else {
            maze.push_back(15);                 // fill the maze with full boxes
        }

        shuffled_indexes.push_back(i);
    }

    shuffled_indexes = shuffle(shuffled_indexes);
}



// Shuffles the vector containing all the maze indexes so that a cell can
// be accessed at random later.
std::vector<int> MazeGenerator::shuffle(std::vector<int> maze_indexes) {
    int rand_index = 0;

    for (std::size_t i = 0; i < maze_indexes.size(); i++) {
        rand_index = std::rand() % ((maze_indexes.size() - 1) - i + 1) + i; 
        std::swap(maze_indexes[i], maze_indexes[rand_index]);
    }

    return maze_indexes;
}



// Generates a maze using the disjoint set class by selecting a random cell,
// grabbing a random neighbor of that cell, checking if the neighbor and cell
// are part of the same set (if not, they are unioned and the wall between them
// is knocked down), then continues to do so until there is only one set (all 
// cells are connected and a path to complete the maze exists)
void MazeGenerator::generate_maze () {
    DisjointSet set(maze.size());
    int cell = 0;
    int neighbor = 0;
    std::pair<int, int> walls;
    std::size_t i = 0;

    while (set.num_sets() > 1) {                                // stop when all cells are connected (there is a way through the maze)
        if (i == shuffled_indexes.size()) {i = 0;}
        cell = shuffled_indexes[i];                             // grab a random cell at some index in the maze
        neighbor = get_neighbor(cell);                          // grab a random neighbor of the cell
        if (set.find(cell) != set.find(neighbor)) {             // if the cells are not connected, theres a wall between them
            set.Union(cell, neighbor);                          // union the two cells to show they are connected
            walls = get_walls(cell, neighbor);
            maze[cell] = maze[cell] - walls.first;
            maze[neighbor] = maze[neighbor] - walls.second; 
        }
        i++;
    }
}



// Initializes the lookup table used for converting the int values stored
// in the maze to strings that represent their HEX counterparts.
const std::string MazeGenerator::lookup[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};



// Prints the maze using the lookup table filled with the HEX counterparts.
void MazeGenerator::print_maze () {
    for (std::size_t i = 0; i < maze.size(); i++) {
        if (i % maze_dim == 0 && i != 0) {
            std::cout << std::endl;
        }
        std::cout <<  lookup[maze[i]];
    }
    std::cout << std::endl;         // NO ENDLINE FIXED!
}



// Depending on the neighbor to the randomly selected cell, we must
// find which two walls they share in common. In this case, 1 = right wall,
// 2 = bottom wall, 4 = left wall, and 8 = top wall.
std::pair<int, int> MazeGenerator::get_walls(int cell, int neighbor) {
    int cell_wall = 0;
    int neighbor_wall = 0;

    if (cell == (neighbor - 1)) {
        cell_wall = 1;
        neighbor_wall = 4;
    } else if (cell == (neighbor + 1)) {
        cell_wall = 4;
        neighbor_wall = 1;
    } else if (cell == (neighbor + maze_dim)) {
        cell_wall = 8;
        neighbor_wall = 2;
    } else {
        cell_wall = 2;
        neighbor_wall = 8;
    }

    return std::make_pair(cell_wall, neighbor_wall);
}



// Randomly picks a neighbor for a given randomly chosedn cell in
// the maze. There are 4 possibilities: 0 = top neighbor, 1 = right
// neighbor, 2 = left neighbor, and 3 = bottom neighbor
int MazeGenerator::get_neighbor(int cell) {
    int range = 4;
    int which_neighbor = -1;     // initialize which_neighbor to -1 to be a non existing option
    int neighbor_index = -1;     // set to -1 so that is_neighbor_valid = false and will activate while loop

    while(!is_neighbor_valid(cell, neighbor_index)) {      // runs if the random neighbor is not valid (out of bounds)
        which_neighbor = rand() % range;        // randomly select a neighbor

        if (which_neighbor == 0) {              // top neighbor selected
            neighbor_index = cell + maze_dim;
        } else if (which_neighbor == 1) {       // right neighbor selected
            neighbor_index = cell + 1;
        } else if (which_neighbor == 2) {       // left neighbor selected
            neighbor_index = cell - 1;
        } else {                                // bottom neighbor selected
            neighbor_index = cell - maze_dim;
        }
    }

    return neighbor_index;
}



// Checks if the randomly chosen neighbor is valid given the position of
// the randomly chosen cell.
bool MazeGenerator::is_neighbor_valid(int cell, int neighbor_index) {
    if (cell % maze_dim == 0 && neighbor_index == (cell - 1)) {                   // check if the neighbor is to the left of a boundary cell
        return false;
    } else if ((cell + 1) % maze_dim == 0 && neighbor_index == (cell + 1)) {      // check if the neighbor is to the right of a boundary cell
        return false;
    }

    if (neighbor_index > 0 && neighbor_index < static_cast<int>(maze.size())) {   // static cast to remove warnings...
        return true;
    }

    return false;
}