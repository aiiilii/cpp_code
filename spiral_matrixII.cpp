#include <vector>

using namespace std;

vector<vector<int>> generate_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n)); // initialization

    if (n == 0) {
        return matrix;
    }

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int k = 1;

    while (left < right && top < bottom) {
        for (int i = left; i < right; i++) {
            matrix[top][i] = k++;
        }
        for (int i = top; i < bottom; i++) {
            matrix[i][right] = k++;
        }
        for (int i = right; i > left; i--) {
            matrix[bottom][i] = k++;
        }
        for (int i = bottom; i > top; i--) {
            matrix[i][left] = k++;
        }

        left ++;
        right --;
        top ++;
        bottom --;
    }

    if (n % 2 != 0) {
        matrix[n / 2][n / 2] = k;
    }

    return matrix;
}