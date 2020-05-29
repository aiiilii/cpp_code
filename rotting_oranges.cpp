#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};

int oranges_rotting(vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }

    int m = grid.size();
    int n = grid[0].size();

    deque<int> q;
    unordered_map<int, int> um;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                int code = i * n + j;
                q.push_back(code);
                um[code] = 0;
            }
        }
    }

    int days = 0;

    while (!q.empty()) {
        int code = q.front();
        q.pop_front();
        int r = code / n;
        int c = code % n;

        for (int k = 0; k < 4; k++) {
            if (r + dx[k] >= 0 && r + dx[k] < m && c + dy[k] >= 0 && c + dy[k] < n && grid[r + dx[k]][c + dy[k]] == 1) {
                grid[r + dx[k]][c + dy[k]] = 2;
                int newCode = (r + dx[k]) *  n + (c + dy[k]);
                q.push_back(newCode);
                um[newCode] = um[code] + 1;
                days = max(days, um[newCode]);
            }
        }
    }

    for (int i  = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return days;
}