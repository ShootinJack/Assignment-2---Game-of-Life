#pragma once
#include "GameMode.h"
class MirrorMode :
	public GameMode
{
private:
	string name = "Mirror Mode";
public:
	MirrorMode();
	MirrorMode(Grid);
	~MirrorMode();
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

