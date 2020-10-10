#pragma once
#include "GameMode.h"
class ClassicMode :
	public GameMode
{
private:
	string name = "Classic Mode";
public:
	ClassicMode();
	ClassicMode(Grid);
	~ClassicMode();
	void generateNextGrid();
	int getNeighborCount(int,int);
	int getTopLeftCorner(int,int);
	int getBottomLeftCorner(int, int);
	int getTopRightCorner(int, int);
	int getBottomRightCorner(int, int);
	int getMiddle(int, int);
	int getTopEdge(int, int);
	int getLeftEdge(int, int);
	int getBottomEdge(int, int);
	int getRightEdge(int, int);
};

