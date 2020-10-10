#include "UserInterface.h"



UserInterface::UserInterface() // Default constructor
{
	genDefaultGrid();
}


UserInterface::~UserInterface()
{
}

void UserInterface::runScript() // Call functions for getting row column and grid information
{
	if (selection == 1) {
		setFilename();
	}
	else if (selection == 2) {
		setRandomInfo();
	}
}

void UserInterface::genDefaultGrid() // generating default array
{
	grid = new char*[5];
	for (int i = 0; i < 5; ++i) {
		grid[i] = new char[5];
	}
}

int UserInterface::getMapInputMethod() // Prompt user to submit map or generate random map or quit
{
	cout << "Welcome to the Game of life!\n1) Submit map\n2) Generate map\n3) Quit\n";
	while (selcB) {
		cin >> selection;
		if (cin.fail()) {
			cout << "Use correct data type.\n";
			cin.clear();
			cin.ignore();
		}
		else if (selection == 1 || selection == 2 || selection == 3) {
			selcB = false;
		}
		else
		{
			cout << "Incorrect Selection. Please select 1, 2, or 3\n";
		}
	}
	return selection;
}

void UserInterface::setFilename() // receive file from user 
{
	do
	{
		cout << "Enter filename: ";
		cin >> filename;
		infile.open(filename);
		if (infile.good() == true) { // Check to make sure the file entered exists. if not prompt for new entry
			file = false;
			count = 0;
			while (infile.good()) { // import the information from the file
				count++;
				if (count == 1) {
					infile >> row;
				}
				else if (count == 2) {
					infile >> column;
				}
				else if (count == 3)
				{
					grid = new char*[row]; // dynamically create the array based on size
					for (int i = 0; i < row; ++i) {
						grid[i] = new char[column];
					}
					for (int i = 0; i < column; ++i) {
						infile >> grid[count - 3][i];
					}
				}
				else if (count > 3 && count <= (row + 2))
				{
					getline(infile, line);
					for (int i = 0; i < column; ++i) {
						infile >> grid[count - 3][i];
					}
				}
				else {
					infile.close(); // close file
				}
			}
		}
		else {
			cout << "Invalid filename\n";
		}
	} while (file == true);
}

void UserInterface::setRandomInfo() // prompt user for Row, Column, Population Percentage
{
	do
	{
		cout << "Enter a how many rows you want. Min is 5\nEntry: ";
		cin >> row;
		if (cin.fail()) {
			cout << "Use correct data type.\n";
			cin.clear();
			cin.ignore();
			row = 0;
		}
		else if (row < 5) {
			cout << "Enter a number greater than 5\n";
		}
	} while (row < 5);
	do
	{
		cout << "Enter a how many columns you want. Min is 5\nEntry: ";
		cin >> column;
		if (cin.fail()) {
			cout << "Use correct data type.\n";
			cin.clear();
			cin.ignore();
			column = 0;
		}
		else if (column < 5) {
			cout << "Enter a number greater than 5\n";
		}
	} while (column < 5);
	do
	{
		cout << "Please enter a population percentage as a decimal: ";
		cin >> population;
		if (cin.fail()) {
			cout << "Use correct data type.\n";
			cin.clear();
			cin.ignore();
			population = 5;
		}
		if (population <= 0 || population >= 1) {
			cout << "Please enter a decimal between 0 and 1\n";
		}
	} while (population <= 0 || population >= 1);

}

int UserInterface::getGameMode() //Prompt user for Game mode they wish to play
{
	while (modeB)
	{
		cout << "Game Mode\n1) Classic Mode\n2) Mirror Mode\n3) Donut Mode\n";
		cout << "Select Game Mode: ";
		cin >> modeSelect;
		if (cin.fail()) {
			cout << "Use correct data type.\n";
			cin.clear();
			cin.ignore();
		}
		else if (modeSelect > 3 || modeSelect < 1) {
			cout << "Invalid Entry\n";
		}
		else {
			modeB = false;
		}
	}
	return modeSelect;
}

int UserInterface::getOutputType() // Prompt user for console output or output to a file
{
	while (outputB) {
		cout << "Select output type\n1) Manual\n2) Output to file\nSelection: ";
		cin >> output;
		if (cin.fail()) {
			cout << "Use correct data type.\n";
			cin.clear();
			cin.ignore();
		}
		else if (output > 2 || output < 1) {
			cout << "Invalid Entry\n";
		}
		else if (output == 2) {
			cout << "Enter outfile name: ";
			cin >> outname;
			outputB = false;
		}
		else {
			outputB = false;
		}

	}
	return output;
}

void UserInterface::runClassicMode(ClassicMode *inMode) // run classic mode
{
	cout << "Called Classic\n";
	if (output == 1) {
		cout << "Generation: " << genCount << endl;
		inMode->printGrid();
		++genCount;
		do
		{
			cout << "Generation: " << genCount << endl;
			inMode->generateNextGrid();
			if (inMode->checkRepeat() == true) {
				++rptCount;
				cout << "Repeat Count: " << rptCount << endl;
				if (rptCount == 4) {
					cout << "Stagnant Sim Game Over\n";
					gameover = true;
				}
				if (inMode->checkEmpty() == true) {
					rptCount = 4;
					cout << "Everybody is dead\n";
					gameover = true;
				}
				if (genCount == 1000) {
					cout << "The Generations Have Stablized.\nGame over\n";
					gameover = true;
				}
			}
			inMode->setNextGeneration();
			inMode->printGrid();
			if (gameover == true) {
				con = 2;
			}
			else {
				cout << "\n1)NextGen\n2)Quit\nInput: ";
				++genCount;
				while (manB) {
					cin >> con;
					if (cin.fail()) {
						cout << "Use correct data type.\n";
						cin.clear();
						cin.ignore();
					}
					else if (con < 1 || con > 2) {						
						cout << "Enter either 1 or 2\n";
					}
					else {
						manB = false;
					}
				}
				manB = true;
			}


		} while (con != 2);
	}
	else {
		cout << "Generation: " << genCount << endl;
		inMode->outputGrid(outname, genCount);
		++genCount;
		do
		{
			cout << "Generation: " << genCount << endl;
			inMode->generateNextGrid();
			if (inMode->checkRepeat() == true) {
				++rptCount;
				cout << "Repeat Count: " << rptCount << endl;
				if (rptCount == 4) {
					cout << "Stagnant Sim Game Over\n";
				}
				if (inMode->checkEmpty() == true) {
					rptCount = 4;
					cout << "Everybody is dead\n";
				}
				if (genCount == 1000) {
					cout << "The Generations Have Stablized.\nGame over\n";
					rptCount = 4;
				}
			}
			inMode->setNextGeneration();
			inMode->outputGrid(outname, genCount);
			++genCount;
		} while (rptCount != 4);
	}
}

void UserInterface::runMirrorMode(MirrorMode *inMode) // Run mirror Mode
{
	cout << "Mirror Mode\n";
	if (output == 1) {
		cout << "Generation: " << genCount << endl;
		++genCount;
		inMode->printGrid();
		do
		{
			cout << "Generation: " << genCount << endl;
			inMode->generateNextGrid();
			if (inMode->checkRepeat() == true) {
				++rptCount;
				cout << "Repeat Count: " << rptCount << endl;
				if (rptCount == 4) {
					cout << "Stagnant Sim Game Over\n";
					gameover = true;
				}
				if (inMode->checkEmpty() == true) {
					rptCount = 4;
					cout << "Everybody is dead\n";
					gameover = true;
				}
				if (genCount == 1000) {
					cout << "The Generations Have Stablized.\nGame over\n";
					gameover = true;
				}
			}
			inMode->setNextGeneration();
			inMode->printGrid();

			if (gameover == true) {
				con = 2;
			}
			else {
				cout << "\n1)NextGen\n2)Quit\nInput: ";
				++genCount;
				while (manB) {
					cin >> con;
					if (cin.fail()) {
						cout << "Use correct data type.\n";
						cin.clear();
						cin.ignore();
					}
					else if (con < 1 || con > 2) {			
						cout << "Enter either 1 or 2\n";
					}
					else {
						manB = false;
					}
				}
				manB = true;
			}
		} while (con != 2);
	}
	else {
		cout << "Generation: " << genCount << endl;
		inMode->outputGrid(outname, genCount);
		++genCount;
		do
		{
			cout << "Generation: " << genCount << endl;
			inMode->generateNextGrid();
			if (inMode->checkRepeat() == true) {
				++rptCount;
				cout << "Repeat Count: " << rptCount << endl;
				if (rptCount == 4) {
					cout << "Stagnant Sim Game Over\n";
				}
				if (inMode->checkEmpty() == true) {
					rptCount = 4;
					cout << "Everybody is dead\n";
				}
				if (genCount == 1000) {
					cout << "The Generations Have Stablized.\nGame over\n";
					rptCount = 4;
				}
			}
			inMode->setNextGeneration();
			inMode->outputGrid(outname, genCount);
			++genCount;
		} while (rptCount != 4);
	}
}

void UserInterface::runDonutMode(DonutMode *inMode) // Run Donut Mode
{
	cout << "Donut Mode\n";
	if (output == 1) {
		cout << "Generation: " << genCount << endl;
		inMode->printGrid();
		do
		{
			cout << "Generation: " << genCount << endl;
			inMode->generateNextGrid();
			if (inMode->checkRepeat() == true) {
				++rptCount;
				cout << "Repeat Count: " << rptCount << endl;
				if (rptCount == 4) {
					cout << "Stagnant Sim Game Over\n";
					gameover = true;
				}
				if (inMode->checkEmpty() == true) {
					rptCount = 4;
					cout << "Everybody is dead\n";
					gameover = true;
				}
				if (genCount == 1000) {
					cout << "The Generations Have Stablized.\nGame over\n";
					gameover = true;
				}
			}
			inMode->setNextGeneration();
			inMode->printGrid();

			if (gameover == true) {
				con = 2;
			}
			else {
				cout << "\n1)NextGen\n2)Quit\nInput: ";
				++genCount;
				while (manB) {
					cin >> con;
					if (cin.fail()) {
						cout << "Use correct data type.\n";
						cin.clear();
						cin.ignore();
					}
					else if (con < 1 || con > 2) {	
						cout << "Enter either 1 or 2\n";
					}
					else {
						manB = false;
					}
				}
				manB = true;
			}
		} while (con != 2);
	}
	else {
		cout << "Generation: " << genCount << endl;
		inMode->outputGrid(outname, genCount);
		++genCount;
		do
		{
			cout << "Generation: " << genCount << endl;
			inMode->generateNextGrid();
			if (inMode->checkRepeat() == true) {
				++rptCount;
				cout << "Repeat Count: " << rptCount << endl;
				if (rptCount == 4) {
					cout << "Stagnant Sim Game Over\n";
				}
				if (inMode->checkEmpty() == true) {
					rptCount = 4;
					cout << "Everybody is dead\n";
				}
				if (genCount == 1000) {
					cout << "The Generations Have Stablized.\nGame over\n";
					rptCount = 4;
				}
			}
			inMode->setNextGeneration();
			inMode->outputGrid(outname, genCount);
			++genCount;
		} while (rptCount != 4);
	}
}

int UserInterface::getRow() // Return Row value
{
	return row;
}

int UserInterface::getColumn() // Return column value
{
	return column;
}

double UserInterface::getPop() // Return population value
{
	return population;
}

char** UserInterface::getGrid() // return grid value
{
	return grid;
}
