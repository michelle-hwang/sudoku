#ifndef GAME_H_
#define GAME_H_

#include "strategies.h"

using namespace std;

class Game {
	Board board;
	bool endgame = false;
	
	void solve() {
		while (!board.solved) {
			bool solution = false;
			while (!solution) {
				// unsolvable if all strategies false
				// have to do checkLastValue 
				for (int i = 0; i <
						
			}
			board.update()
		}

	}
	
	// initializes board based on file input
	void setup(int input[]) {
		for (int i = 0, i < 9, i++) {
			for (int j = 0, j < 9, j++) {
				board[i][j] = input[i][j];
			}
		}
	}
	
	// initializes board with random templates
	// low priority
	void setupRand(int input[]) {
	}
};



// Current values in board
class Board {
	int grid[] = {9, 9};
	Box choices[] = {9, 9} // possible nums for each box
	bool solved = false;
	
	// prints board to stdout
	void print() {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
	}

	void removeChoice(int x, int row, int col) {
		choices[row][col].nums[x] = false;
	}

	// updates board with new value
	void update(int x, int row, int col) {
		grid[row][col] = x;
	}	
};


// Possible values for a box in grid
class Box {
	bool nums[] = {9};

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
	}

	int getLastChoice() {
		for (int i = 0; i < 9; i++ ) {
			if (i != true) {
				return i;	
			}
		}
	}
}


#endif /* GAME_H_
