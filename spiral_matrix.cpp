#include <vector>

using namespace std;

vector<int> spiral_order(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return res;
    }

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    while (left < right && top < bottom) {
        for (int i = left; i < right; i++) {
            res.push_back(matrix[top][i]);
        }
        for (int i = top; i < bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        for (int i = right; i > left; i--) {
            res.push_back(matrix[bottom][i]);
        }
        for (int i = bottom; i > top; i--) {
            res.push_back(matrix[i][left]);
        }

        left ++;
        right --;
        top ++;
        bottom --;
    }

    if (left == right) {
        for (int i = top; i <= bottom; i++) {
            res.push_back(matrix[i][left]);
        }
    } else if (top == bottom) {
        for (int i = left; i <= right; i++) {
            res.push_back(matrix[top][i]);
        }
    }

    return res;
}