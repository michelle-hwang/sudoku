#ifndef GAME_H_
#define GAME_H_

#include "strategies.h"

using namespace std;

class Game {
	Board board;
	bool endgame = false;

	// Vector of pointers to strategy functions in "strategies.h":
	vector<void (*)()> _strategies;	
	
	// Solves puzzle board; fills in rest of empty boxes using strategy functions
	void solve() {
		while (!board.solved) {
			bool solution = false;
			while (!solution) {
				// unsolvable if all strategies false
				// have to do checkLastValue 
				for (iter = _strategies.begin(), end = _strategies.end(); iter != end; ++iter) {
					(*iter)->function();
				}
						
			}
			board.update();
		}

	};
	
	// Initializes board based on file input
	void setup(int input[]) {
		// Fill in board based on input
		for (int i = 0; i < 9; i++) {
			for (int j = 0, j < 9, j++) {
				board[i][j] = input[i][j];
			}
		}

		// Update possible choices of each box 
		for (int i = 0; i < 0; i++) {
			for (int j = 0; j < 0; j ++) {
				// If box is empty:
				if board[i][j] == 0 {
					// Check row
					
					// Check col
					// Check 3x3 grid
				}
				// If box is filled:
				else {
					board.removeChoice(board[i][j], i, j);
				}
			}
		}
	};
	
	// Initializes board with random templates
	void setupRand(int input[]) {

	};

	// Add strategy functions to vector container
	void addStrategy(void (*function)()){
		_strategies.push_back(function);
	};
};



class Board {
	int grid[] = {9, 9};
	Box choices[] = {9, 9}; // possible nums for each box
	bool solved = false;
	
	void print() {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
	};
	
	// Removes a possible num from a box
	void removeChoice(int x, int row, int col) {
		choices[row][col].nums[x] = false;
	};

	// Updates board with new box value
	void update(int x, int row, int col) {
		grid[row][col] = x;
	};	
	
	// Checks row for last value
	bool checkRow(int i) {
		int filledBoxes = 0;
		for (int j = 0; j < 9; j++) {
			if grid[i][j] != 0 {
				filledBoxes += 1;
			}
		}
		if filledBoxes == 8 {
			return true;
		}
		return false;
	};

	// Checks col for last value
	bool checkCol(int j) {
		int filledBoxes = 0;
		for (int i = 0; i < 9; i++) {
			if grid[i][j] != 0 {
				filledBoxes += 1;
			}
		}
		if filledBoxes == 8 {
			return true;
		}
		return false;
	
	};

	// Checks 3x3 for last value
	// Index for 3x3 is upper left box
	bool checkThree(int row, int col) {
		int filledBoxes = 0;
		for (int i = row; i < row + 3; i++) {
			for (int j = col; j < col + 3; j++) {
				if grid[i][j] != 0 {
					filledBoxes += 1;
				}
			}
		}
		if filledBoxes == 8 {
			return true;
		}
		return false;
	};
	
	// Get last value, values must be sorted
	// Only executed if there is a last value
	int getLast(int values[]) {
		for (int i = 0; i < 9; i++) {
			if i != values[i] {
				return(i+2);
			}
		}
	};
};


// Holds potential numbers for a box
class Box {
	bool nums[] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // All nums = T
	
	// Checks if any row, column, or 3x3 grid has 1 num left
	bool checkLastChoice() {
		int choices = 0;
		for (int i = 0; i < 9; i++) {
			if !(choices == false) {
				choices ++ 1;
			}
		}

		if (choices == 8) {
			return true;
		}
		return false;
	};
	
	// Gets the last num if checkLastChoice is true
	int getLastChoice() {
		for (int i = 0; i < 9; i++ ) {
			if (i != true) {
				return i;	
			}
		}
	};
};


#endif /* GAME_H_
