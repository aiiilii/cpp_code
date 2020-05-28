#include <vector>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int count = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                count ++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

void dfs(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size() || grid[r][c] == '0' || grid[r][c] == '2') {
        return;
    }
    grid[r][c] = '2';

    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}