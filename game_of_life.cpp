#include <vector>

using namespace std;

void game_of_life(vector<vector<int>>& board) {
    vector<int> neighbors = {0, -1, 1};

    int rows = board.size();
    int cols = board[0].size();

    vector<vector<int>> copyboard(rows);
    for (int i = 0; i < rows; i++) { // initialize copyboard to be the same size as board;
        copyboard[i].resize(cols);
    }
    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < cols; col ++) {
            copyboard[row][col] = board[row][col];
        }
    }

    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < cols; col ++) {
            int liveNeighbors = 0;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                        int r = row + neighbors[i];
                        int c = col + neighbors[j];

                        if ((r < rows && r >= 0) && (c < cols && c >= 0) && copyboard[r][c] == 1) {
                            liveNeighbors ++;
                        }
                    }
                }
            }

            if (copyboard[row][col] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                board[row][col] = 0;
            }

            if (copyboard[row][col] == 0 && liveNeighbors == 3) {
                board[row][col] = 1;
            }
        }
    }
}