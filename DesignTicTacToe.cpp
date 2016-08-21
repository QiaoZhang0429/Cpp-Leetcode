/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

Follow up:
Could you do better than O(n2) per move() operation?

Hint:

Could you trade extra space such that move() operation can be done in O(1)?
You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
*/
/*
O(n^2), board[][], 0:empty 1:playerA 2:playerB, check each row/col/diag/negdiag
*/
class TicTacToe {
private:
	vector<int> rows;
	vector<int> cols;
	int diags;
	int antidiags;
	int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n){
    	size = n;
    	rows.resize(n, 0);
    	cols.resize(n, 0);
    	diags = 0;
    	antidiags = 0;
    }
    int move(int row, int col, int player){
    	int playerAdd = player == 1? 1: -1;
    	rows[row] += playerAdd;
    	cols[col] += playerAdd;
    	if(row == col)
    		diags += playerAdd;
    	if(row + col == size - 1)
    		antidiags += playerAdd;
    	return abs(diags) == size || abs(antidiags) == size || abs(rows[row]) == size || abs(cols[col]) == size ? player : 0;
    }
};