#include <vector>
#include <algorithm>

using namespace std;

class TicTacToe {
public:
    TicTacToe(int n) {
        rows.resize(n); // initiallize the sizes to n;
        cols.resize(n);
        diagonal = 0;
        antidiagonal = 0;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int toAdd = 0;
        if (player == 1) {
            toAdd = 1;
        } else {
            toAdd = -1;
        }

        rows[row] += toAdd;
        cols[col] += toAdd;

        if (row == col) {
            diagonal += toAdd;
        }

        if (col == cols.size() - row - 1) {
            antidiagonal += toAdd;
        }

        int size = rows.size();

        // order to win, do only need to track the rows and cols instead of the entire n^2 board;
        if (abs(rows[row]) == size ||
            abs(cols[col]) == size ||
            abs(diagonal) == size ||
            abs(antidiagonal) == size) {
            return player;
        }
        return 0;
    }

private:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antidiagonal;
};
