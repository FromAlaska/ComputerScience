// Jim Samson
// October 09, 2017
// counthsr.cpp
// This is for Assignment 4

#include "counthsr.h"

// countHSR()
// See header for details.
int countHSR(int dim_x, int dim_y, int hole_x, int hole_y, int start_x, int start_y, int finish_x, int finish_y)
{
	if(dim_x == 0 || dim_y == 0)
		return 0;

	// Creates a new 2-Dimensional array, then sets a counter to zero.
	board2DArray newBoard;
	int count = 0;

	// Sets the dimenstions, starting postion, hole position of the board.
	newBoard.resize(dim_x, vector<int>(dim_y,0));
	newBoard[start_x][start_y] = 1;
	newBoard[hole_x][hole_y] = 1;
	count = (dim_x*dim_y)-2;

	return countHSR_recurse(newBoard, dim_x, dim_y, finish_x, finish_y, start_x, start_y, count);
}

// countHSR_recurse()
// See header for details.
int countHSR_recurse(board2DArray & boardArray, int dim_x, int dim_y, int finish_x, int finish_y, int pos_x, int pos_y, int squaresLeft)
{
	if(squaresLeft == 0 && pos_x == finish_x && pos_y == finish_y)
	{
        return 1;
  }

	// Recursive
	int total = 0;

	// Move Right
  if((pos_x+1 < dim_x) && boardArray[pos_x+1][pos_y] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_x++;
      boardArray[pos_x][pos_y] = 1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_x--;
      squaresLeft++;
  }
  // Move Left
	//
  if(((0 <= pos_x-1 && pos_x-1 < dim_x)) && boardArray[pos_x-1][pos_y] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_x--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_x++;
      squaresLeft++;
  }
  // Move Up
  if((pos_y+1 < dim_y) && boardArray[pos_x][pos_y+1] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_y++;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_y--;
      squaresLeft++;
  }
  // Move Down
  if((0 <= pos_y-1 && pos_y-1 < dim_y) && boardArray[pos_x][pos_y-1] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_y--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_y++;
      squaresLeft++;
  }

  // Move Right Up
  if((pos_x+1 < dim_x) && (pos_y+1 < dim_y) && boardArray[pos_x+1][pos_y+1] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_x++;
      pos_y++;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_x--;
      pos_y--;
      squaresLeft++;
  }
  // Move Left Up
  if(((0 <= pos_x-1) && (pos_y+1 < dim_y)) && boardArray[pos_x-1][pos_y+1] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_x--;
      pos_y++;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_x++;
      pos_y--;
      squaresLeft++;
  }
  // Move Right Down
  if((pos_x+1 < dim_x) && (0 <= pos_y-1) && boardArray[pos_x+1][pos_y-1] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_x++;
      pos_y--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_x--;
      pos_y++;
      squaresLeft++;
  }
  // Move Left Down
  if((0 <= pos_x-1 && pos_x-1 < dim_x) && (0 <= pos_y-1 && pos_y-1 < dim_y) && boardArray[pos_x-1][pos_y-1] == 0)
	{
			// This moves the position of the x & y axis and adds a one to the current spot in the array.
      pos_y--;
      pos_x--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;

			// Add to the total amount of recursive calls.
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);

			// Reset current position
      boardArray[pos_x][pos_y] = 0;
      pos_y++;
      pos_x++;
      squaresLeft++;
  }
	return total;
}
