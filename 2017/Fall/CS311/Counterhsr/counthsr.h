// Jim Samson
// October 09, 2017
// counthsr.hpp
// This is for Assignment 4.

#ifndef COUNTHSR_FILE
#define COUNTHSR_FILE

#include <vector>
using std::vector;

typedef vector<vector<int>> board2DArray;

// countHSR
// This function returns the number of possible choices that the spider can take.
// It returns the recursive function of the x amount of times it took to make it to the finish.
// Pre:
//      dim_x and dim_y cannot be zero.
int countHSR(int dim_x, int dim_y, int hole_x, int hole_y, int start_x, int start_y, int finish_x, int finish_y);

// countHSR_recurse()
// This function is to check if the spider can jump onto the next square diagonally, up, down, left, right.
// It also checks if the current position is equal to the final position, or if the squares that are left is zero.
// Pre:
//			The number of squares that are left cannot be negative.
int countHSR_recurse(board2DArray & boardArray, int dim_x, int dim_y, int finish_x, int finish_y, int pos_x, int pos_y, int squaresLeft);

#endif  //COUNTHSR_FILE
