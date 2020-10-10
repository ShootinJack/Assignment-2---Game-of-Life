#include <iostream>
#include <string>
#include <fstream>
#include "UserInterface.h"
#include "Grid.h"
#include "GameMode.h"
#include "ClassicMode.h"
#include "MirrorMode.h"
#include "DonutMode.h"
using namespace std;

int main() {
	int selection, row, column, modeSelect;
	double population = .1;
	char **grid;
	UserInterface *UI = new UserInterface; // Create UI Object for menu prompts.

	selection = UI->getMapInputMethod(); // Call to UI Object to select file input or random generation
	if (selection == 3) {
		system("pause");
		return 0;
	}
	UI->runScript();
	row = UI->getRow();
	column = UI->getColumn();
	population = UI->getPop();
	grid = UI->getGrid();
	
	Grid test(row, column, population, grid); // Create Grid instance
	if (selection == 1) {
		test.setGridToInGrid(); // Set Grid to Infile
	}
	else if (selection == 2) {
		test.generateGrid(); // Generate random grid with user input
	}
	test.generateEmptyGrid(); // Generate empty grid 

	ClassicMode *testMode = new ClassicMode(test); // Create GameMode Instances
	MirrorMode *testMirror = new MirrorMode(test);
	DonutMode *testDonut = new DonutMode(test);

	modeSelect = UI->getGameMode(); // Have user select game mode
	UI->getOutputType();


	switch (modeSelect) { // run game mode based on user input
		case 1:
			UI->runClassicMode(testMode);
			break;
		case 2:
			UI->runMirrorMode(testMirror);
			break;
		case 3:
			UI->runDonutMode(testDonut);
			break;
	}

	delete testMode; 
	delete testMirror;
	delete testDonut;
	delete UI;
	test.deleteGrid(); // delete all dynamically created instances

	system("pause");
	return 0;
}
