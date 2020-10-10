#pragma once
#include "GameMode.h"
class DonutMode :
	public GameMode
{
private:
	string name = "Donut Mode";
public:
	DonutMode();
	DonutMode(Grid);
	~DonutMode();
	void generateNextGrid();
	int getNeighborCount(int, int);
	int getTopLeftCorner(int, int);
	int getBottomLeftCorner(int, int);
	int getTopRightCorner(int, int);
	int getBottomRightCorner(int, int);
	int getMiddle(int, int);
	int getTopEdge(int, int);
	int getLeftEdge(int, int);
	int getBottomEdge(int, int);
	int getRightEdge(int, int);
};

