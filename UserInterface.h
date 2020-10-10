#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Grid.h"
#include "GameMode.h"
#include "ClassicMode.h"
#include "MirrorMode.h"
#include "DonutMode.h"
using namespace std;

class UserInterface
{
private:
	int selection, row, column, con, count, genCount = 0, rptCount = 0, modeSelect, output;
	double population = .1;
	char **grid;
	string filename, line, outname;
	ifstream infile;
	bool check = true, file = true, selcB = true, manB = true, outputB = true, modeB = true, gameover = false;
public:
	UserInterface();
	~UserInterface();
	void runScript();
	void genDefaultGrid();
	void setFilename();
	void setRandomInfo();
	void runClassicMode(ClassicMode*);
	void runMirrorMode(MirrorMode*);
	void runDonutMode(DonutMode*);
	int getGameMode();
	int getOutputType();
	int getMapInputMethod();
	int getRow();
	int getColumn();
	double getPop();
	char** getGrid();
};

