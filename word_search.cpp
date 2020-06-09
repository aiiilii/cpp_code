#include <vector>
#include <string>

using namespace std;

class WordSearch {

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word.size() == 0) {
            return false;
        }

        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (backtracking(board, rows, cols, r, c, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtracking(vector<vector<char>>& board, int rows, int cols, int r, int c, string& word, int index) {
        if (index >= word.size()) {
            return true;
        }

        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) {
            return false;
        }

        board[r][c] = '#';

        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            if (backtracking(board, rows, cols, r + dx[k], c + dy[k], word, index + 1)) {
                return true;
            }
        }
        board[r][c] = word[index];
        return false;
    }
};
