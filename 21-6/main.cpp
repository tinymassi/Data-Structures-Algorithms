// **************************************************** //
// Main program that demonstrates the functionality of  //
// the maze generator class MazeGenerator. To run this  //
// code, run 'make' in your terminal, then type ./p6    //
// 'n', where 'n' is the n x n dimention of your maze.  //
// To see your maze, copy the n x n output and paste it //
// in the following maze visalizer website:             //
// https://jeff.cis.cabrillo.edu/tools/cs21_maze_viewer //
//                                                      //
// author: massimoginella12@gmail.com                   //
// **************************************************** //

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "maze.h"
// FIXED INCLUDE THAT WASNT NECESSARY.


int main(int argc, char* argv[]) {
    int n = std::stoi(argv[1]);
    std::srand(std::time(0));

    if (n >= 3) {
        MazeGenerator maze (n);
        maze.generate_maze();
        maze.print_maze();
    } else {
        std::cerr << "Invalid maze dimension. Please set dimension >= 3." << std::endl;    
    }

    return 0;
}