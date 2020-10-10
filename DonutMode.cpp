#include "DonutMode.h"



DonutMode::DonutMode()
{
}

DonutMode::DonutMode(Grid O) // overloaded constructor importing the base grid
{
	inGrid = O;
	tempGrid = O.getGrid();
	nextGrid = O.getEmptyGrid();
	tempRow = O.getRow();
	tempColumn = O.getColumn();
}

void DonutMode::generateNextGrid() // Function called to generate the next grid, checks each cell and determines the next grid cell occupants
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

int DonutMode::getNeighborCount(int i, int j) // gets how many neighbors a cell has for donut mode based on cell location
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


int DonutMode::getTopLeftCorner(int i, int j) // Runs Donut Corner Scenario
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
	if (getSelf(i, (tempColumn-1)) == 'X') {
		count++;
	}
	if (getSelf((i + 1), (tempColumn-1)) == 'X') {
		count++;
	}
	if (getSelf((tempRow-1), (tempColumn-1)) == 'X') {
		count++;
	}
	if (getSelf((tempRow-1), j) == 'X') {
		count++;
	}
	if (getSelf((tempRow - 1), (j+1)) == 'X') {
		count++;
	}
	return count;
}
int DonutMode::getBottomLeftCorner(int i, int j) // Runs Donut Corner Scenario
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
	if (getSelf(0, 0) == 'X') {
		count++;
	}
	if (getSelf(0, 1) == 'X'){
		count++;
	}
	if (getSelf(0, (tempColumn-1)) == 'X') {
		count++;
	}
	if (getSelf((tempRow-1), (tempColumn-1)) == 'X') {
		count++;
	}
	if (getSelf((tempRow-2), (tempColumn-1)) == 'X') {
		count++;
	}
	return count;
}
int DonutMode::getTopRightCorner(int i, int j) // Runs Donut Corner Scenario
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
	if (getSelf(0, 0) == 'X') {
		count++;
	}
	if (getSelf(1, 0) == 'X') {
		count++;
	}
	if (getSelf((tempRow-1), 0) == 'X') {
		count++;
	}
	if (getSelf((tempRow - 1), (tempColumn - 1)) == 'X') {
		count++;
	}
	if (getSelf((tempRow - 1), (tempColumn - 2)) == 'X') {
		count++;
	}
	return count;
}
int DonutMode::getBottomRightCorner(int i, int j) // Runs Donut Corner Scenario
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
	if (getSelf((tempRow - 1), 0) == 'X') {
		count++;
	}
	if (getSelf((tempRow - 2), 0) == 'X') {
		count++;
	}
	if (getSelf(0, 0) == 'X') {
		count++;
	}
	if (getSelf(0, (tempColumn - 1)) == 'X') {
		count++;
	}
	if (getSelf(0, (tempColumn - 2)) == 'X') {
		count++;
	}

	return count;
}
int DonutMode::getMiddle(int i, int j) // Standard check for middle area
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
int DonutMode::getTopEdge(int i, int j) // Runs Neightbor Check on Edge for donut scenario
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
	if (getLeft((tempRow-1), j) == 'X') {
		count++;
	}
	if (getSelf((tempRow - 1), j) == 'X') {
		count++;
	}
	if (getRight((tempRow - 1), j) == 'X') {
		count++;
	}
	return count;
}
int DonutMode::getLeftEdge(int i, int j) // Runs Neightbor Check on Edge for donut scenario
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
	if (getTop(i, (tempColumn-1)) == 'X') {
		count++;
	}
	if (getSelf(i, (tempColumn-1)) == 'X') {
		count++;
	}
	if (getBottom(i, (tempColumn-1)) == 'X') {
		count++;
	}
	return count;
}
int DonutMode::getBottomEdge(int i, int j) // Runs Neightbor Check on Edge for donut scenario
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
	if (getLeft(0, j) == 'X') {
		count++;
	}
	if (getSelf(0, j) == 'X') {
		count++;
	}
	if (getRight(0, j) == 'X') {
		count++;
	}
	return count;
}
int DonutMode::getRightEdge(int i, int j) // Runs Neightbor Check on Edge for donut scenario
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
	if (getTop(i, 0) == 'X') {
		count++;
	}
	if (getSelf(i, 0) == 'X') {
		count++;
	}
	if (getBottom(i, 0) == 'X') {
		count++;
	}
	return count;
}

DonutMode::~DonutMode()
{
}
