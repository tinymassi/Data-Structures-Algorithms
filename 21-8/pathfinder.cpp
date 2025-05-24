/*
This cpp file contains the code for each function declared in
the pathfinder class located in the pathfinder.h header file.
In short, this program receives a 2D vector hex maze in the 
find_path function, which uses the breadth first search
algorithm to traverse each coordinate of the maze while using
helper functions to streamline the process of finding/validating
neighbors, checking walls, etc. Finally, the parents of each 
coordinate is passed to the print_path function which will output
the coordinates to traverse the maze and complete it.

author: massimoginella12@gmail.com
*/

#include <iostream>
#include <utility> 
#include <queue>
#include <sstream>
#include <map>
#include "pathfinder.h"

// class constructor.
pathfinder::pathfinder(){
    maze_width = 0;
    maze_height = 0;
    h_nudges = {1, 0, -1, 0};
    v_nudges = {0, 1, 0, -1};
}




// the find_path function receives a 2D vector maze of hex ints and uses
// breadth first search to traverse each cell in order to solve it while
// respecting the rules of walls that divide the cells apart
void pathfinder::find_path(std::vector<std::vector<int>> maze) {
    maze_width = maze[0].size();
    maze_height = maze.size();

    std::map <std::pair<int, int>, std::pair<int, int>> parent;
    std::map <std::pair<int, int>, bool> visited;
    std::queue<std::pair<int, int>> queue;
    
    std::pair<int, int> starting_cell = {0, 0};     // starting cell begins at top left of maze
    parent[starting_cell] = {-1, -1};               // starting cell has no parent 
    visited[starting_cell] = true;                  // starting cell has been visited
    queue.push(starting_cell);                      // begin algorithm by placing starting_cell first
                                                    // in line
    std::pair<int, int> cell;
    std::pair<int, int> neighbor;

    while(!queue.empty()) {
        cell = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++) {                                  // for checking a max of 4 neighbors/cell
            neighbor = get_neighbor(cell, i);                          // returns the cells neighbor based on value of i

            if (is_neighbor_valid(neighbor) && !visited[neighbor]) {   // check if neighbor coord is out of bounds and if
                                                                       // the neighbor has already been visited
                if (check_wall(maze[cell.second][cell.first], i)) {    // check if there is a wall separating cell & neighbor
                    parent[neighbor] = cell;
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        visited[cell] = true;
    }

    print_path(parent);     // the chain of parents from the final cell (width - 1, height - 1) will reveal the path 
}




// takes takes a map of (x,y) cord -> (x,y) parent values that detail the parents of each cell 
// in the maze. This function follows the chain of parents from the final cell which is ultimately
// the path used to solve the maze.
void pathfinder::print_path(std::map<std::pair<int, int> , std::pair<int, int>> parents) {
    std::pair<int, int> cell = {maze_width - 1, maze_height - 1};    // begin at bottom right cell
    std::vector<std::string> path;
    
    while (cell != std::make_pair(-1, -1)) {                         // if the parent is (-1, -1) that means we are in the top left of the maze (AKA done)
        std::ostringstream coordinate;
        coordinate << "(" << cell.first << ", " << cell.second << ")";
        path.push_back(coordinate.str());
        cell = parents[cell];                                        // go to the next parent
    }

    for (int i = path.size() - 1; i >= 0; i--)  {
        std::cout << path[i] << std::endl;
    }
}




// this function finds the neighbor of a given cell based upon the value of i 
// in the for loop from the find_path function. below is info about which neighbor
// each value of i accesses:
// if i = 0: (1, 0) = right neighbor. i = 1: (0, 1) = top neighbor.
// if i = 2: (-1, 0) = left neighbor. i = 3: (0, -1) = bottom neighbor.
std::pair<int, int> pathfinder::get_neighbor(std::pair<int, int> cell, int i) {
    int x = cell.first + h_nudges[i];
    int y = cell.second + v_nudges[i];

    return std::make_pair (x, y);
}




// this function checks if the neighbors coordinates are within the boundaries of
// the maze.
bool pathfinder::is_neighbor_valid(std::pair<int, int> neighbor) {
    int x = neighbor.first;
    int y = neighbor.second;
    if (x < 0 || x > maze_width - 1 || y < 0 || y > maze_height - 1) {
        return false;
    }

    return true;
}




// this function checks if there is a wall between the current cell, and the neighbor
// it is looking to traverse to.
// 0001 = right wall, 0010 = bottom wall, 0100 = left wall, and 1000 = top wall
// example: 1011 has a top, bottom, and right wall.
// if the cells binary value at 'i' is 1, then there is a wall which means that we cannot
// traverse to the neighbor in such a way. otherwise, if the cells binary value at 'i' 
// is 0, then there is no wall and we can traverse to the neighbor. 
bool pathfinder::check_wall(int cell_val, int i) {
    if (cell_val & (1 << i)) {
        return false;
    }
    return true;
}




// destructor for the pathfinder class.
pathfinder::~pathfinder(){}