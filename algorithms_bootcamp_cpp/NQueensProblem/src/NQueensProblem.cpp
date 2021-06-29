#include "NQueensProblem.h"
#include <iostream>
using std::cout;

QueensProblem::QueensProblem(int _numOfQueens)
	: numOfQueens(_numOfQueens)
{
	//create 2D array with as many rows and columns as the number of queens
	chessTable.resize(numOfQueens);
	for (auto &chessRow : chessTable)
		chessRow.resize(numOfQueens);
}

void QueensProblem::solve()
{
	//solve the problem starting with the first column (0)
	if (setQueens(0)) {
		printQueens();
	}
	else {
		cout << "There is no solution...\n";
	}
}

bool QueensProblem::setQueens(int colIndex)
{
	//if we have considered as many queens as the number of rows/columns then WE ARE DONE !!!
	//so we have found valid places for all the queens
	if (colIndex == numOfQueens) {
		return true;
	}

	//consider all the rows in a single column to check where to put the queen
	for (int rowIndex = 0; rowIndex < numOfQueens; ++rowIndex) {

		//check if the given location is valid (queen can not be attacked by other queens)
		if (isPlaceValid(rowIndex, colIndex)) {

			//valid place so put a queen to this location
			chessTable[rowIndex][colIndex] = 1;

			//check the next queen (next column) (every column has one queen)
			//we manage to put a queen in the next column -> return true
			if (setQueens(colIndex + 1)) {
				return true;
			}

			// we failed to put a given queen in a given column: BACKTRACKING !!!
			//1: denotes a queen and 0: is an empty space so we re-initialize the location
			//what to do? keep iterating and consider the next row (maybe it is a valid place for the queen)
			chessTable[rowIndex][colIndex] = 0;
		}
	}

	//we have considered all the rows without any result which means there is no solution
	//we are not able to put the queens such that they can not attack each other
	//so we backtrack -> maybe we have to change the position of the previous queens
	return false;
}

bool QueensProblem::isPlaceValid(int rowIndex, int colIndex) const
{
	//there can not be another queen in the same row: they would be able to attack each other
	for (int i = 0; i < colIndex; i++)
		if (chessTable[rowIndex][i] == 1)
			return false;

	//there is a queen in the diagonal (from top left to bottom right direction)
	for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--) {
		if (chessTable[i][j] == 1)
			return false;
	}

	//there is a queen in the diagonal (from top right to bottom left direction)
	for (int i = rowIndex, j = colIndex; i < numOfQueens && j >= 0; i++, j--) {
		if (chessTable[i][j] == 1)
			return false;
	}

	return true;
}

void QueensProblem::printQueens() const
{
	//there is a queen where the table contains a 1 else there is no queens (0 value)
	//* represents the queens and - is an empty state
	for (size_t i = 0; i < chessTable.size(); i++) {
		for (size_t j = 0; j < chessTable.size(); j++) {
			if (chessTable[i][j] == 1) {
				cout << " * ";
			}
			else {
				cout << " - ";
			}
		}

		cout << '\n';
	}
}
