#include <iostream>
#include <iomanip>
#include <time.h>
#pragma once
using namespace std;

class Grid
{
private:
	int rows, columns;
	double pop;
	char **grid, **emptyGrid, **inGrid;

public:
	Grid();
	Grid(int, int, double, char**);
	~Grid();
	void generateGrid();
	void setUpdatedGrid(char**);
	void deleteGrid();
	void generateEmptyGrid();
	void printGrid();
	void setGridToInGrid();
	char** getGrid();
	char** getEmptyGrid();
	int getRow();
	int getColumn();
};

