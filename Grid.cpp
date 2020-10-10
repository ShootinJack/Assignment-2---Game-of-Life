#include "Grid.h"



Grid::Grid() //default constructor 
{

}

Grid::Grid(int r, int c, double p, char** in) // Constructor Dyanamically creates the size of the grid.
{
	rows = r;
	columns = c;
	pop = p;
	inGrid = in;
	grid = new char*[rows];
	for (int i = 0; i < rows; ++i) {
		grid[i] = new char[columns];
	}

	emptyGrid = new char*[rows];
	for (int i = 0; i < rows; ++i) {
		emptyGrid[i] = new char[columns];
	}
}


Grid::~Grid() // destructor 
{

}

void Grid::deleteGrid() // deleting dynamically created array
{
	for (int i = 0; i < rows; ++i) {
		delete[] grid[i];
	}
	delete[] grid;

	for (int i = 0; i < rows; ++i) {
		delete[] emptyGrid[i];
	}
	delete[] emptyGrid;
}

void Grid::generateGrid() { // generate grid with population and inputted rows and columns
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			double random = double(rand()) / RAND_MAX;
			if (random <= pop) {
				grid[i][j] = 'X';
			}
			else {
				grid[i][j] = '-';
			}
			
		}
	}
}

void Grid::generateEmptyGrid() // Generate Empty grid of the same size
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			emptyGrid[i][j] = '-';
		}
	}
}

void Grid::setGridToInGrid() // sets grid to the grid imported from the file
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			grid[i][j] = inGrid[i][j];
		}
	}
}

void Grid::setUpdatedGrid(char** inGrid) { // sets the grid to the next generation
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			grid[i][j] = inGrid[i][j];
		}
	}
}

void Grid::printGrid()  // print grid to the screen for user
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << setw(5) << grid[i][j];
		}
		cout << endl;
	}
}

char** Grid::getGrid() // return grid
{
	return grid;
}

char** Grid::getEmptyGrid() // return empty grid
{
	return emptyGrid;
}

int Grid::getRow() // return rows
{
	return rows;
}

int Grid::getColumn() // return column
{
	return columns;
}
