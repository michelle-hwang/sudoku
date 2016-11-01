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

	// Vector of pointers to strategy functions in "strategies.h":
	vector<void (*)()> _strategies;	
public:	
	// Constructor
	// Initializes board based on file input
	Game(int input[]);

	// Solves puzzle board; fills in rest of empty boxes using strategy functions
	void solve();
	
	// Initializes board with random templates
	void setupRand(int input[]);

	// Add strategy functions to vector container
	void addStrategy(void (*function)());
};


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
	void update(int x, int row, int col);	
	
	// Checks row for last value
	bool checkRow(int i);

	// Checks col for last value
	bool checkCol(int j);

	// Checks 3x3 for last value
	// Index for 3x3 is upper left box
	bool checkThree(int row, int col);
	
	string checkLast(int i, int j);

	// Get last value, values must be sorted
	// Only executed if there is a last value
	int getLast(int i, int j, string type);
};



// Holds potential numbers for a box
class Box {
	bool nums[] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // All nums = T

public:
	// Checks if box only has one possible num left
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
	// Update all boxes on board; remove possible values
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


string Board::checkLast(int i, int j) {
	if checkRow(i) is true {
		return "row";
	}
	else if checkCol(j) is true {
		return "col";
	}
	else if checkThree(i, j) is true {
		return "three";
	}
	return "none";
}


int Board::getLast(int i, int j, string type) {


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
