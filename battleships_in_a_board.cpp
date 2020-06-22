#include <vector>

using namespace std;

int count_battleships(vector<vector<char>>& board) {
    if (board.size() == 0 || board[0].size() == 0) {
        return 0;
    }
    int m = board.size();
    int n = board[0].size();
    int battleships = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'X') {
                if ((!i || board[i - 1][j] == '.') && (!j || board[i][j - 1] == '.')) { // only count the X's whose left and up neights are both '.';
                    battleships ++;
                }
            }
        }
    }

    return battleships;
}
