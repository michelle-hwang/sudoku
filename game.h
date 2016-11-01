#ifndef GAME_H_
#define GAME_H_

#include "strategies.h"

using namespace std;

// ============================================================================
// CLASSES 
// ============================================================================

class Game {
	Board board;
	bool endgame;
	vector<void (*)()> _strategies;	 // Pointers to strategy functions
public:	
	// Constructor: initializes board based on file input
	Game(int input[]);

	// Solves puzzle board 
	// AKA fills in rest of empty boxes using strategy functions
	void solve();

	// Add strategy functions to vector container
	void addStrategy(void (*function)());
};

// ----------------------------------------------------------------------------

class Board {
	int grid[9][9];
	Box choices[9][9]; // possible nums for each box
	bool solved;
public:	
	Board();
	
	void print();
	
	// Removes a possible num from a box
	void removeChoice(int x, int row, int col);

	// Updates board with new box value
	// Removes possible nums in boxes affected by update
	void update(int x, int row, int col);	
	
	// Checks row for last value
	bool checkRow(int i);

	// Checks col for last value
	bool checkCol(int j);

	// Checks 3x3 for last value
	// Index for 3x3 is upper left box
	bool checkThree(int row, int col);
	
	// Checks for a last value in row, col, and 3x3
	// Updates board and choices to reflect last value
	// Returns false if no last value, true otherwise 
	bool checkLast(int i, int j);
};

// ----------------------------------------------------------------------------

// Holds potential numbers for a box
class Box {
	bool nums[];
	bool full;

public:
	// Constructor: initializes all to 1 (true)
	Box::Box();
	
	// Checks if box only has one possible num left
	bool checkLastChoice();
	
	// Gets the index of last num if checkLastChoice is true
	int getLastChoice();
};


// ============================================================================
// CLASS FUNCTION DEFINITIONS
// ============================================================================

Game::Game(int input[]) {
	endgame = false;
	
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
				while(board.checkLast(i, j) != "none") {
					x = board.getLast(i, j, board.checkLast(i, j));		
					board.update(x, i, j);
				}
			}
			// If box is filled:
			else {
				board.removeChoice(board[i][j], i, j);
			}
		}
	}
}


void Game::solve() {
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

}


void Game::addStrategy(void (*function)()){
	_strategies.push_back(function);
}

// ----------------------------------------------------------------------------

Board::Board() {
	solved = false;
}

void Board::print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}


void Board::removeChoice(int x, int row, int col) {
	choices[row][col].nums[x] = false;
}


void Board::update(int x, int row, int col) {
	grid[row][col] = x;
	
	// Remove value as possible choice in row and col
	for(int n = 0; n < 9; n++) {
		removeChoice(x, row, n);
		removeChoice(x, n, col);
	}
	
	// Remove value as possible choice in 3x3
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			removeChoice(x, row + i, col + j);
		}
	}
}	

bool Board::checkRow(int i) {
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
}

bool Board::checkCol(int j) {
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
}

bool Board::checkThree(int row, int col) {
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
}


bool Board::checkLast(int i, int j) {
	Box element; // Holds possible values of row, col, or 3x3
	int last;
	
	if checkRow(i) is true {
		for(int n = 0; n < 9; n++) {
			if grid[i][n] != 0 {
				element[grid[i][n] - 1] = 1;
			}
		}
	}
	else if checkCol(j) is true {
		for(int n = 0; n < 9; n++) {
			if grid[n][j] != 0 {	
				element[grid[n][j]] = 1;
			}
		}
	}
	else if checkThree(i, j) is true {
		x = 0;
		for(int n = 0; n < 3; n++) {
			for(int m = 0; m < 3; m++) {
				if grid[i + n][j + m] != 0 {
					element[x] = 1;
					x += 1;
				}
			}
		}
	}
	else {
		// No last value found
		return false;
	}
	
	if element.checkLastChoice(): last = element.getLastChoice();
	else: cout << "WARNING: Box::getLastChoice() called when Box::checkLastChoice() returned F\n";

	// Update board
	update(last, i, j);
	
	return true;
}


// ----------------------------------------------------------------------------

Box::Box() {
	nums[] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // All nums = T
	full = false;
}

bool Box::checkLastChoice() {
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
}


int Box::getLastChoice() {
	for (int i = 0; i < 9; i++ ) {
		if (i != true) {
			return i;	
		}
	}
}


#endif /* GAME_H_
