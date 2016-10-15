// sudoku solver

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "strategies.h"
#include "game.h"

using namespace std;

// ============================================================================
// FUNCTIONS
// ============================================================================

int stringSplit (const string &s, char delim);
int stringSplit (const string &s, char delim) {
	int row[];
	stringstream ss;
	ss.str(s);
	string item;
	

	// find way to deal with invalid elements

	for (int i = 0; i < 9; i++) {
		getline(ss, item, delim)
		row[i] = stoi(item);
	}

	return row;

// ============================================================================
// MAIN
// ============================================================================


int main(int argc, char* argv[]) {

	Game g;
	
	// INITIALIZE THE BOARD
	// If .txt file containing board is not provided:
	if (argv[1] == nullptr) {
		g.setupRand();
	}
	// If .txt file containing board is provided:
	else {
		ifstream myfile;
		myfile.exceptions (ifstream::failbit | ifstream::badbit);

		try {
			myfile.open(argv[1]);
			while (!file.eof()) file.get();
		}
		catch (const ifstream::failure&e) {
			cout << "EXCEPTION: Opening/reading file.";
		}

		int inputBoard[] = {9, 9}
		int rowCounter = 0;
		while (getline(myfile, s)) {
			char delim = ',' 
			int row = stringSplit(s, delim);
			
			for (int i = 0; i < 9; i++ ) {
				inputBoard[rowCounter][i] = row[i];
			}
			
			rowCounter++;
		}

		// Stop if board contains invalid integer

		// Stop if board is completely empty or full
		
		g.setup(inputBoard);
	}
	

	// SOLVE GAME
	g.solve();

	// END GAME



	myfile.close();
	return 0;

}




