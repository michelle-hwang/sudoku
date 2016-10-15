#ifndef GAME_H_
#define GAME_H_

#include "strategies.h"

using namespace std;

class Game {
	Board board;
	bool endgame = false;
	
	// fills in entire board
	void solve() {
		// LOTS OF WORK HERE
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
	void setupRand(int input[]) {
	}
};




class Board {
	int grid[] = {9, 9};
	bool solved = false;
	
	// initializes board
	void initialize(int grid[]) {
	}
	
	// prints board to stdout
	void print(int grid[]) {
	}

	// updates board with new value
	void update(int grid[], int x, int row, int col) {
	}	
};





#endif /* GAME_H_ */
