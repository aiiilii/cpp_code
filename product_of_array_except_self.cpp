#include <vector>

using namespace std;

vector<int> product_except_self(vector<int>& nums) {
    int length = nums.size();
    vector<int> res(length);

    if(length == 0) {
        return res;
    }

    res[0] = 1;
    for (int i = 1; i < length; i++) {
        res[i] = res[i- 1] * nums[i - 1];
    }

    int r = 1;
    for (int j = length - 1; j >= 0; j--) {
        res[j] = res[j] * r;
        r = r * nums[j];
    }

    return res;
}