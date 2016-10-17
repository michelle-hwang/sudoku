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

// Store pointers to strategy functions
vector<void (*)()> _basics;
vector<void (*)()> _strategies;


// ============================================================================
// BASIC STRATEGIES
// ============================================================================

// If any row, column, or box only needs one last number, return index
newValue lastCell(int board[]) {
	
}

newValue nakedPairs(int board[]) {
}

// ============================================================================
// STRATEGIES
// ============================================================================




#endif /* STRATEGIES_H_ */
