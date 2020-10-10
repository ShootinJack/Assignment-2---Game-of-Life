#pragma once
#include "Grid.h"
#include <fstream>

class GameMode
{
protected:
	Grid inGrid;
	ofstream outfile;
	int tempRow, tempColumn;
	char **tempGrid, **nextGrid;
	string name = "Default";
public:
	GameMode();
	~GameMode();
	void setNextGeneration();
	virtual string getName();
	bool checkEmpty();
	bool checkRepeat();
	void printGrid();
	void deleteGrid();
	void outputGrid(string, int);
	char getTopLeft(int, int);
	char getTop(int, int);
	char getTopRight(int, int);
	char getLeft(int, int);
	char getRight(int, int);
	char getBottomLeft(int, int);
	char getBottom(int, int);
	char getBottomRight(int, int);
	char getSelf(int, int);
};

