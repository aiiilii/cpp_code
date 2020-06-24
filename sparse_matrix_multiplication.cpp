#include <vector>
#include <unordered_map>

using namespace std;

// Time - O(m * n)
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    if (!A.size() || !B.size() || !B[0].size()) {
        return vector<vector<int>>(0);
    }

    vector<vector<int>> res(A.size(), vector<int>(B.size(), 0));

    int am = A.size();
    int an = A[0].size();
    int bm = B.size();
    int bn = B[0].size();

    unordered_map<int, unordered_map<int, int>> um;

    for (int j = 0; j < bn; j++) {
        for (int i = 0; i < bm; i++) {
            if (B[i][j]) {
                um[j][i] = B[i][j];
            }
        }
    }

    for (int i = 0; i < am; i++) {
        for (int j = 0; j < an; j++) {
            for (pair<int, int> p : um[j]) { //sparse = O(1)
                if (A[i][p.first]) {
                    res[i][j] += p.second * A[i][p.first];
                }
            }
        }
    }

    return res;
}