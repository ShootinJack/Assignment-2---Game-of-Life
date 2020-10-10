#include "ClassicMode.h"



ClassicMode::ClassicMode()
{

}

ClassicMode::ClassicMode(Grid O) // overloaded constructor importing the base grid
{
	inGrid = O;
	tempGrid = O.getGrid();
	nextGrid = O.getEmptyGrid();
	tempRow = O.getRow();
	tempColumn = O.getColumn();
}

ClassicMode::~ClassicMode()
{
}

void ClassicMode::generateNextGrid() // Generates next grid
{
	for (int i = 0; i < tempRow; ++i) {
		for (int j = 0; j < tempColumn; ++j) {
			int tempNeighborCount = 0;
			tempNeighborCount = getNeighborCount(i, j);
			if (tempNeighborCount < 2) {
				nextGrid[i][j] = '-';
			}
			else if (tempNeighborCount == 2) {
				nextGrid[i][j] = tempGrid[i][j];
			}
			else if (tempNeighborCount == 3) {
				if (tempGrid[i][j] == '-') {
					nextGrid[i][j] = 'X';
				}
				else {
					nextGrid[i][j] = tempGrid[i][j];
				}
			}
			else if (tempNeighborCount > 3) {
				nextGrid[i][j] = '-';
			}
		}
	}
}

int ClassicMode::getNeighborCount(int i, int j) // Sends to check each cell for neightbors
{
	if (i == 0 && j == 0) { 
		return getTopLeftCorner(i, j);
	}
	else if (i == 0 && j == (tempColumn-1)) { 
		return getTopRightCorner(i, j);
	}
	else if (i == (tempRow-1) && j == 0) { 
		return getBottomLeftCorner(i, j);
	}
	else if (i == (tempRow-1) && j == (tempColumn-1)) {
		return getBottomRightCorner(i, j);
	}
	else if (i > 0 && i < (tempRow-1) && j > 0 && j < (tempColumn-1)) {
		return getMiddle(i, j);
	}
	else if (i == 0 && j > 0 && j < (tempColumn-1)) {
		return getTopEdge(i, j);
	}
	else if (i == (tempRow-1) && j > 0 && j < (tempColumn-1)) {
		return getBottomEdge(i, j);
	}
	else if (i > 0 && i < (tempRow-1) && j == 0) {
		return getLeftEdge(i, j);
	}
	else if (i > 0 && i < (tempRow-1) && j == (tempColumn-1)) {
		return getRightEdge(i, j);
	}
}


int ClassicMode::getTopLeftCorner(int i, int j) // Runs Corner Check with classic mode rules
{
	int count = 0;
	if (getRight(i, j) == 'X') {
		count++;
	}
	if (getBottom(i, j) == 'X') {
		count++;
	}
	if (getBottomRight(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getBottomLeftCorner(int i, int j) // Runs Corner Check with classic mode rules
{
	int count = 0;
	if (getTop(i, j) == 'X') {
		count++;
	}
	if (getTopRight(i, j) == 'X') {
		count++;
	}
	if (getRight(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getTopRightCorner(int i, int j) // Runs Corner Check with classic mode rules
{
	int count = 0;
	if (getLeft(i, j) == 'X') {
		count++;
	}
	if (getBottomLeft(i, j) == 'X') {
		count++;
	}
	if (getBottom(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getBottomRightCorner(int i, int j) // Runs Corner Check with classic mode rules
{
	int count = 0;
	if (getLeft(i, j) == 'X') {
		count++;
	}
	if (getTopLeft(i, j) == 'X') {
		count++;
	}
	if (getTop(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getMiddle(int i, int j) // Standard Middle Checks
{
	int count = 0;
	if (getTopLeft(i, j) == 'X') {
		count++;
	}
	if (getTop(i, j) == 'X') {
		count++;
	}
	if (getTopRight(i, j) == 'X') {
		count++;
	}
	if (getRight(i, j) == 'X') {
		count++;
	}
	if (getLeft(i, j) == 'X') {
		count++;
	}
	if (getBottomLeft(i, j) == 'X') {
		count++;
	}
	if (getBottom(i, j) == 'X') {
		count++;
	}
	if (getBottomRight(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getTopEdge(int i, int j) // Runs Edge Check with classic mode rules
{
	int count = 0;
	if (getLeft(i, j) == 'X') {
		count++;
	}
	if (getRight(i, j) == 'X') {
		count++;
	}
	if (getBottomLeft(i, j) == 'X') {
		count++;
	}
	if (getBottom(i, j) == 'X') {
		count++;
	}
	if (getBottomRight(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getLeftEdge(int i, int j) // Runs Edge Check with classic mode rules
{
	int count = 0;
	if (getTop(i, j) == 'X') {
		count++;
	}
	if (getTopRight(i, j) == 'X') {
		count++;
	}
	if (getRight(i, j) == 'X') {
		count++;
	}
	if (getBottomRight(i, j) == 'X') {
		count++;
	}
	if (getBottom(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getBottomEdge(int i, int j) // Runs Edge Check with classic mode rules
{
	int count = 0;
	if (getLeft(i, j) == 'X') {
		count++;
	}
	if (getTopLeft(i, j) == 'X') {
		count++;
	}
	if (getTop(i, j) == 'X') {
		count++;
	}
	if (getTopRight(i, j) == 'X') {
		count++;
	}
	if (getRight(i, j) == 'X') {
		count++;
	}
	return count;
}
int ClassicMode::getRightEdge(int i, int j) // Runs Edge Check with classic mode rules
{
	int count = 0;
	if (getTop(i, j) == 'X') {
		count++;
	}
	if (getTopLeft(i, j) == 'X') {
		count++;
	}
	if (getLeft(i, j) == 'X') {
		count++;
	}
	if (getBottomLeft(i, j) == 'X') {
		count++;
	}
	if (getBottom(i, j) == 'X') {
		count++;
	}
	return count;
}
