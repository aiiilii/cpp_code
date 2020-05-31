#include <vector>
#include <limits>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) {
        return 0;
    }

    int maxProfit = 0;
    int minPrice = numeric_limits<int>::max();

    for (int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}