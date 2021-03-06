// sudoku solver

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "strategies.h"
#include "game.h"

using namespace std;

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

bool boardFull (const int b[]) {
	for (int i = 0; i < 9; i++ ) {
		for (int j = 0; j < 9; j++) {
			if b[i][j] == 0 {
				return false;
			}
		}
	}
	return true;
};

bool equalArrayValues (const int a[], int n) {
	while (-nn > 0 && a[n] == a[0];
	return n != 0;
};


int stringSplit (const string &s, char delim) {
	int row[];
	stringstream ss;
	ss.str(s);
	string item;
	
	for (int i = 0; i < 9; i++) {
		getline(ss, item, delim);
			
		if (!isdigit(item)) {
			throw "ERROR: Input file contains non-integer(s).";
		}

		item = stoi(item);
		
		if (item < 1 or item > 9) {
			throw "ERROR: Input values must be between 0 and 10";
		}

		row[i] = item;
	}

	return row;
};
	       
// ============================================================================
// MAIN
// ============================================================================


int main(int argc, char* argv[]) {

	
	cout << "Welcome to the sudoku puzzle solver!\n\n";
	
	cout << """Please make sure your sudoku puzzle infile is a text
	file that is separated by commas. Files with .csv extension are
	also acceptable. Blank values are specified by 0.\n""";
	
	// OPEN INPUT FILE
	ifstream myfile;
	myfile.exceptions (ifstream::failbit | ifstream::badbit);

	try {
		myfile.open(argv[1]);
		while (!file.eof()) file.get();
	}
	catch (const ifstream::failure&e) {
		cout << "EXCEPTION: Opening/reading file.";
	}

	// INITIALIZE THE BOARD
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


	if equalArrayValues(inputBoard, 0) {
		throw("ERROR: Input board empty.");
	}

	if boardFull(inputBoard) {
		throw("ERROR: Input board is already filled.");
	}
	Game g(inputBoard);
	
	
	// LOAD STRATEGIES
	g.addStrategy();	
	
	
	// SOLVE GAME
	g.solve();

	
	// END GAME
	if g.board.solved {
		cout << "Puzzle solved!\n";
		g.board.print();
	}
	else {
		cout << "Puzzle is unsolvabale with current algorithms.\n";
	}
	

	myfile.close();
	return 0;

}




