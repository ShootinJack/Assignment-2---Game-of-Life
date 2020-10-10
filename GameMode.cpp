#include "GameMode.h"



GameMode::GameMode() //default constructor
{
}

GameMode::~GameMode()
{

}

void GameMode::setNextGeneration() // Sets next generation
{
	for (int i = 0; i < tempRow; ++i) {
		for (int j = 0; j < tempColumn; ++j) {
			tempGrid[i][j] = nextGrid[i][j];
			nextGrid[i][j] = '-';
		}
	}
	inGrid.setUpdatedGrid(tempGrid);
}

void GameMode::printGrid() // prints grid to user terminal
{
	inGrid.printGrid();
}

void GameMode::deleteGrid() { // deletes grids
	for (int i = 0; i < tempRow; ++i) {
		delete[] tempGrid[i];
	}
	delete[] tempGrid;

	for (int i = 0; i < tempRow; ++i) {
		delete[] nextGrid[i];
	}
	delete[] nextGrid;
}

void GameMode::outputGrid(string name, int count) // outputs grid to file
{
	outfile.open(name, ios_base::app);
	outfile << "Generation: " << count << endl;
	for (int i = 0; i < tempRow; ++i) {
		for (int j = 0; j < tempColumn; ++j) {
			outfile << setw(5) << tempGrid[i][j];
		}
		outfile << endl;
	}
	outfile.close();
}

bool GameMode::checkEmpty() // checks for empty grid
{
	for (int i = 0; i < tempRow; ++i) {
		for (int j = 0; j < tempColumn; ++j) {
			if (tempGrid[i][j] == 'X') {
				return false;
			}
		}
	}
	return true;
}

bool GameMode::checkRepeat() // checks for repeat grids
{
	for (int i = 0; i < tempRow; ++i) {
		for (int j = 0; j < tempColumn; ++j) {
			if (tempGrid[i][j] != nextGrid[i][j]) {
				return false;
			}
		}
	}
	return true;
}

string GameMode::getName() // returns name of gamemode
{
	return name;
}

char GameMode::getTopLeft(int i, int j) // checks for top left neighbor inherited by all modes
{
	return tempGrid[i-1][j-1];
}
char GameMode::getTop(int i, int j) // checks for top neighbor inherited by all modes
{
	return tempGrid[i-1][j];
}
char GameMode::getTopRight(int i, int j) // checks for top right neighbor inherited by all modes
{
	return tempGrid[i-1][j+1];
}
char GameMode::getLeft(int i, int j) // checks for left neighbor inherited by all modes
{
	return tempGrid[i][j-1];
}
char GameMode::getRight(int i, int j) // checks for right neighbor inherited by all modes
{
	return tempGrid[i][j+1];
}
char GameMode::getBottomLeft(int i, int j) // checks for bottom left neighbor inherited by all modes
{
	return tempGrid[i+1][j-1];
}
char GameMode::getBottom(int i, int j) // checks for bottom neighbor inherited by all modes
{
	return tempGrid[i+1][j];
}
char GameMode::getBottomRight(int i, int j) // checks for bottom right neighbor inherited by all modes
{
	return tempGrid[i+1][j+1];
}
char GameMode::getSelf(int i, int j) // returns character in self inherited by all modes
{
	return tempGrid[i][j];
}
