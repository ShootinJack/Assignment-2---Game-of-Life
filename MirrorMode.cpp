#include "MirrorMode.h"



MirrorMode::MirrorMode()
{
}

MirrorMode::MirrorMode(Grid O) {
	inGrid = O;
	tempGrid = O.getGrid();
	nextGrid = O.getEmptyGrid();
	tempRow = O.getRow();
	tempColumn = O.getColumn();
}

void MirrorMode::generateNextGrid() //Generates next Grid with mirror rules
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

int MirrorMode::getNeighborCount(int i, int j) //Sends to check each cell
{
	if (i == 0 && j == 0) { 
		return getTopLeftCorner(i, j);
	}
	else if (i == 0 && j == (tempColumn - 1)) { 
		return getTopRightCorner(i, j);
	}
	else if (i == (tempRow - 1) && j == 0) { 
		return getBottomLeftCorner(i, j);
	}
	else if (i == (tempRow - 1) && j == (tempColumn - 1)) {
		return getBottomRightCorner(i, j);
	}
	else if (i > 0 && i < (tempRow - 1) && j > 0 && j < (tempColumn - 1)) {
		return getMiddle(i, j);
	}
	else if (i == 0 && j > 0 && j < (tempColumn - 1)) {
		return getTopEdge(i, j);
	}
	else if (i == (tempRow - 1) && j > 0 && j < (tempColumn - 1)) {
		return getBottomEdge(i, j);
	}
	else if (i > 0 && i < (tempRow - 1) && j == 0) {
		return getLeftEdge(i, j);
	}
	else if (i > 0 && i < (tempRow - 1) && j == (tempColumn - 1)) {
		return getRightEdge(i, j);
	}
}


int MirrorMode::getTopLeftCorner(int i, int j) // Runs Corner Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count = count + 3;
	}
	if (getRight(i, j) == 'X') {
		count = count + 2;
	}
	if (getBottom(i, j) == 'X') {
		count = count +2;
	}
	if (getBottomRight(i, j) == 'X') {
		count++;
	}
	return count;
}
int MirrorMode::getBottomLeftCorner(int i, int j) // Runs Corner Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count = count + 3;
	}
	if (getTop(i, j) == 'X') {
		count = count + 2;
	}
	if (getTopRight(i, j) == 'X') {
		count++;
	}
	if (getRight(i, j) == 'X') {
		count = count + 2;
	}
	return count;
}
int MirrorMode::getTopRightCorner(int i, int j) // Runs Corner Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count = count + 3;
	}
	if (getLeft(i, j) == 'X') {
		count = count + 2;
	}
	if (getBottomLeft(i, j) == 'X') {
		count++;
	}
	if (getBottom(i, j) == 'X') {
		count = count + 2;
	}
	return count;
}
int MirrorMode::getBottomRightCorner(int i, int j) // Runs Corner Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count = count + 3;
	}
	if (getLeft(i, j) == 'X') {
		count = count + 2;
	}
	if (getTopLeft(i, j) == 'X') {
		count++;
	}
	if (getTop(i, j) == 'X') {
		count = count + 2;
	}
	return count;
}
int MirrorMode::getMiddle(int i, int j) // Standard Middle Rules
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
int MirrorMode::getTopEdge(int i, int j) // Runs Edge Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count++;
	}
	if (getLeft(i, j) == 'X') {
		count = count + 2;
	}
	if (getRight(i, j) == 'X') {
		count = count + 2;
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
int MirrorMode::getLeftEdge(int i, int j) // Runs Edge Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count++;
	}
	if (getTop(i, j) == 'X') {
		count = count + 2;
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
		count = count + 2;
	}
	return count;
}
int MirrorMode::getBottomEdge(int i, int j) // Runs Edge Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count++;
	}
	if (getLeft(i, j) == 'X') {
		count = count + 2;
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
		count = count + 2;
	}
	return count;
}
int MirrorMode::getRightEdge(int i, int j) // Runs Edge Check with mirror mode rules
{
	int count = 0;
	if (getSelf(i, j) == 'X') {
		count = count++;
	}
	if (getTop(i, j) == 'X') {
		count = count + 2;
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
		count = count + 2;
	}
	return count;
}

MirrorMode::~MirrorMode()
{
}


