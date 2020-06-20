#include <vector>

using namespace std;

int climb_stairs(int n) {
    if (n == 1) {
        return 1;
    }

    vector<int> ways(n + 1); // initiallize n + 1 in size to include 0th index;
    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
}