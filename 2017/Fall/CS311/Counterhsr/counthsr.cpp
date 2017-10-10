// Jim Samson
// October 09, 2017
// counthsr.cpp
// This file is a

#include "counthsr.h"

int countHSR(int dim_x, int dim_y, int hole_x, int hole_y, int start_x, int start_y, int finish_x, int finish_y)
{
	if(dim_x == 0 || dim_y == 0)
		return 0;

	board2DArray newBoard;
	int count = 0;

	newBoard.resize(dim_x, vector<int>(dim_y,0));
	newBoard[start_x][start_y] = 1;
	newBoard[hole_x][hole_y] = 1;
	count = (dim_x*dim_y)-2;

	return countHSR_recurse(newBoard, dim_x, dim_y, finish_x, finish_y, start_x, start_y, count);
}

int countHSR_recurse(board2DArray & boardArray, int dim_x, int dim_y, int finish_x, int finish_y, int pos_x, int pos_y, int squaresLeft)
{
	if (squaresLeft == 0 && pos_x == finish_x && pos_y == finish_y)
	{
        return 1;
  }

	// Recursive
	int total = 0;

	//move right
  if ((pos_x+1 < dim_x) && boardArray[pos_x+1][pos_y] == 0)
	{
      pos_x++;
      boardArray[pos_x][pos_y] = 1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_x--;
      squaresLeft++;
  }
  //move left
  if (((0 <= pos_x-1 && pos_x-1 < dim_x)) && boardArray[pos_x-1][pos_y] == 0)
	{
      pos_x--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_x++;
      squaresLeft++;
  }
  //move up
  if ((pos_y+1 < dim_y) && boardArray[pos_x][pos_y+1] == 0)
	{
      pos_y++;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_y--;
      squaresLeft++;
  }
  //move down
  if ((0 <= pos_y-1 && pos_y-1 < dim_y) && boardArray[pos_x][pos_y-1] == 0)
	{
      pos_y--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_y++;
      squaresLeft++;
  }

  //move right up
  if ((pos_x+1 < dim_x) && (pos_y+1 < dim_y) && boardArray[pos_x+1][pos_y+1] == 0)
	{
      pos_x++;
      pos_y++;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_x--;
      pos_y--;
      squaresLeft++;
  }
  //move left up
  if (((0 <= pos_x-1) && (pos_y+1 < dim_y)) && boardArray[pos_x-1][pos_y+1] == 0)
	{
      pos_x--;
      pos_y++;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_x++;
      pos_y--;
      squaresLeft++;
  }
  //move right down
  if ((pos_x+1 < dim_x) && (0 <= pos_y-1) && boardArray[pos_x+1][pos_y-1] == 0)
	{
      pos_x++;
      pos_y--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_x--;
      pos_y++;
      squaresLeft++;
  }
  //move left down
  if ((0 <= pos_x-1 && pos_x-1 < dim_x) && (0 <= pos_y-1 && pos_y-1 < dim_y) && boardArray[pos_x-1][pos_y-1] == 0)
	{
      pos_y--;
      pos_x--;
      boardArray[pos_x][pos_y] =1;
      squaresLeft--;
      total += countHSR_recurse(boardArray, dim_x, dim_y, finish_x, finish_y, pos_x, pos_y, squaresLeft);
      boardArray[pos_x][pos_y] = 0;
      pos_y++;
      pos_x++;
      squaresLeft++;
  }
	return total;
}
