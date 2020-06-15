#include <vector>

using namespace std;

vector<vector<int>> interval_intersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;

    int i = 0;
    int j = 0;

    while (i < A.size() && j < B.size()) {
        int low = max(A[i][0], B[j][0]);
        int high = min(A[i][1], B[j][1]);

        if (low <= high) {
            vector<int> temp = {low, high};
            res.push_back(temp);
        }

        if (A[i][1] < B[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    
    return res;
}
