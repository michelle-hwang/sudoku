#ifndef STRATEGIES_H_
#define STRATEGIES_H_

using namespace std;

// Strategies derived from www.sudokuwiki.org

struct newValue {
	bool solution = false;
	int row = 0;
	int col = 0;
	int val = 0;
}


// ============================================================================
// BASIC STRATEGIES
// ============================================================================

// Checks rows, cols, 3x3s for naked pairs
// Eliminates choices in relevant boxes
void nakedPairs(int board[]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			Box *b = board.choices[i][j];
			if ((&b)->full == false &&
			    count(b->nums.begin(), b->nums.end(), 0) == 2) {
				// If there's 2 values left in box
			}
		}
	}

	// Find matching pairs
	


}

// ============================================================================
// STRATEGIES
// ============================================================================




#endif /* STRATEGIES_H_ */
