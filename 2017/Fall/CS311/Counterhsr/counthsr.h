// Jim Samson
// October 09, 2017
// counthsr.hpp
//

#include <vector>

using std::vector;

#ifndef COUNTHSR_FILE
#define COUNTHSR_FILE

typedef vector<vector<int>> board2DArray;

int countHSR(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y);

int countHSR_recurse(board2DArray & boardArray, int dim_x, int dim_y, int finish_x, int finish_y, int pos_x, int pos_y, int squaresLeft);

#endif  //COUNTHSR_FILE
