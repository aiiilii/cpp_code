#include <vector>

using namespace std;

int min_path_sum(vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> sums(rows, vector<int>(cols));
    sums[0][0] = grid[0][0];

    for (int i = 1; i < rows; i++) { // going down on the left first column;
        sums[i][0] = sums[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < cols; j++) {
        sums[0][j] = sums[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            sums[i][j] = min(sums[i - 1][j], sums[i][j - 1]) + grid[i][j]; // sums[i - 1][j] is coming down from top, sums[i][j - 1] is coming right from left; use which ever is smaller;
        }
    }

    return sums[rows - 1][cols - 1];
}
